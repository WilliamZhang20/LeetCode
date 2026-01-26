class Excel {
    struct Range { int r1, c1, r2, c2; };
    struct Formula { vector<Range> ranges; };
    using CellSource = variant<int, Formula>;

    struct Cell {
        int val = 0;
        CellSource source = 0;
    };

    int H, W;
    vector<vector<Cell>> sheet;
    map<pair<int, int>, set<pair<int, int>>> deps;
    map<pair<int, int>, set<pair<int, int>>> observ;

    std::pair<int, int> getIndices(int r, char c) { return {r - 1, c - 'A'}; }

    Range parseRange(const string& s) {
        auto colon = s.find(':');
        if (colon == string::npos) {
            auto p = parseSingle(s);
            return {p.first, p.second, p.first, p.second};
        }
        auto p1 = parseSingle(s.substr(0, colon));
        auto p2 = parseSingle(s.substr(colon+1));
        return {p1.first, p1.second, p2.first, p2.second};
    }    

    std::pair<int, int> parseSingle(const std::string& s) {
        return {std::stoi(s.substr(1)) - 1, s[0] - 'A'};
    }

    int executeSum(const Formula& f) {
        int total = 0;
        for (const auto& r : f.ranges) {
            auto rows = views::iota(r.r1, r.r2+1);
            auto cols = views::iota(r.c1, r.c2+1);
            for(int i: rows) {
                auto row_view = cols | std::views::transform([&](int j) {
                    return sheet[i][j].val;
                });
                for(int val : row_view) {
                    total += val;
                }
            }
        }
        return total;
    }

    void propagate(std::pair<int, int> start) {
        std::map<std::pair<int, int>, int> in_degree;
        std::vector<std::pair<int, int>> queue;
        
        std::vector<std::pair<int, int>> todo = {start};
        size_t head = 0;
        while(head < todo.size()){
            auto curr = todo[head++];
            for(auto next : deps[curr]){
                if(in_degree[next]++ == 0) todo.push_back(next);
            }
        }

        std::vector<std::pair<int, int>> sources = {start};
        while(!sources.empty()){
            auto curr = sources.back();
            sources.pop_back();

            for(auto next : deps[curr]){
                in_degree[next]--;
                if(in_degree[next] == 0) {
                    auto& cell = sheet[next.first][next.second];
                    cell.val = executeSum(std::get<Formula>(cell.source));
                    sources.push_back(next);
                }
            }
        }
    }

    void clearLinks(std::pair<int, int> pos) {
        for (auto source : observ[pos]) {
            deps[source].erase(pos);
        }
        observ[pos].clear();
    }
public:
    Excel(int height, char width) : H(height), W(width - 'A' + 1) {
        sheet.resize(H, std::vector<Cell>(W));
    }
    
    void set(int row, char column, int val) {
        auto pos = getIndices(row, column);
        clearLinks(pos); // Stop listening to old sources
        sheet[pos.first][pos.second].source = val;
        sheet[pos.first][pos.second].val = val;
        propagate(pos);
    }
    
    int get(int row, char column) {
        auto [r, c] = getIndices(row, column);
        return sheet[r][c].val;
    }
    
    int sum(int row, char column, vector<string> numbers) {
        auto pos = getIndices(row, column);
        clearLinks(pos);

        Formula f;
        for(const string& s: numbers) {
            auto r = parseRange(s);
            f.ranges.push_back(r);
            for(int i=r.r1; i<=r.r2; i++) {
                for(int j=r.c1; j<=r.c2; j++) {
                    deps[{i, j}].insert(pos);
                    observ[pos].insert({i, j});
                }
            }
        }
        sheet[pos.first][pos.second].source = f;
        sheet[pos.first][pos.second].val = executeSum(f);
        propagate(pos);
        return sheet[pos.first][pos.second].val;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
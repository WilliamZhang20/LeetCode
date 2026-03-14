class SQL {
    unordered_map<string, int> ids; // auto incr
    unordered_map<string, int> numCols;
    unordered_map<string, map<int, vector<string>>> data;

public:
    SQL(vector<string>& names, vector<int>& columns) {
        int n = names.size();
        for(int i = 0; i < n; i++) {
            numCols[names[i]] = columns[i];
        }
    }
    
    bool ins(string name, vector<string> row) {
        if(!numCols.count(name)) return false;
        if(row.size() != numCols[name]) return false;

        data[name][++ids[name]] = row; // 1-indexed rowId
        return true;
    }
    
    void rmv(string name, int rowId) {
        if(!numCols.count(name)) return;
        data[name].erase(rowId);
    }
    
    string sel(string name, int rowId, int columnId) {
        if(!numCols.count(name)) return "<null>";
        if(!data[name].count(rowId)) return "<null>";

        auto &row = data[name][rowId];

        if(columnId < 1 || columnId > row.size()) return "<null>";

        return row[columnId - 1];
    }
    
   vector<string> exp(string name) {
    vector<string> res;

    if(!numCols.count(name)) return res;

    for(auto &[rowId, row] : data[name]) {
        string s = to_string(rowId);

        for(auto &v : row) {
            s += "," + v;
        }

        res.push_back(s);
    }

    return res;
}
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */
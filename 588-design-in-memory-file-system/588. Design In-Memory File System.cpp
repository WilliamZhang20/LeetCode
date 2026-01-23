class FileSystem {
public:
    class Node {
    public:
        bool isFile;
        map<string, unique_ptr<Node>> children; // sorts children by default
        string content = ""; // empty for dirs
        Node(bool file = false) : isFile(file) {}
    };

    Node root;
    
    FileSystem() : root(false) {}
    
    vector<string> ls(const string& path) {
        const vector<string_view> parts = split(path);
        Node* result = traverse(parts, false);
        if(!result) return {};
        if(result->isFile) return { string(parts.back()) };
        vector<string> res;
        res.reserve(result->children.size());
        for(const auto& kv : result->children) {
            res.push_back(kv.first);
        }
        return res;
    }
    
    void mkdir(const string& path) {
        const vector<string_view> parts = split(path);
        traverse(parts, true);
    }
    
    void addContentToFile(const string& filePath, const string& content) {
        const vector<string_view> parts = split(filePath);
        Node* result = traverse(parts, true);
        result->isFile = true;
        result->content.append(content);
    }
    
    string readContentFromFile(const string& filePath) {
        const vector<string_view> parts = split(filePath);
        Node* result = traverse(parts, false);
        return result ? result->content : "";
    }
private:
    Node* traverse(const vector<string_view>& parts, bool createMissing) {
        Node* curr = &root;
        for(const auto& part : parts) {
            string key(part); // convert string_view -> string for map
            auto it = curr->children.find(key);
            if(it != curr->children.end()) {
                curr = it->second.get();
            } else if(createMissing) {
                curr->children[key] = make_unique<Node>(false);
                curr = curr->children[key].get();
            } else if(curr->isFile) {
                return curr;
            } else {
                return nullptr;
            }
        }
        return curr;
    }

    vector<string_view> split(const string& path) {
        vector<string_view> parts;
        auto it = path.begin();
        while (it != path.end()) {
            while (it != path.end() && *it == '/') ++it;
            if (it == path.end()) break;
            auto start = it;
            while (it != path.end() && *it != '/') ++it;
            parts.emplace_back(&(*start), it - start);
        }
        return parts;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
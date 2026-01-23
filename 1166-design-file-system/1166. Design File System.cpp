class FileSystem {
public:
    unordered_map<string, int> paths;
    FileSystem() {}
    
    bool createPath(string path, int value) {
        if (path.empty() || path == "/" || paths.count(path)) return false;

        int found = path.rfind("/");
        string parent = path.substr(0, found);

        // if parent is not root and doesn't exist
        if (!parent.empty() && !paths.count(parent)) return false;

        paths[path] = value;
        return true;
    }
    
    int get(string path) {
        if(!paths.count(path)) return -1;
        return paths[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
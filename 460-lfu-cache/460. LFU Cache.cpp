struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v, int f) : key(k), val(v), freq(f), prev(nullptr), next(nullptr) {}
};

struct List {
    Node *head, *tail;
    int size;
    List() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    
    bool isEmpty() { return size == 0; }
};

class LFUCache {
    int capacity, minFreq, count;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;

    void updateFreq(Node* node) {
        int f = node->freq;
        freqMap[f]->remove(node);
        if (f == minFreq && freqMap[f]->isEmpty()) {
            minFreq++;
        }
        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new List();
        }
        freqMap[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0), count(0) {
        keyMap.reserve(capacity); // Optimization: prevent rehashing
    }
    
    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;
        Node* node = keyMap[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        
        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->val = value;
            updateFreq(node);
            return;
        }
        
        if (count == capacity) {
            List* minList = freqMap[minFreq];
            Node* toRemove = minList->tail->prev;
            keyMap.erase(toRemove->key);
            minList->remove(toRemove);
            delete toRemove;
            count--;
        }
        
        Node* newNode = new Node(key, value, 1);
        keyMap[key] = newNode;
        if (freqMap.find(1) == freqMap.end()) {
            freqMap[1] = new List();
        }
        freqMap[1]->addFront(newNode);
        minFreq = 1;
        count++;
    }
};
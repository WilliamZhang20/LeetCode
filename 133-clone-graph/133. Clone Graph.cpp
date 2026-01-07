/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> track;
public:
    Node* searchGraph(Node* node) {
        Node* ret = new Node(node->val);
        track[node] = ret;
        for(int i=0; i<node->neighbors.size(); i++) {
            if(!track[node->neighbors[i]]) {
                ret->neighbors.push_back(searchGraph(node->neighbors[i]));
            } else {
                ret->neighbors.push_back(track[node->neighbors[i]]);
            }
        }
        return ret;
    }
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        return searchGraph(node);
    }
};
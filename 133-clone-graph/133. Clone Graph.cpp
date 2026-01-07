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
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> track;
        queue<Node*> q;
        q.push(node);
        track[node] = new Node(node->val);
        
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            Node* clone = track[n];
            for (Node* neighbor : n->neighbors) {
                if (!track.count(neighbor)) {
                    track[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                clone->neighbors.push_back(track[neighbor]);
            }
        }
        return track[node];
    }
};
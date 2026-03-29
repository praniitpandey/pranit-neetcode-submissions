class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        return clone(node, visited);        
    }

    Node* clone(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        Node* newNode = new Node(node->val);
        visited[node] = newNode;

        for (Node* neighbor : node->neighbors) {
            Node* newNeighbor = clone(neighbor, visited);
            if (newNeighbor) {
                newNode->neighbors.push_back(newNeighbor);
            }
        }

        return newNode;
    }
};
class Node {
public:
    Node* left;
    Node* right;
    int key;
    int value;

    Node(int key, int value, Node* left = nullptr, Node* right = nullptr) {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class TreeMap {
private:
    Node* root;

    Node* insert(int key, int value, Node* root) {
        if (!root) {
            return new Node(key, value);
        }
        else if (key > root->key) {
            root->right = insert(key, value, root->right);
        }
        else if (key < root->key) {
            root->left = insert(key, value, root->left);
        }
        else if (key == root->key) {
            root->value = value;
        }
        return root;
    }

    int get(int key, Node* root) {
        if (!root) {
            return -1;
        }

        if (key > root->key) {
            return get(key, root->right);
        }
        else if (key < root->key) {
            return get(key, root->left);
        }
        else {
            return root->value;
        }
    }

    int getMin(Node* root) {
        if (!root) {
            return -1;
        }

        while (root->left) {
            root = root->left;
        }

        return root->value;
    }

    int getMax(Node* root) {
        if (!root) {
            return -1;
        }

        while (root->right) {
            root = root->right;
        }

        return root->value;
    }

    Node* remove(int key, Node* root) {
        if (!root) {
            return nullptr;
        }

        if (key > root->key) {
            root->right = remove(key, root->right);
        }
        
        else if (key < root->key) {
            root->left = remove(key, root->left);
        }
        
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            
            else if (root->left && !root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            else if (!root->left && root->right) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            
            else {
                Node* minNode = root->right;
                while (minNode && minNode->left)
                {
                    minNode = minNode->left;
                }
                
                root->key = minNode->key;
                root->value = minNode->value;
                root->right = remove(minNode->key, root->right);
            }
            
        }
        
        return root;
    }

    void traverse(vector<int>& ans, Node* root) {
        if (!root) {
            return;
        }

        traverse(ans, root->left);
        ans.push_back(root->key);
        traverse(ans, root->right);
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        this->root = insert(key, val, this->root);
    }

    int get(int key) {
        return get(key, this->root);
    }

    int getMin() {
        return getMin(this->root);
    }

    int getMax() {
        return getMax(this->root);
    }

    void remove(int key) {
        this->root = remove(key, this->root);
    }

    std::vector<int> getInorderKeys() {
        vector<int> ans;
        traverse(ans, this->root);
        return ans;
    }
};

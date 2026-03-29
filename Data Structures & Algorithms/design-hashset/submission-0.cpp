class MyHashSet {
    struct Node {
        int val;
        Node *next;
        Node() : val(0), next(nullptr) {}
        Node(int x) : val(x), next(nullptr) {}
        Node(int x, Node *next) : val(x), next(next) {}
    };
    vector<Node*> hash;
    int n;
public:
    MyHashSet() {
        n = 10;
        hash = vector<Node*>(n, nullptr);
    }
    
    void add(int key) {
        if (contains(key)) return;
        int index = key % n;
        Node* newNode = new Node(key);

        if (!hash[index] || hash[index]->val >= key) {
            newNode->next = hash[index];
            hash[index] = newNode;
        }
        else {
            Node* ptr = hash[index];

            while (ptr->next && ptr->next->val < key) {
                ptr = ptr->next;
            }

            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    
    void remove(int key) {
        int index = key % n;

        if (!hash[index] || hash[index]->val > key) {
            return;
        }
        else if (hash[index]->val == key) {
            Node* oldNode = hash[index];
            hash[index] = hash[index]->next;
            delete oldNode;
        }
        else {
            Node* ptr = hash[index];

            while (ptr->next && ptr->next->val < key) {
                ptr = ptr->next;
            }

            if (ptr && ptr->next && ptr->next->val == key) {
                Node* oldNode = ptr->next;
                ptr->next = oldNode->next;
                delete oldNode;
            }
        }        
    }
    
    bool contains(int key) {
        int index = key % n;

        if (hash[index]) {
            Node* ptr = hash[index];

            while (ptr && ptr->val <= key) {
                if (ptr->val == key) {
                    return true;
                }
                ptr = ptr->next;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
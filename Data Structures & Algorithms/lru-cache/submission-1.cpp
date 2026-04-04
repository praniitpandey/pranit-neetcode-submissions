class Node {
public:
    Node* prev;
    Node* next;
    int key;
    int value;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
    int size;

    void remove(Node* node) {
        Node* _next = node->next;
        Node* _prev = node->prev;

        _prev->next = _next;
        _next->prev = _prev;
    }

    void insert(Node* node) {
        Node* _first = head->next;
        head->next = node;
        node->next = _first;
        _first->prev = node;
        node->prev = head;
    }

public:
    LRUCache(int capacity) {
        this->size = capacity;

        this->head = new Node(0, 0);
        this->tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        else {
            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->value;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);

            node->value = value;
            return;
        }

        if (cache.size() == this->size) {
            Node* lru = this->tail->prev;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }

        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;
    }
};
class Node {
public:
    Node* next;
    int value;
    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* ptr = head;

        for (int i = 0; i < index; i++) {
            if (!ptr) {
                return -1;
            }
            ptr = ptr->next;
        }

        return ptr ? ptr->value : -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = this->head;
        this->head = newHead;
    }
    
    void insertTail(int val) {
        if (!this->head) {
            insertHead(val);
            return;
        }

        Node* ptr = head;
        while (ptr->next) {
            ptr = ptr->next;
        }

        Node* newTail = new Node(val);
        ptr->next = newTail;
    }

    bool remove(int index) {
        if (!this->head) {
            return false;
        }

        if (index == 0) {
            Node* oldHead = this->head;
            this->head = head->next;
            delete oldHead;
            return true;
        }

        Node* ptr = head;
        for (int i = 0; i < index - 1; i++) {
            if (!ptr || !ptr->next) {
                return false;
            }
            ptr = ptr->next;
        }
        
        if (!ptr || !ptr->next) return false;
        Node* oldNode = ptr->next;
        ptr->next = ptr->next->next;
        delete oldNode;

        return true;
    }

    vector<int> getValues() {
        Node* ptr = head;
        vector<int> values;

        while (ptr) {
            values.push_back(ptr->value);
            ptr = ptr->next;
        }

        return values;
    }
};

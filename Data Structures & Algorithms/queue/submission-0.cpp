class Node {
public:
    Node* prev;
    Node* next;
    int value;

    Node(int value) {
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class Deque {
public:
    Node* head;
    Node* tail;
    int size;
    Deque() {
        this->size = 0;
        this->head = new Node(-1e9);
        this->tail = new Node(1e9);
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    void append(int value) {
        ++this->size;

        Node* newLast = new Node(value);
        Node* oldLast = tail->prev;

        oldLast->next = newLast;
        newLast->next = tail;
        tail->prev = newLast;
        newLast->prev = oldLast;
    }

    void appendleft(int value) {
        ++this->size;

        Node* newFirst = new Node(value);
        Node* oldFirst = head->next;

        head->next = newFirst;
        newFirst->next = oldFirst;
        oldFirst->prev = newFirst;
        newFirst->prev = head;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        --this->size;
        
        Node* oldLast = tail->prev;
        Node* newLast = tail->prev->prev;

        newLast->next = tail;
        tail->prev = newLast;

        int oldLastValue = oldLast->value;
        delete oldLast;

        return oldLastValue;
    }

    int popleft() {
        if (size == 0) {
            return -1;
        }
        --this->size;

        Node* oldFirst = head->next;
        Node* newFirst = head->next->next;

        head->next = newFirst;
        newFirst->prev = head;

        int oldFirstValue = oldFirst->value;
        delete oldFirst;

        return oldFirstValue;
    }
};
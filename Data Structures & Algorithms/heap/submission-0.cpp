class MinHeap {
private:
    vector<int> heap;

    int leftChildOf(int index) {
        return (((index + 1) * 2) - 1);
    }
    int rightChildOf(int index) {
        return ((index + 1) * 2);
    }
    int parentOf(int index) {
        return ((index - 1) / 2);
    }
    void bubbleDown(int index) {
        int size = heap.size();
        
        while (true) {
            int left = leftChildOf(index);
            int right = rightChildOf(index);
            int smallest = index;
            
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if (smallest == index) {
                break;
            }
            
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

    void bubbleUp(int index) {
        while (index > 0) {
            int parent = parentOf(index);
            if (heap[parent] <= heap[index]) {
                break;
            }
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }
public:
    MinHeap() {}

    void push(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }

    int pop() {
        if (heap.empty()) {
            return -1;
        }
        if (heap.size() == 1) {
            int minVal = heap.back();
            heap.pop_back();
            return minVal;
        }

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
        
        return minVal;
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    void heapify(const vector<int>& nums) {
        heap.clear();
        heap = nums;
        
        int n = heap.size();
        for (int i = n/2 - 1; i >= 0; i--) {
            bubbleDown(i);
        }
    }
};

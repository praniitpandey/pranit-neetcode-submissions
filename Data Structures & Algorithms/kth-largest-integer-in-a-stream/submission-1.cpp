class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> topHeap;   //min heap to store top k elements
    priority_queue<int> bottomHeap; //max heap to store bottom (size - k) elements
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (topHeap.size() < k) {
            topHeap.push(val);
        }
        else if (val <= topHeap.top()) {
            bottomHeap.push(val);
        } //if new value <= current kth largest element, it does not affect the k largest elements
        else {
            bottomHeap.push(topHeap.top());
            topHeap.pop();
            //previous Kth largest element gets relegated to the bottom heap
            topHeap.push(val);
            //new value is promoted to top k elements
        }

        return (topHeap.size() < k ? 666 : topHeap.top());
    }
};

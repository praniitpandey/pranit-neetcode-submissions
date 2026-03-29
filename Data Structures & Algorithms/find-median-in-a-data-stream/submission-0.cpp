class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; //minHeap of top half elements
    priority_queue<int> maxHeap;                            //maxHeap of bottom half elements
    
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return (maxHeap.top() + minHeap.top())/2.0;
        }
    }
};
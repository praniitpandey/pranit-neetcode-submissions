class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; //minHeap of top half elements
    priority_queue<int> maxHeap;                            //maxHeap of bottom half elements
    
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        double median = findMedian();

        if (maxHeap.size() == minHeap.size()) {
            if (num > median) {
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else {
                maxHeap.push(num);
            }
        }
        else if (maxHeap.size() > minHeap.size()) {
            if (num > median) {
                minHeap.push(num);
            }
            else {
                maxHeap.push(num);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
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
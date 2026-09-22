class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            maxHeap.push((int)sqrt(maxHeap.top()));
            maxHeap.pop();
        }

        long long sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};
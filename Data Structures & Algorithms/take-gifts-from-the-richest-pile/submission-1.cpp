class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for (int gift : gifts) {
            maxHeap.push(gift);
        }

        for (int i = 0; i < k; i++) {
            int maxGift = maxHeap.top();
            maxHeap.pop();

            maxHeap.push((int)sqrt(maxGift));
        }

        long long sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};
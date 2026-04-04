class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;

        for (int pile : gifts) {
            maxHeap.push(pile);
        }

        for (int i = 0; i < k && !maxHeap.empty(); i++) {
            int maxPile = maxHeap.top();
            maxHeap.pop();
            
            maxHeap.push((int)sqrt(maxPile));
        }

        long long sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        
        return sum;
    }
};
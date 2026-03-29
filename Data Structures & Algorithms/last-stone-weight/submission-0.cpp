class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int weight : stones) {
            maxHeap.push(weight);
        }

        while (maxHeap.size() > 1) {
            int heaviest1 = maxHeap.top();
            maxHeap.pop();

            int heaviest2 = maxHeap.top();
            maxHeap.pop();

            if (heaviest1 > heaviest2) {
                maxHeap.push(heaviest1 - heaviest2);
            }
        }

        return (maxHeap.empty() ? 0 : maxHeap.top());        
    }
};

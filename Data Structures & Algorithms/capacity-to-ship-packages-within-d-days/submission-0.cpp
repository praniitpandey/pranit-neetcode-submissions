class Solution {
public:
    int shipWithinDays(vector<int>& weights, int maxDays) {
        long long minCapacity = 0, maxCapacity = 0, midCapacity = 0;
        for (int weight : weights) {
            minCapacity = max((long long)weight, minCapacity);
            maxCapacity += weight;
        }

        while (minCapacity <= maxCapacity) {
            midCapacity = minCapacity + (maxCapacity - minCapacity)/2;
            int midDays = daysNeeded(weights, midCapacity);

            if (midDays > maxDays) {
                minCapacity = midCapacity + 1;
            }
            else {
                maxCapacity = midCapacity - 1;
            }
        }

        return minCapacity;
    }

    long long daysNeeded(vector<int>& weights, long long capacity) {
        long long days = 1;
        long long loaded = 0;

        for (int weight : weights) {
            if ((loaded + weight) > capacity) {
                ++days;
                loaded = weight;
            }
            else {
                loaded += weight;
            }
        }

        return days;
    }
};
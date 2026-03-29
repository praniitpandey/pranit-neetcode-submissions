class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1, maxSpeed = 1, midSpeed = 0, midTime;
        for (int pile : piles) {
            maxSpeed = max(pile, maxSpeed);
        }

        while (minSpeed <= maxSpeed) {
            midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            midTime = eatingTime(piles, midSpeed);

            if (midTime > h) {
                minSpeed = midSpeed + 1;

            }
            else {
                maxSpeed = midSpeed - 1;
            }
        }

        return minSpeed;
    }

    long long eatingTime(vector<int>& piles, int k) {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours += (long long)(piles[i] + k - 1) / k;
        }

        return totalHours;
    }
};
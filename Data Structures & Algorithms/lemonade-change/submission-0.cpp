class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;
        int change;
        int fivesSpent, tensSpent, twentiesSpent;

        for (int i = 0; i < bills.size(); i++) {
            switch (bills[i]) {
                case 5: ++fives;
                break;
                case 10: ++tens;
                break;
                case 20: ++twenties;
                break;
            }

            change = bills[i] - 5;
            twentiesSpent = min(change/20, twenties);
            twenties -= twentiesSpent;
            change -= (twentiesSpent * 20);

            tensSpent = min(change/10, tens);
            tens -= tensSpent;
            change -= (tensSpent * 10);

            fivesSpent = min(change/5, fives);
            fives -= fivesSpent;
            change -= (fivesSpent * 5);

            if (change > 0) {
                return false;
            }
        }

        return true;        
    }
};
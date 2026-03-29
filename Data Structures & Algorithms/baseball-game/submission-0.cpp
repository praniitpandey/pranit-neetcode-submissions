class Solution {
public:
    int calPoints(vector<string>& operations) {

        vector<int> scores;
        for (string s : operations) {

            if (s == "+") {
                int op1 = scores[scores.size() - 1];
                int op2 = scores[scores.size() - 2];

                scores.push_back(op1 + op2);
            }
            else if (s == "C") {
                scores.pop_back();
            }
            else if (s == "D") {
                scores.push_back(scores[scores.size() - 1] * 2);
            }
            else {
                scores.push_back(stoi(s));
            }
        }

        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        
        return sum;
    }
};
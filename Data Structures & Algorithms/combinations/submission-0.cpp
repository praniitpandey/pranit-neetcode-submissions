class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        backtrack(1, n, k, vector<int>{}, combinations);

        return combinations;
    }

    void backtrack(int i, const int n, int k, vector<int> combination, vector<vector<int>>& combinations) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }

        if (i > n) {
            return;
        }

        backtrack(i + 1, n, k, combination, combinations);
        combination.push_back(i);
        backtrack(i + 1, n, k, combination, combinations);
    }
};
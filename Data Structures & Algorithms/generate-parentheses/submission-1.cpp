class Solution {
public:
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");

        return paths;
    }

private:
    vector<string> paths;

    void solve(const int n, int open, int close, string path) {
        if (path.size() == n << 1) {
            paths.push_back(path);
            return;
        }

        if (open > close) {
            path.push_back(')');
            solve(n, open, close + 1, path);
            path.pop_back();
        }

        if (open < n) {
            path.push_back('(');
            solve(n, open + 1, close, path);
            path.pop_back();
        }
    }
};

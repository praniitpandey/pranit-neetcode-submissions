class Solution {
public:
    vector<string> generateParenthesis(int n) {
        solve(n, 0, "");

        return paths;
    }

private:
    vector<string> paths;

    void solve(int n, int depth, string path) {
        if (depth > n) {
            return;
        }
        
        if (n == 0) {
            paths.push_back(path);
            return;
        }

        if (depth > 0) {
            path.push_back(')');
            solve(n - 1, depth - 1, path);
            path.pop_back();
        }

        path.push_back('(');
        solve(n, depth + 1, path);
        path.pop_back();
    }
};

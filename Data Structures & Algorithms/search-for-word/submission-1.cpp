class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if (word[0] == board[i][j]) {
                    if (search(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool search(const vector<vector<char>>& board, const string& word, int i, int j, int k, vector<vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        int w = word.size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || word[k] != board[i][j]) {
            return false;
        }
        if (k == w - 1) {
            return true;
        }

        visited[i][j] = true;
        bool up = search(board, word, i - 1, j, k + 1, visited);
        bool down = search(board, word, i + 1, j, k + 1, visited);
        bool left = search(board, word, i, j - 1, k + 1, visited);
        bool right = search(board, word, i, j + 1, k + 1, visited);

        visited[i][j] = false;
        return up || down || left || right;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if (search(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool search(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        int m = board.size();
        int n = board[0].size();
        int w = word.size();

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '!' || word[k] != board[i][j]) {
            return false;
        }
        if (k == w - 1) {
            return true;
        }

        board[i][j] = '!';
        bool up = search(board, word, i - 1, j, k + 1);
        bool down = search(board, word, i + 1, j, k + 1);
        bool left = search(board, word, i, j - 1, k + 1);
        bool right = search(board, word, i, j + 1, k + 1);

        board[i][j] = word[k];
        return up || down || left || right;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {

            vector<int> count(10, 0);
            for (int j = 0; j < 9; j++) {

                char c = board[i][j];
                if (c != '.') {
                    ++count[c - '0'];
                    if (count[c - '0'] > 1) {
                        return false;
                    }
                }

            }
        }


        for (int i = 0; i < 9; i++) {

            vector<int> count(10, 0);
            for (int j = 0; j < 9; j++) {
                
                char c = board[j][i];
                if (c != '.') {
                    ++count[c - '0'];
                    if (count[c - '0'] > 1) {
                        cout << "columns\n";
                        return false;
                    }
                }

            }
        }


        for (int a = 0; a < 9; a+=3) {

            for (int b = 0; b < 9; b+=3) {

                vector<int> count(10, 0);
                for (int i = a; i < (a + 3); i++) {

                    for (int j = b; j < (b + 3); j++) {

                        char c = board[i][j];
                        if (c != '.') {
                            ++count[c - '0'];
                            if (count[c - '0'] > 1) {
                                cout << "squares\n";
                                return false;
                            }
                        }

                        // cout << "[" << i << "][" << j << "] ";
                    }
                    // cout << "\n";
                }
                // cout << "\n";
            }
        }

        return true;
    }
};

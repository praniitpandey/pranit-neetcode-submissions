class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // = matrix[i].size()
        int swap;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        } cout << endl;

        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                swap = matrix[i][j];
                matrix[i][j] = matrix[n-i-1][j];
                matrix[n-i-1][j] = swap;
            }
        }   //reversing matrix[][] vertically

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        } cout <<endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = swap;
                cout << "[" << i << "][" << j << "]" << " ";
            } cout << endl;
        }   //transposing matrix[][]

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        } cout <<endl;
    }
};

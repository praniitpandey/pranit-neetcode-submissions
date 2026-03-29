class Solution {
public:
    int compress(vector<char>& v) 
    {
        vector<char> ans;
        char curr = v[0];
        int count = 1;

        for (int i = 1; i < v.size(); i++) {
            if (v[i] == curr) {
                ++count;
            }
            else {
                ans.push_back(curr);
                if (count > 1) {
                    string countString = to_string(count);

                    for (char d : countString) {
                        ans.push_back(d);
                    }
                }

                curr = v[i];
                count = 1;
            }
        }

        ans.push_back(curr);
        if (count > 1) {
            string countString = to_string(count);

            for (char d : countString) {
                ans.push_back(d);
            }
        }
        
        v = ans;
        return ans.size();
    }
};
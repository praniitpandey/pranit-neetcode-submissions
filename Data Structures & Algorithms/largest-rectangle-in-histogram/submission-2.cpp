class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        vector<int> leftSmaller(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            leftSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        vector<int> rightSmaller(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            rightSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        int area = 0, maxArea = 0;
        for (int i = 0; i < n; i++) {
            area = (rightSmaller[i] - leftSmaller[i] - 1) * heights[i];
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

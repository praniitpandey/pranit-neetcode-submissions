class StockSpanner {
private:
    stack<pair<int, int>> st;
    int day;
public:
    StockSpanner() {
        day = 0;
    }
    
    int next(int price) {
        while (!st.empty() && st.top().first <= price)
            st.pop();
        int ans = st.empty() ? day + 1 : day - st.top().second;
        st.push(make_pair(price, day++));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
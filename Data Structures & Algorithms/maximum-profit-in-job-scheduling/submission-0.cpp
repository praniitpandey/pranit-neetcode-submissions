class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), cmp);
        vector<unordered_map<int, int>> cache(n);
        return dfs(jobs, 0, 0, cache);
    }

private:
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        else {
            return a[0] < b[0];
        }
    }

    long long dfs(const vector<vector<int>>& jobs, int index, long long currentEndTime, vector<unordered_map<int, int>>& cache) {
        if (index == jobs.size()) {
            return 0;
        }
        if (cache[index].count(currentEndTime)) {
            return cache[index][currentEndTime];
        }
        long long ifNotPicked = dfs(jobs, index + 1, currentEndTime, cache);
        long long ifPicked = 0;
        if (jobs[index][0] >= currentEndTime) {
            ifPicked = jobs[index][2] + dfs(jobs, index + 1, jobs[index][1], cache);
        }

        cache[index][currentEndTime] = max(ifNotPicked, ifPicked);
        return cache[index][currentEndTime];
    }
};
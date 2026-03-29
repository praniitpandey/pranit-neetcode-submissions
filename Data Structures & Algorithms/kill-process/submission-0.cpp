class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> children;

        for (int i = 0; i < pid.size(); i++) {
            if (children.find(ppid[i]) == children.end()) {
                children[ppid[i]] = vector<int>{};
            }
            children[ppid[i]].push_back(pid[i]);
        }

        vector<int> ans;
        dfs(children, kill, ans);

        return ans;
    }

    void dfs(unordered_map<int, vector<int>>& children, int parent, vector<int>& ans) {
        ans.push_back(parent);
        if (children.find(parent) != children.end()) {
            for (int child : children[parent]) {
                dfs(children, child, ans);
            }
        }

        return;
    }
};

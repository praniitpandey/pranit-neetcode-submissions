class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    int time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> maxHeap;
        unordered_set<int> subs = followees[userId];
        subs.insert(userId);

        for (int f : subs) {
            if (!tweets[f].empty()) {
                int lastIdx = tweets[f].size() - 1;
                maxHeap.push({tweets[f][lastIdx].first, tweets[f][lastIdx].second, f, lastIdx});
            }
        }

        vector<int> ans;
        while (ans.size() < 10 && !maxHeap.empty()) {
            auto [t, tweetId, user, index] = maxHeap.top();
            maxHeap.pop();
            ans.push_back(tweetId);

            if (index > 0) {
                int nextIdx = index - 1;
                maxHeap.push({tweets[user][nextIdx].first, tweets[user][nextIdx].second, user, nextIdx});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);        
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].erase(followeeId);
        }
    }
};
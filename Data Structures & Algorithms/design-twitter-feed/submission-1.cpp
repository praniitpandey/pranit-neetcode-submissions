class Twitter {
public:
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if (followees[userId].empty()) {
            followees[userId].insert(userId);
        }
        tweets[userId].push_back({tweetId, ++time});        
    }
    
    vector<int> getNewsFeed(int userId) {
        if (followees[userId].empty()) {
            followees[userId].insert(userId);
        }
        priority_queue<tuple<int, int, int, int>> maxHeap;

        for (auto followee : followees[userId]) {
            if (!tweets[followee].empty()) {
                int index = tweets[followee].size() - 1;
                auto [tweetId, time] = tweets[followee][index];
                maxHeap.push({time, tweetId, followee, index});
            }
        }

        vector<int> feed;

        while (feed.size() < 10 && !maxHeap.empty()) {
            auto [time, tweetId, followee, index] = maxHeap.top();
            maxHeap.pop();

            feed.push_back(tweetId);

            if (index > 0) {
                auto [tweetId2, time2] = tweets[followee][--index];
                maxHeap.push({time2, tweetId2, followee, index});
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followees[followerId].empty()) {
            followees[followerId].insert(followerId);
        }
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].erase(followeeId);
        }
    }
};
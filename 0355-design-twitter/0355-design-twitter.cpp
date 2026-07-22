class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        followMap[userId].insert(userId);

        for (auto& f : followMap[userId]) {
            auto& t = tweets[f];
            int n = t.size();
            for (int i = max(0, n - 10); i < n; i++) {
                pq.push(t[i]);
            }
        }
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
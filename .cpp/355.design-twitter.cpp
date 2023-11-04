/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
// 2023-11-03 submission
// 16/16 cases passed
// Runtime: 3 ms, faster than 41.42% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 22.32% of cpp online submissions.
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed
     * must be posted by users who the user followed or by the user herself. Tweets must be ordered
     * from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto &id : followees[userId]) {
            for (auto &tweet : tweets[id]) {
                pq.push(tweet);
            }
        }
        // Remember to add the user's own tweets
        for (auto &tweet : tweets[userId]) {
            pq.push(tweet);
        }
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        followees[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        followees[followerId].erase(followeeId);
    }

private:
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int, int>>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

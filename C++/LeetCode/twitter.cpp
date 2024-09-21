#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    set<int> userIds;
    map<int, set<int>> follows;

    // UserId -> (tweetId, time)
    map<int, map<int, int>> posts;
    int numPosts;

public:
    Twitter()
    {
        numPosts = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        if (posts.count(userId) == 0)
        {
            map<int, int> p;

            p.insert(pair<int, int>(numPosts++, tweetId));

            posts.insert(pair<int, map<int, int>>(userId, p));
        }
        else
        {
            posts[userId].insert(pair<int, int>(numPosts++, tweetId));
        }
    }

    vector<int> getNewsFeed(int userId)
    {
        set<int> followedUsers = follows[userId];

        // time -> tweet
        map<int, int> userPosts;

        userPosts.insert(posts[userId].begin(), posts[userId].end());

        for (auto followedUser : followedUsers)
        {
            userPosts.insert(posts[followedUser].begin(), posts[followedUser].end());
        }

        vector<int> ans;

        for (auto it = userPosts.rbegin(); it != userPosts.rend() && it != userPosts.rbegin() + 10; it++)
            ans.push_back(it->second);

        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        if (follows.count(followerId) == 0)
        {
            set<int> followedUsers;
            followedUsers.insert(followeeId);
            follows.insert(pair<int, set<int>>(followerId, followedUsers));
        }
        else
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
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

int main()
{

    return 0;
}
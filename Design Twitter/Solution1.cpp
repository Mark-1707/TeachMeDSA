// https://leetcode.com/problems/design-twitter/description/

#include<bits/stdc++.h>
using namespace std;

class Twitter {

private:
    unordered_map<int, unordered_set<int>> followers;
    vector<vector<pair<int, int>>> tweets;
    int counter = 0;

public:
    Twitter(): tweets(500) {
        
    }
    
    void postTweet(int userId, int tweetId) {
       tweets[userId].push_back({tweetId, counter++});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> users;
        vector<pair<int, int>> q;

        followers[userId].insert(userId);
        for(const int& it: followers[userId]){
            int count = 0;
            for(int i = tweets[it].size() - 1; i >= 0; i--){
                q.push_back(tweets[it][i]);
                count++;
                if(count == 10) break;
            }
        }

        sort(q.begin(), q.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        });

        vector<int> ans;
        int len = q.size();

        for(int i=0; i<len && i < 10; i++){
            ans.push_back(q[i].first);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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
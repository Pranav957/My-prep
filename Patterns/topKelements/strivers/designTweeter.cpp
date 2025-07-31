class Twitter {
    int timeStamp;
    unordered_map<int,vector<pair<int,int>>> tweets;
        unordered_map<int,unordered_set<int>> follows;
public:
    Twitter() {
        this->timeStamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++,tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
         priority_queue<pair<int,int>> pq;
         vector<int> res;
         for(auto followedId:follows[userId])
         {
            for(auto post:tweets[followedId])
            {
                pq.push(post);
            }
         }
          for(auto post:tweets[userId])
            {
                pq.push(post);
            }
           int count=0;
            while(!pq.empty() && count<10)
            {
                res.push_back(pq.top().second);
                pq.pop();
                count++;
            }
            return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
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

class Twitter {
public:
     
    unordered_map<int,set<int>> fo;
    unordered_map<int,vector<pair<int,int>>> t;
    int time;

    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++,tweetId});    
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto it=t[userId].begin();it!=t[userId].end();it++){
            pq.push(*it);
        }
        for(auto i=fo[userId].begin();i!=fo[userId].end();i++){
            int followed=*i;
            for(auto j=t[followed].begin();j!=t[followed].end();j++){
                pq.push(*j);
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            if(ans.size()==10) break;
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);   
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

struct User{
   int user_id;
   set<int> follows;
   vector<pair<int,int>> posts;
};

class Twitter {
public:
    int time = 0;
    unordered_map<int,User> mp;
    Twitter() {
       time = 0; 
       mp.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        User curr;
        time++;
        if(mp.count(userId)) curr=mp[userId];
        curr.posts.push_back({time,tweetId});
        mp[userId] = curr;
    }
    
    vector<int> getNewsFeed(int userId) {

     vector< pair<int,int> > tot;
     User& curr = mp[userId];

     for(auto& p : curr.posts) tot.push_back(p);

     for(auto f_id : curr.follows){
        for(auto fp : mp[f_id].posts) tot.push_back(fp);
     }

     sort(tot.begin(), tot.end());
     vector<int> ans;
     reverse(tot.begin(), tot.end());
     for(int i=0;i<min(10,(int)tot.size());i++){
        //cout<<i<<endl;
       ans.push_back(tot[i].second);
     }

    return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        mp[followerId].follows.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        mp[followerId].follows.erase(followeeId);
        
    }
};

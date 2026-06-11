class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(char c : s){
           mp[c]++;
           if(mp[c] > (int)(s.size()+1)/2)
             return "";
        }

        priority_queue< pair<int,int> > pq;
        for(auto it : mp)
        {
            pq.push({it.second,it.first-'a'});
        }

        string ans;

        while(!pq.empty()){
            auto p1 = pq.top();
            pq.pop();
            ans += ('a'+p1.second);
            p1.first--;
            
            if(!pq.empty()){
                 auto p2 = pq.top();
                  pq.pop();
                  ans += ('a'+p2.second);
                  p2.first--;
                  if(p2.first){
                    pq.push(p2);
                  }

            }
            if(p1.first)
               pq.push(p1);
        }

        return ans;
        
    }
};
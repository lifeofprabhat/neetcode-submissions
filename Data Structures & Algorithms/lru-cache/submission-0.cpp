class LRUCache {
public:
    std::list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator >mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        
    }

    void evict(){
        auto it = l.end();
        it--;
        mp.erase(it->first);
        l.pop_back();
    }
    
    int get(int key) {
        if(!mp.contains(key)) return -1;
        int val;
        if(mp.contains(key)){
            val = mp[key]->second;
            l.erase(mp[key]);    
        }
  
        l.push_front({key,val});
        mp[key] = l.begin();
        return val;
        
    }
    
    void put(int key, int val) {
        
         if(mp.contains(key)){
           // val = mp[key]->second;
            l.erase(mp[key]);    
        }

        l.push_front({key,val});
        mp[key] = l.begin();
        if(mp.size()>cap)
           evict();    
    }
};

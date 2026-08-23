/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intV) {

        vector<int>pref(1000001,0);
        if(!intV.size()) return 0;
        int mx = 1;
        
        for(auto v : intV){
            pref[v.start]++;
            pref[v.end]--;
        }

        for(int i=1;i<1000001;i++){
            pref[i]+=pref[i-1];
            mx = max(mx,pref[i]);
        }


        return mx;
    }
};

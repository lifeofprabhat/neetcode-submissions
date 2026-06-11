class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

     vector< vector<int> > vv;
     for(int i=0;i<tasks.size();i++){
        vv.push_back({tasks[i][0], tasks[i][1], i});
     }
     sort(vv.begin(), vv.end(), [](vector<int>&a,vector<int>b){
        if(a[0]==b[0] && a[1]==b[1]){
            return a[2]< b[2];
        }
        else if(a[0]==b[0]){
            return a[1] < b[1];
        }
        else{
            return a[0] < b[0];
        }
     });
   
    // for(int i=0;i<tasks.size();i++){
    //   cout<<vv[i][0]<<" "<<vv[i][1]<<" "<<vv[i][2]<<endl;
    // }
     set<vector<int> > st;

     int currT= vv[0][0];
     int vIdx = 0;
     vector<int>ans;

     int jobDone = 0;
     while(jobDone<tasks.size()){ //untill all tasks are done
        while( vIdx<tasks.size() && currT >= vv[vIdx][0]){ //consider all tasks 
            st.insert({vv[vIdx][1],vv[vIdx][2]});          //available till now
            vIdx++;
        }
        
        if(st.empty() && vIdx<tasks.size() ){
            currT = vv[vIdx][0];
            continue;
        }

        auto currJob = *(st.begin());
        ans.push_back(currJob[1]);
        st.erase(st.begin());
        currT += currJob[0];
        jobDone++;
     }

    return ans;   
        
    }
};
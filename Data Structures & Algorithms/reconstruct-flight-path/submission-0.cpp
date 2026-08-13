class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<string> ans;

    void dfs(string node) {
        while (!mp[node].empty()) {

            string next = mp[node].back();
            mp[node].pop_back();

            dfs(next);
        }

        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &v : tickets) {
            mp[v[0]].push_back(v[1]);
        }

        // Sort descending so smallest destination is at the back
        for (auto &[from, to] : mp) {
            sort(to.rbegin(), to.rend());
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
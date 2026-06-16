class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<pair<int,int>> ans;
        for(auto it: mp){
            ans.push_back({it.second, it.first});
        }
        sort(ans.rbegin(), ans.rend());
        vector<int> res;
        for(int i = 0;i<k;i++){
            res.push_back(ans[i].second);
        }
        return res;
    }
};
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);

            if (mp[nums[i]].size() >= 3) {
                int n = mp[nums[i]].size();

                ans = min(ans, 2 * (mp[nums[i]][n-1] 
                                  - mp[nums[i]][n-3]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
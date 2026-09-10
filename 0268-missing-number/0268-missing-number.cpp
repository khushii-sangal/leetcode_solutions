class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz=nums.size();
        int i;

        sort(nums.begin(),nums.end());
        for(i=0;i<sz;i++)
        {
            if(i!=nums[i])
            break;
        }
       return i;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0,i=0;
        int k=1;
        nums[index]=nums[i];
        for(i=1;i<nums.size();i++)
        {
            if(nums[index]==nums[i])
            {
                continue;
            }
            else
            {
                index++;
                nums[index]=nums[i];
                k++;
            }
        }
        return k;
    }
};
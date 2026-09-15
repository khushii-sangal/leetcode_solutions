class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mid;
        
        while(start<=end)
        {
        mid=(start+end)/2;
        if(target<nums[mid])
        end=mid-1;
        else if(target>nums[mid])
        start=mid+1;
        else if(target==nums[mid])
        {
        return mid;
        }
        }
        return start;
    }
};
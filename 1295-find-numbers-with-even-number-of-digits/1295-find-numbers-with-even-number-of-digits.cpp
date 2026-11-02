class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int j=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            j=nums[i];
            if((to_string(j).length()%2)==0)
            count++;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size=nums.size();
        vector<int>ans(2*size);
        int j=0;

        for(int i=0;i<2*size;i++)
        {
            if(i<size)
            ans[i]=nums[i];
            else
            {
            ans[i]=nums[j];
            j++;
            }
        }
        return ans;
    }
};
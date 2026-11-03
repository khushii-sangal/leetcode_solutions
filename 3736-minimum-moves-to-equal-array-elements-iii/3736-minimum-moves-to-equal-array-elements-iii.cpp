class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0, max_no = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            max_no = max(nums[i], max_no);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            count += max_no - nums[i];
        }

        return count;
    }
};

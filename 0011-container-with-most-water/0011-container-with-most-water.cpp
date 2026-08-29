// brute-force approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water=0;
        int w,ht,curr_water;
        int start=0;
        int end=height.size()-1;
            while(start<end)
            {
              w=end-start;
              ht=min(height[start],height[end]);
              curr_water=w*ht;
              max_water=max(curr_water,max_water);
              height[start]<height[end]?start++:end--;
            }
        
        return max_water;
        
    }
};
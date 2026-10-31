class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        char swap=' ';
        int end=s.size()-1;
        while(start<=end)
        {
            swap=s[start];
            s[start]=s[end];
            s[end]=swap;

            start++;
            end--;

        }
        return;
    }
    
};
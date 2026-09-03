class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 ||(x%10==0 && x!=0))
        return false;
        int n=x;
        long long rev=0;

        while(x>0)
        {
            int c=x%10;
            rev=rev*10+c;
            x=x/10;
        }
        

        if(n==int(rev))
        return true;
        else
        return false;
    }
};
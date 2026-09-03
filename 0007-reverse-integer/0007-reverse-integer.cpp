class Solution {
public:
    int reverse(int x) {
        int c=0;
        long long reverse=0;
        int n=x;
       
        while(x!=0)
        {
            c=x%10;
            reverse=reverse*10+c;
            x=x/10;
        }
        
       

        if(reverse>INT_MAX || reverse < INT_MIN)
        return 0;

        return int(reverse);
    }
};
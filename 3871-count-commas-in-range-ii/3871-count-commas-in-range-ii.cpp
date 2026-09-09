class Solution {
public:
    long long countCommas(long long n) {

        long long ans=0;
        for(long long i=1000;i<=n;)
        {
            ans+=(n-i)+1;
        
        if(i>n/1000)
        break;
        i*=1000;
        }
        
        
        return ans;
    }
};
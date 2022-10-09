
    
    class Solution {
public:
   
    int maxProfit(int k,vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int count=k;count>0;count--)
                {
                    if(buy==1){
                    dp[index][buy][count]=max( (-p[index])+dp[index+1][0][count]
                       ,dp[index+1][1][count]);
                             }
                    else
                    {
                        dp[index][buy][count]=max( (p[index])+dp[index+1][1][count-1]
                       ,dp[index+1][0][count]);
                    }
                                              
         
                }
            }
        }
        return dp[0][1][k];
        
        //return solve(p,n,0,1,2,dp);
    }
};


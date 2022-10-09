// R E C U R S I O N😢
// class Solution {
// public:
//     int solve(vector<int> &p,int n,int index,int buy,int count)
//     {
//         if(index==n || count==2)return 0;
//         int profit=0;
//         if(buy==1)
//         {
//             profit= max( (-p[index])+solve(p,n,index+1,0,count)
//                        ,solve(p,n,index+1,1,count));
//         }
//         else
//         {
//             profit= max( (p[index])+solve(p,n,index+1,1,count+1)
//                        ,solve(p,n,index+1,0,count));
//         }
//         return profit;
//     }
//     int maxProfit(vector<int>& p) {
//       int n=p.size();
        
//         return solve(p,n,0,1,0);
//     }
// };



// M E M O I Z A T I O N😢
// class Solution {
// public:
//     int solve(vector<int> &p,int n,int index,int buy,int count,vector<vector<vector<int>>> &dp)
//     {
//         if(index==n || count==0)return 0;
//         if(dp[index][buy][count]!=-1)
//             return dp[index][buy][count];
//         int profit=0;
//         if(buy==1)
//         {
//             profit= max( (-p[index])+solve(p,n,index+1,0,count,dp)
//                        ,solve(p,n,index+1,1,count,dp));
//         }
//         else
//         {
//             profit= max( (p[index])+solve(p,n,index+1,1,count-1,dp)
//                        ,solve(p,n,index+1,0,count,dp));
//         }
//         dp[index][buy][count]=profit;
//         return profit;
//     }
//     int maxProfit(vector<int>& p) {
//       int n=p.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         return solve(p,n,0,1,2,dp);
//     }
// };


class Solution {
public:
   
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int count=2;count>0;count--)
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
        return dp[0][1][2];
        
        //return solve(p,n,0,1,2,dp);
    }
};


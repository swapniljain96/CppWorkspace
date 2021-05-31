class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1=w1.size();
        int n2=w2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
        { for(int j=0;j<=n2;j++)
           { dp[i][j]=0;}         
        }
       for(int i=1;i<=n1;i++)
        { for(int j=1;j<=n2;j++)
            { if(w1[i-1]==w2[j-1])
              { dp[i][j]=1+dp[i-1][j-1]; }
              else
              { dp[i][j]=max(dp[i-1][j],dp[i][j-1]); }
            }
        }
        
        return n1+n2-(2*dp[n1][n2]);
    }
};
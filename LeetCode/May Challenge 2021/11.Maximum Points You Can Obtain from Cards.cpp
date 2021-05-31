//Method 1
class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int curTotal=0;
        for(int i=0;i<k;i++)
        { curTotal+=a[i]; }
        
        int curMax=curTotal;
        for(int i=k-1,j=n-1;i>=0;i--,j--)
        { curTotal-=a[i];
          curTotal+=a[j];
          curMax=max(curMax,curTotal);  
        }
    return curMax;
    }
};

//Method 2
class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int L[k+1], R[k+1];
        L[0]=0; R[0]=0;
        for(int i=0;i<k;i++)
        { L[i+1]=L[i]+a[i];}
        for(int i=n-1,j=0;i>=n-k;i--,j++)
        { R[j+1]=R[j]+a[i];}
        int ans=0;
        for(int i=0;i<=k;i++)
        { ans=max(ans,L[i]+R[k-i]);   }
     return ans;
    }
};
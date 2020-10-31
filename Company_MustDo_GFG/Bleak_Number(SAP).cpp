// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
public:
    int countbit(int n)
    { int cnt=0;
      while(n>0)
      { cnt+=(n&1);
        n=n>>1;
      }
      return cnt;
    }
    
    int is_bleak(int n)
	{ 
	  int f=1;
	  for(int i=0;i<n;i++)
	  {  int res=countbit(i)+i;
	      if(res==n)
	      {
	          f=0;
	          break;
	      }
	   }
        return f;
	}
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}
  // } Driver Code Ends
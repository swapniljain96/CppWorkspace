#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n)
{  int maxcnt=0,cnt=1;
    sort(a,a+n);
    if(n==1)
    { return 1;}
    else
    { for(int i=1;i<n;i++)
      { if((a[i]-a[i-1])==1)
        { cnt++; }
        else if((a[i]-a[i-1])>1)
         { int t=cnt;
           cnt=1;
           if(maxcnt<t)
           { maxcnt=t; }
         }            
      }
      if(maxcnt<cnt)
      { maxcnt=cnt; }
    }
    return maxcnt;
}

int main() {
	int t; cin>>t;
	while(t--)
	{ int n;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++) { cin>>a[i]; }
	  cout<<solve(a,n)<<"\n";
	 }
	return 0;
}
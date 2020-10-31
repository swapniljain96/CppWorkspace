#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
	cin>>t;
	while(t--)
	{ int n,m;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++)cin>>a[i];
	  cin>>m;
	  
	  sort(a,a+n);
	  
	  int mindif=INT_MAX;
	  for(int i=0;(i+m-1)<n;i++)
	  { 
	     int diff=a[i+m-1]-a[i];
	      if(diff<mindif)
	      {  mindif=diff; }
	   }
	 cout<<mindif<<"\n";   
	}
	return 0;
}
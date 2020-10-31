#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{ int n;
	  cin>>n;
	  int a[n];
	  for(int i=0;i<n;i++) cin>>a[i];
	  
	  int cnt[3]={0,0,0};
	  for(int i=0;i<n;i++)  
	  { if(a[i]==0)
	    {cnt[0]=cnt[0]+1; }
	    
	    if(a[i]==1)
	    {cnt[1]=cnt[1]+1; }
	    
	    if(a[i]==2)
	    {cnt[2]=cnt[2]+1; }
	  }  
	  int n0,n1,n2;
      n0=cnt[0];
      n1=cnt[1];
      n2=cnt[2];
      for(int i=0;i<n0;i++)
      { a[i]=0; }
	  for(int i=n0;i<(n0+n1);i++)
      { a[i]=1; }
	  for(int i=(n0+n1);i<(n0+n1+n2);i++)
      { a[i]=2; }
	  
	  for(int i=0;i<n;i++) 
	  { cout<<a[i]<<" "; }
	  cout<<"\n";
	    
	}
	return 0;
}
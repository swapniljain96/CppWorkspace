#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--)
	{ int n;
	  cin>>n;
	  vector<int> v(n);
	  for(int i=0;i<n;i++) cin>>v[i];
	  int msf=INT_MIN;
	  int meh=0;
	  for(int i=0;i<n;i++)
	  {  meh=meh+v[i];
	     if(meh<v[i])
	       {meh=v[i];}
	     if(msf<meh)
	       {msf=meh;}    
	  }
      cout<<msf<<"\n";
	}
	return 0;
}
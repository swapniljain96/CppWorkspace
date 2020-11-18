#include<bits/stdc++.h>
using namespace std;
int main()
 {  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;cin>>t;
	while(t--)
	{  int n1,n2;
	   cin>>n1; cin>>n2;
	   vector<int> a(n1),b(n2);
	   for(int i=0;i<n1;i++) cin>>a[i];
	   for(int i=0;i<n2;i++) cin>>b[i];
	   set<int> s;
	   for(int i:a) 
	   { s.insert(i); }
	   
	   for(int i:b) 
	   { auto pos=s.find(i);
	      if(pos!=s.end())
	      { continue; }
	      else
	      {s.insert(i);}
	   }
	   cout<<s.size()<<"\n";
	}
	return 0;
}
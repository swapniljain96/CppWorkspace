#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
    { int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      int k;
      cin>>k;
      
      int i,min,pos;
      while((k-1))
     {min=a[0];
      pos=0;
      for(i=1;i<n;i++)
      { if(min>a[i])
         {
            min=a[i];
            pos=i;
         }
      }
      a[pos]=INT_MAX;    
      k--;  
     }  
     
     min=a[0];
     pos=0;
     for(i=1;i<n;i++)
      { if(min>a[i])
         {
            min=a[i];
            pos=i;
         }
      } 
      cout<<"\n"<<min;
    }
    return 0;
}
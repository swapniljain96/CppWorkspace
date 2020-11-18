#include<iostream>
using namespace std;
void solve(int a[],int n)
{  if(n==1)
   { cout<<a[0]; }
  else 
     { int temp=a[n-1];
       for(int i=n-1;i>0;i--)
       { a[i]=a[i-1]; }
        a[0]=temp;
       for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
     }
}


int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin>>t;
  while(t--)
  {  int n; cin>>n;
     int a[n];
     for(int i=0;i<n;i++) cin>>a[i];
     solve(a,n);
     cout<<"\n";
   }
}
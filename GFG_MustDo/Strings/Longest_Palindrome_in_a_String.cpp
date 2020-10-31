#include <bits/stdc++.h>
using namespace std;
int main()
{   int t;
    cin>>t;
    cin.ignore();
    while(t--)
    { string ss;
      getline(cin,ss);
      cout<<"String is:"<<ss<<"\n\n";
      if(ss.length()<=1) { cout<<"If string length is 1: "<<ss; }
      int maxl=1;
      int n=ss.length();
      int st=0,end=0;

      //odd      
      for(int i=0;i<n-1;i++)
      {  int l=i,r=i;
          while(l>=0 && r<n)
          {  if(ss[l]==ss[r])
               { l--;  r++; }
             else
               break;   
          }
            int len=r-l-1;
            if(maxl<len){
            maxl=len;         
            st=l+1;
            end=r-1;
       }
      }
       //even      
      for(int i=0;i<n-1;i++)
      { int l=i,r=i+1;
          while(l>=0 && r<n)
          {  if(ss[l]==ss[r])
               { l--;  r++; }
             else
               break;   
          }
            int len=r-l-1;
            if(maxl<len){
            maxl=len;         
            st=l+1;
            end=r-1;
          }       
       }
       cout <<<"\nAt the end we get: "<ss.substr(st,maxl) <<"\n";
     }
  cout << "\n";
	system("pause");
	return 0;
}

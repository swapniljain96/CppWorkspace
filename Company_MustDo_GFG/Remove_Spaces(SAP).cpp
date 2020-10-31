#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    { string ss,st="";
      getline(cin,ss);
      for(int i=0;i<ss.size();i++)   
        {   if(ss[i]==' ')
            {  continue; }
            st+=ss[i]; 
         } 
       cout<<st<<"\n";    
    }
	return 0;
}
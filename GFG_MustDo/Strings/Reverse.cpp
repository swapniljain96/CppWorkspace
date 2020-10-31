#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore();
    // cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(t--)
    { string s;
      cin>>s;
      stack<char> st;
      int c=0;
      for(int i=0;i<s.size();i<i++)
      {  
          if(s[i]=='.')
          { i=i-c;
            while(st.empty()==false)
            {  
                s[i]=st.top();
                st.pop();
                i++;
            }  
            c=0;
          }
          else
          { st.push(s[i]);
            c++;
          }
       }
       int i=s.size()-c;
       while(st.empty()==false)
        {
           s[i]=st.top();
           st.pop();
           i++;
        }
         
        reverse(s.begin(),s.end());
        cout<<s<<"\n";
    }
          
          
    return 0;
}
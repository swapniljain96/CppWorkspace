class Solution {
public:
    int evalRPN(vector<string>& a) {
      int res;
      stack<int> st;
      for(int i=0;i<a.size();i++)
      { int c;
         if(a[i]=="+" || a[i]=="-"||a[i]=="*"|| a[i]=="/" )
         { int y=st.top(); st.pop();
           int x=st.top(); st.pop();
           int c;
           if(a[i]=="+")    { c=x+y;}
           else if(a[i]=="-"){c=x-y;}
           else if(a[i]=="*"){c=x*y;}
           else if(a[i]=="/"){c=x/y;}
           st.push(c);
         }  
         else
         { st.push(stoi(a[i]));    }
      }
      return st.top();  
    }
};
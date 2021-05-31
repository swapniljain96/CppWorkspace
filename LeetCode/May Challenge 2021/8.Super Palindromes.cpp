class Solution {
public: 
    #define ll long long
    
    bool checkPal(string s)
    {  string res=s;
       reverse(res.begin(),res.end());
       return res==s;
    }
    
    int superpalindromesInRange(string left, string right) {
        int ans=0;
        ll l=stoll(left);
        ll r=stoll(right);
        vector<ll> store;
        for(ll i=1;i<10;i++){store.push_back(i);}
        
        for(ll i=1;i<=1e4;i++)
        { string s1=to_string(i);
          string s2=to_string(i);
          reverse(s2.begin(),s2.end());
         
          //even length pallindrome
         store.push_back(stoll(s1+s2));
         
         //odd length pallindrome
         for(ll j=0;j<10;j++)
         {   string middle=s1;
             middle=middle+to_string(j);
             middle=middle+s2;
             store.push_back(stoll(middle));
         }
        }
        
        for(auto it:store)
        { if(it>1e9) {continue;}
            
         ll num=it*it;
         
         if(num>=l && num<=r and checkPal(to_string(num)))
             ans++;
            
        }
        return ans;
    }
};
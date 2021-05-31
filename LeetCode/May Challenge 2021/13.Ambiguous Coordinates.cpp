class Solution {
public:
    vector<string> posCord(string s){
        int n=s.length();
        vector<string> store;
        if(n==1){
            store.push_back(s);
            return store;
        }
        if(s[0]=='0' and s[n-1]=='0')
        {return store;}
        if(s[0]=='0')
        { store.push_back("0."+s.substr(1));
            return store;
        }
        if(s[n-1]=='0')
        {store.push_back(s);
         return store;
        }
        string rev=s;
        string start="";
        store.push_back(s);
        for(int i=0;i<n-1;i++){
           start+=s[i];
           rev.erase(rev.begin());
           store.push_back(start+"."+rev); 
         }
        return store;
        
    }    
    vector<string> ambiguousCoordinates(string s) {
        int n=s.length();
        vector<string> ans;
        for(int i=1;i<n-2;i++){
            vector<string> R=posCord(s.substr(1,i));
            vector<string> S=posCord(s.substr(i+1,n-i-2));
            for(auto &ch1:R)
            { for(auto &ch2:S){
                ans.push_back("("+ch1+", "+ch2+")");
              }
            }
        }
        return ans;
    }
};
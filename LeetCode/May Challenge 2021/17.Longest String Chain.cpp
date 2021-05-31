class Solution {
public:
    int longestStrChain(vector<string>& words) {
       
        sort(words.begin(),words.end(),[](const string& s1,const string& s2)
        {return s1.size()>s2.size();});
    
        unordered_map<string,int> index;
        int n=words.size(); 
        
        for(int i=0;i<n;i++)
        {index[words[i]]=i;}
    
        int res=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        { for(int j=0;j<words[i].length();j++)
            { string newstr=words[i].substr(0,j)+words[i].substr(j+1);
               if(index.count(newstr)){
                dp[index[newstr]]=max(dp[index[newstr]],1+dp[i]);
                res=max(res,dp[index[newstr]]);
                   
               }
            }
          }
        return res;
    }
};
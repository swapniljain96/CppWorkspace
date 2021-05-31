// Method 1
class Solution {
public:
    bool matches(string str,string pat)
    { vector<bool> visit(26,false);
      unordered_map<char,char> umap;
      for(int i=0;i<str.size();i++)
      {  char w=str[i],p=pat[i];
          if(umap[w] && umap[w]!=p) return false;
       
          if(!umap[w] && visit[p-'a']) return false;
          
          umap[w]=p;
          visit[p-'a']=true;
          
      }
        
     return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string s:words)
        { if(matches(s,pattern))
          { ans.push_back(s);}
        }
       return ans;
    }
};

//Method 2
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
         for(string s:words){
            if(matches(s,pattern)){
                ans.push_back(s);
            }
        }      
        return ans;
        }
    
       bool matches(string s,string patt){
           unordered_map<char,char> stop,ptos;
           for(int i=0;i<s.size();i++)
           { char schar=s[i],pchar=patt[i];
             if(!stop[schar]) stop[schar]=pchar;   
             if(!ptos[pchar]) ptos[pchar]=schar;   
             if(ptos[pchar]!=schar || stop[schar]!=pchar)  
             {  return false;  }
            }
           return true;
       }
    
};
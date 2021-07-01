// Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.
class Solution {
public:
    bool checkPal(string s)
    { string r=s;
      reverse(r.begin(),r.end());
      return r==s;
    }
    vector<vector<int>> palindromePairs(vector<string>& a) {
      vector<vector<int>> ans;
      unordered_map<string,int> m;
      for(int i=0;i<a.size();i++){
      string tmp=a[i];
      reverse(tmp.begin(),tmp.end());
      m[tmp]=i;  
      }
      if(m.count("")){
        for(int i=0;i<a.size();i++)
        { if(!a[i].empty() and checkPal(a[i])){
           ans.push_back({i,m[""]});
          }
         }
        }
      for(int i=0;i<a.size();i++)
      { string left,right;
        for(int j=0;j<a[i].size();j++)
        { left.push_back(a[i][j]);
          right=a[i].substr(j+1);
          if(m.count(left) and i!=m[left] and checkPal(right))         
            ans.push_back({i,m[left]});
          if(m.count(right) and i!=m[right] and checkPal(left))
            ans.push_back({m[right],i});
        }
      }
        return ans; 
    }
};
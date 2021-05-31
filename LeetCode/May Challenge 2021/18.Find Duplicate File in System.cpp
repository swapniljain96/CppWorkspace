class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(string a:paths){
            string pt="";
            int i=0;
            while(i<a.size() && a[i]!=' ')  //here we take file path
               { pt+=a[i++];  }
            pt+='/';
            i++;    
            while(i<a.size())
            { string file="",content="";
              while(i<a.size() && a[i]!='(')
               { file+=a[i++];  }               //here we take file name

              while(i<a.size() && a[i]!=' ')
                { content+=a[i++]; }            //here we take file content
              
              mp[content].push_back(pt+file);   //here we take put them in map
               i++;
             
            }
        }
        
        for(auto &x:mp)
        { if(x.second.size()>1)
            { res.push_back(x.second);}
        }
        return res;
    }
};
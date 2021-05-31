class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pro, string src) {
        sort(pro.begin(),pro.end());
        vector<vector<string>> ans;
        int start,bsstart=0; int n=pro.size();
        string pre;
        for(auto c:src)
        { pre+=c;
          start=lower_bound(pro.begin()+bsstart,pro.end(),pre)-pro.begin();
         ans.push_back({}); //ye imp krna hi hai
         for(int i=start;i< min(start+3,n) && !pro[i].compare(0,pre.size(),pre);i++)
           ans.back().push_back(pro[i]);
         bsstart=start;
        }
      return ans;
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
      int n=a.size();
      set<int> s;
      int i=0,j=0;
      int ans=0; int sum=0;
      while(i<n and j<n)
      {  if(s.find(a[j])==s.end())
         { sum+=a[j];
           ans=max(ans,sum);
           s.insert(a[j]); 
           j++;
          }
         else
         { sum-=a[i];
           s.erase(a[i]);
           i++;
         }
      }
      for(auto i=s.begin();i!=s.end();i++)
      { cout<<*i<<" ";}
      return ans;
    }
};
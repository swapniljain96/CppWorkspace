class Solution {
public:
    int maximumGap(vector<int>& a) {
      int n=a.size();
      int ans=0;
      if(n<2) return 0;
      sort(a.begin(),a.end());
      for(int i=1;i<n;i++){
          ans=max(ans,a[i]-a[i-1]);
      }
       return ans;
    }
};
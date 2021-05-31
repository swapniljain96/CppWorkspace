class Solution {
public:
    int minMoves2(vector<int>& a) {
        int ans=0;
        sort(a.begin(),a.end());
        int midval=a[a.size()/2];
        for(int val:a)
        {  ans+=abs(val-midval);  }
        return ans;   
    }
};
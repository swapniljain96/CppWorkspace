class Solution {
public:
    int maxProduct(vector<string>& a) {
        int ans = 0;
        int n = a.size();
        vector<int> bits(n,0);
 
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i].length();j++)
                bits[i]|=(1<<(a[i][j]-'a'));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int w1 = a[i].length(); 
               int w2 = a[j].length();
                if((bits[i]&bits[j])==0)
                    ans=max(ans,w1*w2);
            }
        }
        return ans;
    }
};
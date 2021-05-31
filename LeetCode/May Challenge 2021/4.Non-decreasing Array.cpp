class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int cnt=0;
        for(int i=1;i<a.size();i++)
            { if(a[i-1]>a[i])
               { cnt++;
                 if(cnt>1) return false;
                 if(i<2 || a[i-2]<=a[i]) a[i-1]=a[i];
                 else a[i]=a[i-1];
               }
            }
        return true;
    }
};
class Solution {
public:
    int jump(vector<int>& a) {
        int cur=0,far=0,cnt=0;
        for(int i=0;i<a.size()-1;i++)
        { far=max(far,i+a[i]);
           if(i==cur)
           { cnt++;
             cur=far;
           }
        }
        return cnt;
    }
};
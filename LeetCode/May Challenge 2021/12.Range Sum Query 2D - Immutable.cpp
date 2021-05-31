class NumMatrix {
public:
    int m[200][200];
    int r,c;
    NumMatrix(vector<vector<int>>& a) {
        r=a.size();
        c=a[0].size();
        for(int i=0;i<r;i++){
          for(int j=0;j<c;j++)
            m[i][j]=a[i][j]; }
        
        for(int j=0;j<c;j++){
          for(int i=1;i<r;i++)
            m[i][j]+=m[i-1][j]; }
        
        for(int i=0;i<r;i++){
          for(int j=1;j<c;j++)
            m[i][j]+=m[i][j-1]; }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int res=m[r2][c2];
        
        if(r1>0 and c1>0)
        { res-=m[r1-1][c2];
          res-=m[r2][c1-1];
          res+=m[r1-1][c1-1];
        }
        else if(r1==0 and c1!=0){
            res-=m[r2][c1-1];
        }
        else if(r1!=0 and c1==0){
            res-=m[r1-1][c2];
        }
        return res;
    }
};

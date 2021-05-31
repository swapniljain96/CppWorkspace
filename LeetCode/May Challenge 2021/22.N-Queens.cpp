class Solution {
public:
    vector<vector<string>> res;
    
    bool check(vector<string> tmp,int r,int c,int n){ 
        for(int i=0;i<c;i++) 
        { if(tmp[r][i]=='Q') return false; }
      
       for(int i=r-1,j=c-1;i>=0 and j>=0;i--,j--)
        { if(tmp[i][j]=='Q') return false;}
     
       for(int i=r+1,j=c-1;i<n and j>=0;i++,j--)
        { if(tmp[i][j]=='Q') return false;}
        return true; 
      
    }

    void recur(int c,int n,vector<string> tmp){
        if(c==n){res.push_back(tmp); return;}
        
        for(int i=0;i<n;i++){
            if(check(tmp,i,c,n)){
                tmp[i][c]='Q';
                recur(c+1,n,tmp);
                tmp[i][c]='.';
            }
        }
    
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp;
        string s="";
        for(int i=0;i<n;i++) s+='.';
        
        for(int i=0;i<n;i++) tmp.push_back(s);
        
        recur(0,n,tmp);
        return res;
        
    }
};
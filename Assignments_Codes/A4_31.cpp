class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        UFind ufind(graph.size());
        for(int i=0;i<graph.size();++i){
            for(int j=i+1;j<graph.size();j++){
                if(graph[i][j]==1){
                    ufind.uset(i,j);
                }
            }
        }
        unordered_map<int,int> usize;
        for(int i=0;i<graph.size();i++){
            ++usize[ufind.fset(i)];
        }
        unordered_map<int,int> mal_cnt;
        for(const auto& i:initial){
            ++mal_cnt[ufind.fset(i)];
        }
        return *min_element(initial.cbegin(),initial.cend(),
                    [&](const int& a, const int& b){
                        return make_tuple(mal_cnt[ufind.fset(a)] > 1 ? 1: 0,
                                          -usize[ufind.fset(a)],a) <
                               make_tuple(mal_cnt[ufind.fset(b)] > 1 ? 1: 0,
                                          -usize[ufind.fset(b)],b);
                          });
    }
private:
  class UFind{
      public:
         UFind(const int n):st(n){
             iota(st.begin(),st.end(),0);
         }
      int fset(const int x){
          if(st[x]!=x){
              st[x]=fset(st[x]);
          }
          return st[x];
      }
      bool uset(const int x,const int  y){
          int x_root=fset(x),y_root=fset(y);
          if(x_root==y_root){
              return false;
          }
          st[min(x_root,y_root)] = max(x_root,y_root);
          return true;
      }private:
      vector<int> st;
  };
};
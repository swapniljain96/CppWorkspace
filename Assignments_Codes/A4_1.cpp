#include <bits/stdc++.h>
 
using namespace std;
 
int const NMAX = 1e5;
int n, m, k;
 
int nComp;
bool visited[1 + NMAX];
vector<int> g[1 + NMAX];
vector<int> cc[1 + NMAX];
int ccIndex[1 + NMAX];
int sz[1 + NMAX];
 
void dfs(int from) {
  visited[from] = true;
  cc[nComp].push_back(from);
  ccIndex[from] = nComp;
  for(auto to : g[from]) {
    if(!visited[to]) {
	    dfs(to);
	  }
  }
}
 
void dfsOutput(int from) {
  visited[from] = true;
  cout << from << " ";
  sz[ccIndex[from]]--;
  if(sz[ccIndex[from]] == 0) {
    k++;
  }
  if(from == n || k == nComp - 1) {
    for(auto to : cc[ccIndex[from]]) {
      if(!visited[to]) {
        visited[to] = true;
        cout << to << " ";
      }
    }
    return;
  }
  if(ccIndex[from] != ccIndex[from + 1]) {
    k--;
  }
  dfsOutput(from + 1);
}
 
int main() {
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    int a, b;
	  cin >> a >> b;
	  g[a].push_back(b);
	  g[b].push_back(a);
  }
 
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      nComp++;
      dfs(i);
      sz[ccIndex[i]] = cc[ccIndex[i]].size();
      sort(cc[nComp].begin(), cc[nComp].end());
    }
  }
  if(k < nComp - 1) {
    cout << -1;
    return 0;
  }
  memset(visited, false, sizeof(visited));
  dfsOutput(1);
  for(int i = 2; i <= n; i++) {
    if(!visited[i]) {
      for(auto to : cc[ccIndex[i]]) {
        if(!visited[to]) {
          visited[to] = true;
          cout << to << " ";
        }
      }
    }
  }
  return 0;
}
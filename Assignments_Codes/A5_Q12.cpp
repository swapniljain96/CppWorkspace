#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <int> a(n, 0);
		// vector <int> b(n, 0);
		int front = 0, end = n-1;
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		int small = min(a[front], a[end]);
		int no = 0;
		while(front<= end){
			if(min(a[front], a[end]) < small){
				cout<<"NO\n";
				no = -1;
				break;
			}
			small = min(a[front], a[end]);
			if(small == a[front]){
				front += 1;
				continue;
			}
			if(small == a[end]){
				end -= 1;
			}
		}
		if(no != -1) cout<<"YES\n";
 
	}	
}
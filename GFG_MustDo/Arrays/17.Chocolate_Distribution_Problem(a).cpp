// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
     sort(a.begin(),a.end());  //here first we sort the array 
     long long res=INT_MAX;    //initialize our result with largest value
     for(int i=0;i<n-m+1;i++) 
     { res=min(res,(a[i+m-1]-a[i])); }   //we subtract the window 1st element and last element and take minimum
     return res;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends
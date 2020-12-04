/*
// Sample code to perform I/O:
 
#include <iostream>
 
using namespace std;
 
int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include<bits/stdc++.h>
using namespace std;
int calc(int a[],int n,int sum)
{
	bool dp[n][sum+1];
	dp[0][0]=true;
	for(int i=1;i<sum+1;i++)
	{
		if(a[0]==i)
			dp[0][i]=true;
		else
			dp[0][i]=false;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(a[i]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
			}
		}
	}
	int cnt=0;
	for(int i=0;i<sum+1;i++)
	{
		if(dp[n-1][i]==true)
			cnt++;
	}
	return cnt;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
			
		cout<<calc(a,n,sum)<<endl;	
	}
}
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, int s)
    {  int sum=a[0];       
       int i=0,j=1;            //i and j give the starting and ending of the window 
       vector<int> res;
       while(j<=n)               //here = is imp bcoz n is not size of array it is upper limit of number
       { if(sum==s)              //if pehle hi sum aa gaya toh aage check hi nahi krna
         { res.push_back(i+1);
           res.push_back(j);
           return res;
         }
         else if(sum<s)        //if sum is smaller than required sum then window ko increase karo (by doing j++)
         { sum+=a[j++];}
         else if(sum>s)        //if sum is larger than required sum then window ko decrease karo (by doing i++)
         {sum+=a[i--];}
       }
       res.push_back(-1);     //if given sum is not found then put -1 in vector and return it
       return res;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
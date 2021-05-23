// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int a[], int n)
	{  
	    sort(a,a+n);				 //firstly sort the array
	    int cnt=0;					 // initialize counter as 0
	    for(int i=n-1;i>0;i--)       // start from the last element to see usko koi triplet ban raha hau ya nahi
	    {  int j=0; int k=i-1;       // initialize start and end index pointers 
	       while(j<k)				 // i should must be less then j bcoz if [ 1 ,2 , 3 ,4,6] toh ye (3,3) ek triplet count kr lega
	       { if(a[i]==a[k]+a[j])     // if triplet found than counter++;
	         { cnt++; j++;
	          k--;
	         }
	         else if(a[j]+a[k]<a[i])    // sum if lesse then increase j by 1
	         {  j++; }
	         else
	         {k--; } 					// sum if greater then decrease j by 1
	       }
	    }
	    return cnt;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Method 1 by creating 2 arrays (1) that take sum from L->R (2)) that take sum from R->L
      int equilibriumPoint(long long a[], int n) {
      int L[n],R[n];
      L[0]=a[0];
      R[n-1]=a[n-1];
      
      for(int i=1;i<n;i++)
      { L[i]=L[i-1]+a[i]; }
     
      for(int i=n-2;i>=0;i--)
      { R[i]=R[i+1]+a[i]; }
      
      for(int i=0;i<n;i++)
      { if(R[i]==L[i])
         { return i+1;}
      }
     return -1;
    }

    // Method 2 by creating 1 array and equationg sum
      int equilibriumPoint(long long a[], int n) {
      int L[n],R[n];
      L[0]=a[0];
      for(int i=1;i<n;i++)
      { L[i]=L[i-1]+a[i]; }
      int leftSum,rightSum,totalSum=L[n-1];
      for(int i=0;i<n;i++)
      { leftSum=L[i]-a[i];
        rightSum=totalSum-L[i];
        if(leftSum==rightSum)
         { return i+1;}
      }
      return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
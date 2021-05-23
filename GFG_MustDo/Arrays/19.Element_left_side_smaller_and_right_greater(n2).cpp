// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int a[], int n) {
    int leftMax[n],rightMin[n];
    leftMax[0]=a[0];
    rightMin[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    { leftMax[i]=max(leftMax[i-1],a[i]);}
  
    for(int i=n-2;i>=0;i--)
    { rightMin[i]=min(rightMin[i+1],a[i]);} 

    for(int i=1;i<n-1;i++)            //here extreme elements cannot be required element so start with 1 end at n-1
    { if(leftMax[i]==rightMin[i])
       {return a[i];}
    }
    return -1;
}
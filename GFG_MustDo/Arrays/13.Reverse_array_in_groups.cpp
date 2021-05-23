// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
    
public:
    //Method 1 by swapping
    void reverseInGroups(vector<long long>& a, int n, int k){
        for(int i=0;i<n;i=i+k)
        { int l=i; 
          int r=min(i+k-1,n-1);   //min liya bcoz last wala group agar complete na bane toh array index out of bound aa jayega
           while(l<r)             // imp we will swap till half of the array
           { swap(a[l],a[r]);
             l++; r--;
           }
        }
    }

    //Method 2 by reversing
    void reverseInGroups(vector<long long>& a, int n, int k){   
        for(int i=0;i<n;i=i+k)
        { int l=i; 
          int r=min(i+k,n);
           reverse(a.begin()+l,a.begin()+r);
        }
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends
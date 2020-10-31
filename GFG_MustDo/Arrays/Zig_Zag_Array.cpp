// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution {
    public:
    void zigZag(int arr[], int n) {
	    bool f=true;
	    for(int i=0;i<n-1;i++)
	    {   if(f)
	        { if(arr[i]>arr[i+1])
	            { int t=arr[i];
	               arr[i]=arr[i+1];
	               arr[i+1]=t;
	            }
	        }
	        else
	        {  if(arr[i]<arr[i+1])
	            { int t=arr[i];
	               arr[i]=arr[i+1];
	               arr[i+1]=t;
	            }	            
	        }
	        f=!f;
	    }
    }
}; 




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
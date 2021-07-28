// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

vector<int> largestAndSecondLargest(int, int[]);


 // } Driver Code Ends


     

/* Function to find largest and second largest element
*sizeOfArray : number of elements in the array
* arr = input array
*/
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    vector<int> v;
    sort(arr,arr+sizeOfArray);
    max=arr[sizeOfArray-1];
    v.push_back(max);
    for(int i=sizeOfArray-1;i>=0;i--)
    { if(arr[i]!=max)
       { max2=arr[i];
         break;
        }
      else if(i==0)
      { max2=-1;}
    } 
    v.push_back(max2);
    return v;
     
}

// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
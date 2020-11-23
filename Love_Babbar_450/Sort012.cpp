// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {


    

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends

void sort012(int a[], int n)
{  int n0=0,n1=0,n2=0;
    for(int i=0;i<n;i++)    
    { if(a[i]==0) { n0++; }
      
      if(a[i]==1) { n1++; }
      
      if(a[i]==2) { n2++; }
     }
    for(int i=0;i<n0;i++) {a[i]=0;}
    
    for(int i=n0;i<(n0+n1);i++) {a[i]=1;}
    
    for(int i=(n0+n1);i<n;i++) {a[i]=2;}   
 }
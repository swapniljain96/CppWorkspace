#include<bits/stdc++.h>

using namespace std;
void get(int arr[],int n)
{
    int i=0,a=0,b=0;
    while(i<n-1)
    {
        while(i<n-1 && arr[i+1]<=arr[i]) //this gives us idea that if we are having decreasing order
        { i++;  }          
        
        if(i==n-1)                      //if we find array is in decreasing order we come out of the loop    
        { break;  }                        //and a=0 and b=0,then we don't have any profit 
        
        a=i++;
        while(i<n && arr[i]>=arr[i-1])
        { i++; }
        b=i-1;
        cout<<"("<<a<<" "<<b<<")"<<" ";
    }
    if(a==0 && b==0)
    cout<<"No Profit";
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n; int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        get(arr,n);
        cout<<"\n";
    }
    system("pause");
    return 0;
}
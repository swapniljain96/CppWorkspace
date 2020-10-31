// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int thirdLargest(int a[],int n);
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<thirdLargest(a,n)<<endl;
    }
}   // } Driver Code Ends

/* We can also do it Simple and Sweet but it take more time to sort
int thirdLargest(int a[], int n)
{ 
  if(n<3)
  {return -1;}
  sort(a,a+n);
  return a[n-3];
}
*/
int thirdLargest(int a[], int n)
{ 
  if(n<3)
  {return -1;}
  
  int i,max,pos;
  int k=2;    //here we find k largest so we run loop for k-1
  while(k>0) //this loop make values the k-1 largest element 0
  { max=a[0];
    pos=0;
    for(i=1;i<n;i++)
    { if(max<a[i])
      {  max=a[i];
         pos=i;
      }
    }
    a[pos]=INT_MIN;
    k--;
  }
  
  max=a[0];
  for(i=1;i<n;i++)
  {  if(max<a[i])
     {  max=a[i];
     }
  }
 return max;
}

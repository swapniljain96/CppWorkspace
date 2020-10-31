#include<bits/stdc++.h>

using namespace std;
void get(int a[],int n)
{  
  for(int i=0;i<n;i++)
  { int flag=1;
	for(int j=0;j<i;j++)
	{  if(a[j]>a[i])
		{ flag=0;
		  break;
		}	
	}
	for(int j=i+1;j<n;j++)
	{  if(a[j]<a[i])
		{ flag=0;
		  break;cin
		}	
	}
    if(flag == 1)
    {  cout<<a[i];
		break;
	}
   }
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
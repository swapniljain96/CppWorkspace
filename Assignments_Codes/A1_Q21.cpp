#include <iostream>
#include<vector>
using namespace std;
int FindPos(int a[],int X,int l,int n)
{ if(X<=a[l])
   return l;
  else if(X>=a[n-1])
   return n;
  else
  { int mid;
    while(l<n)
	{ int mid=(l+n)/2;
       if(X>=a[mid] && X<a[mid+1])
	    return mid;
		else if (X>a[mid])
		{
			l=mid+1;
		}
		else
		{
			n=mid-1;
		}
	}
  }
  //return 0;
}

void func(int a[],int X,int k,int l,int n)
{ int pos;
	if(n<k)
   {cout<<"Wrong input given"; }
  else {
  pos=FindPos(a,X,l,n);
  if ( pos == l){
	if(X<a[l])
	  { int temp=l;
	    while(k--)
		{ cout<<a[temp]<<" ";
		  temp++;
		}
	  }	
	  else
	  { int temp=l+1;
	    while(k--)
		{ cout<<a[temp]<<" ";
		  temp++;
		}
	  }	
   }
   else if (pos == n)
   { 	if(X>a[n-1])
	  { int temp=n-1;
	    while(k--)
		{ cout<<a[temp]<<" ";
		  temp--;
		}
	  }	
	  else
	  { int temp=n-2;
	    while(k--)
		{ cout<<a[temp]<<" ";
		  temp--;
		}
	  }	
    }
	
  } 
}

int main()
{   
	int n = 14;
	int a[]={2,5,8,9,12,13,21,26,33,43,70,73,84,100};
	int X=2,k=4;
	int l=0;
    for(int i=0;i<n;i++)
	{cout<<a[i]<<" ";}
	cout<<"\nValue of X:"<<X<<"\n";
	cout<<"Value of k:"<<k<<"\n";
	cout<<"\n";
	func(a,X,k,l,n);
	
	cout << "\n";
	system("pause");
	return 0;
}
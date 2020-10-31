#include <bits/stdc++.h>

using namespace std;

int bin(int a[],int x,int n)
    {  int l=0;
       int r=n;
       int mid;
       while(l<=r)
       {  mid=(l+r)/2;
          if(a[mid]<=x && x<a[mid+1] )
           {return mid;}           
          else if (a[mid]>x && x<a[mid+1])
          { r=mid-1; }
          else
          { l=mid+1; }
       }
        return -1;
    }
int main()
{   int a[] = {31, 14, 4, 84, 6,17,95,2};
	int n = 8;
	cout << "Array before sort:\n";
	for (int i = 0; i < n; i++)
	   cout << a[i] << " ";
	sort(a,a+8);
	cout << "\nArray after sort:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	int num=77; 
	cout<<"\nElement to be searched:"<<num;
	int ans=bin(a,num,8);
	if(ans == -1)
	{ cout<<"\nElement not found";  }
	else
	{ cout<<"\nElement found at index:"<<ans; }
	 
	cout << "\n";
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ long long n,k;
	  cin>>n;
	  cin>>k;
	  int a[n];
	  for(int i=0;i<n;i++)cin>>a[i];
	  cout<<"\n";	
	  for(int i=0;i<n;i++)cout<<a[i]<<" ";
	   
	 int b[n];
	  int tmp=k-1;
      int cnt=0;
	  for(int i=0;i<n;i++)
	  {   if(cnt == 3  )
	      { tmp=(k*2)-1; 
		  	cnt=0;
		  }
		  if(a[tmp]=='\0')
		  { tmp--; }
		  b[tmp]=a[i];
		  cnt++;
	      tmp--;
	     // cnt++;
          //if(cnt == 3)
     }
	 cout<<"\n";	
	 for(int i=0;i<n;i++)cout<<b[i]<<" ";
	 
	}
	cout<<"\n";
	system("pause");
	return 0;
}
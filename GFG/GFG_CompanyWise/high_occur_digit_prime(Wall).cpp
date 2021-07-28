#include <iostream>
using namespace std;
bool isPrime(int n)
{  if(n<=1)
    return false;
   for(int i=2;i<n/2;i++)
   { if(n%i==0)
      {  return false;}
   }
  return true;  
}
void countdig(int a[],int temp)
{ while(temp>0)
  { int pos=temp%10;
    a[pos]=a[pos]+1;  
    temp=temp/10;
   }
}

int main() {
	int t; cin>>t;
	while(t--)
	{ int L,R;
	  cin>>L; cin>>R;
	  int a[10]; int maxprime=0;
	  for(int i=0;i<10;i++) a[i]=0;
	  for(int i=L;i<=R;i++)
	  { if(isPrime(i))
	     { countdig(a,i);  
	       if(maxprime<i)
	       { maxprime=i;}
	     }
	  }
	  int res=a[1],flag=0;
	  for(int i=0;i<10;i++)
	  { if(res!=a[i])
	    { flag=1;}  
	  }
	  
	  if(flag==0 && maxprime!=0)
	  {cout<<maxprime<<"\n";}
	  else if(flag==1)
	  { int max=0;int maxdig=0;
	    for(int i=0;i<10;i++)
	    { if(max<a[i])
	       { max=a[i];
	         maxdig=i;    
	       } 
	    }
	    cout<<maxdig<<"\n";  
	  }
	  else if(maxprime==0)
	  { cout<<"-1\n";}
	}
	return 0;
}
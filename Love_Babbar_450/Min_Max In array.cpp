#include<iostream>

using namespace std;

int main() 
{  int a[]={ 1000, 11, 445,1, 330, 3000 ,-77};
   int n=sizeof(a)/sizeof(a[0]);
    cout<<"Size:"<<n;
    int max=a[0];
    int min=a[0];
    for(int i=1;i<n;i++)
    { if(a[i]>max)
      {max=a[i];}
      if(a[i]<min)
      {min=a[i];}
      }
    cout<<"\nMinimum:"<<min<<"\nMaximum:"<<max;
    system("pause");
    return 0;
} 
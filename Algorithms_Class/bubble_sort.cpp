#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

int main()
{   
  int a[]={31,14,84,4,6,17,89,147};
  int n=0,t;
  cout<<"Array before sort:\n";
  for(int i=0;i<8;i++)
  cout<<a[i]<<" ";
  for(int i=0;i<8;i++)
   for(int j=0;j<8-i;j++)
    { if(a[j]>a[j+1])
       { t=a[j];
         a[j]=a[j+1];
         a[j+1]=t;
       }    
    }
  cout<<"\nArray after sort:\n";
  for(int i=0;i<8;i++)
  cout<<a[i]<<" ";
  cin.get();

}
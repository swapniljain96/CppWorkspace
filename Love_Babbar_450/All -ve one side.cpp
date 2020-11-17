#include<bits/stdc++.h>

using namespace std;
void rearrange(int a[],int n)  
{ int j=0;
  for(int i=0;i<n;i++)
  { if(a[i]<0)
     { if(i!=j)
         { swap(a[i],a[j]); }
       j++;
     }
  }
}
void printArray(int arr[],int n)
{ for(int i=0;i<n;i++)
   {cout<<arr[i]<<" ";}
}

int main() 
{   int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before Rearrange:";
    printArray(arr, n);
    cout<<"\n";
    rearrange(arr, n);
    cout<<"\n";
    cout<<"After Rearrange: ";
    printArray(arr, n);
    system("pause");
    return 0;
} 
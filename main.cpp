#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) 
{ return x < y ? x : y; } 
    
int max(int x, int y) 
{ return x > y ? x : y; } 
    
long long int maxSubProduct(int a[],int n) 
    {  long long int maxeh = 1,mineh = 1,msf = 1,flag = 0; 
       for (int i = 0; i < n; i++) { 
            if (a[i] > 0) { 
                maxeh = maxeh * a[i]; 
                mineh = min(mineh * a[i], 1); 
                flag = 1; 
            } 
             else if (a[i] == 0) { 
                maxeh = 1; 
                mineh = 1;  } 
            else { 
                long long int temp = maxeh; 
                maxeh = max(mineh * a[i], 1); 
                mineh = temp * a[i]; } 
            if (msf < maxeh) 
                msf = maxeh; 
        } 
        if (flag == 0 && msf == 1) 
            return 0; 
        return msf; 
    } 
  
int main() 
{  int a[] = { 9,5,3,-4,8,-6,10,-11,52,-20,4,-30,89}; 
    int n= sizeof(a) / sizeof(a[0]); ;
    cout<<"\n\nMaximum Subarray product is: "<<maxSubProduct(a,n); 
    return 0;
} 
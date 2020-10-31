#include <iostream> 
#include<stdlib.h>
  
using namespace std; 
   
int main() 
{   int n=0,x=-10,y=100;
    int a[n][n] = { { -8, -2, -1, 0 , 4   }, 
                    {  3,  8, 15, 25, 26  }, 
                    {  5,  9, 23, 34, 41  }, 
                    { 14, 18, 33, 49, 51  }, 
                    { 22, 29, 59, 75, 100 } 
                  }; 
    for(int i=0;i<5;i++)
    { for(int j=0;j<5;j++)
        { cout<<a[i][j]<<" ";}
        cout<<"\n";
    }
    
    int temp;
    int a1,a2,b1,b2;
    if (n == 0) 
        { cout<<"Dimensions 0 matrix is given.";     } 
    
        
    else if (x < smallest || y > largest) 
       { cout<<"Given numbers are out of limit.";     }

    else 
    { for(int r=0;r<2;r++){
        if(r==0) { temp=x;}

        if(r==1) { temp=y;}
     /*if(a[mid]<=x && x<a[mid+1] )
           {return mid;}           
          else if (a[mid]>x && x<a[mid+1])
          { r=mid-1; }
          else
          { l=mid+1; }*/
     // set indexes for top right element 
    int i = 0, j = n - 1;  
    while (i < n && j >= 0) { 
        if (a[i][j] == temp) { 
            //cout << "Number "<<temp<<" found at :"<< i << ", " << j;
            if(r==0) { a1=i; b1=j;}
            if(r==1) { a2=i; b2=j;}
          }  
        if (a[i][j] > temp) 
            j--; 
        else  
            i++; 
    }
    } 
    
     cout<<"\nNumber "<<x<<" found at :"<< a1 << ", " << b1;
     cout<<"\nNumber "<<y<<" found at :"<< a2 << ", " << b2;

     
    cout << "\n\nFinal Requested array is:\n";
    for(int i=a1;i<=a2;i++)
    { for(int j=b1;j<=b2;j++)
        { cout<<a[i][j]<<" ";}
        cout<<"\n";
    }
    }
    cout<<"\n";
    system("pause");
    return 0; 
} 
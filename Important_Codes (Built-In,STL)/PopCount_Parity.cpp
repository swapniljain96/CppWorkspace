#include <iostream>
using namespace std;
int count_setbits(int N)
{ int cnt=0; 
  while(N>0)
  { cnt+=(N&1);
    N=N>>1;
  }
   return cnt;
}
int main() 
{ 
    int num = 23; 
    int clz = 0; 
    int ctz = 0; 
    int pop = 0; 
    int parity = 0; 
    
    //
    pop = __builtin_popcount(num); 
    cout<<"\nNumber of one's in "<<num<<" is: "<<pop; 

    int cnt=count_setbits(num);
    cout<<"\nNumber of one's in "<<num<<"by using count set bits function is: "<<cnt; 
  
    parity = __builtin_parity(num); 
    cout<<"\nParity of "<<num<<" is: "<<parity; 
  
    clz = __builtin_clz(num); 
    cout<<"\nNumber of leading zero's in"<<num<<" is: "<<clz;
    
  
    // It only works for unsigned values 
    clz = __builtin_clz(-num); 
    cout<<"\nNumber of leading zero's in"<<-num<<" is: "<<clz;
  
    ctz = __builtin_ctz(num); 
    cout<<"\nNumber of trailing zero's in"<<num<<" is: "<<ctz;
     
    cout << "\n";
    system("pause");
    return 0;
} 
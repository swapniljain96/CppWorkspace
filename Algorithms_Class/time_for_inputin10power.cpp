#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
struct Timer
{ 
  std::chrono::high_resolution_clock::time_point start ,end;
  std::chrono::duration<float> dura; 

  Timer()
  { 
     start =std::chrono::high_resolution_clock::now(); 
  }
 
  ~Timer()
  {   end =std::chrono::high_resolution_clock::now();
      dura=end-start;

      float ms= dura.count()*1000.00f;
      std::cout<<"Timer took"<<ms<<"ms"<<endl;
  }
};

void Function()
{ Timer timer;
    int i,j,k,n,s;
 n=10000;s=2;
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
  for(k=0;k<1000;k++)
   s=2*s+1;

cout<<s<<"\n";
}

int main()
{   
   Function();
   system("pause");
   return 0;
}
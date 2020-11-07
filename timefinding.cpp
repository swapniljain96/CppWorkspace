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
  
  for(int i=0;i<100;i++)
   { cout<<"Hello\n";}

}
int main()
{   
   Function();
  cin.get();
}

/*
void fastio(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
int main(){
	fastio();
}
*/
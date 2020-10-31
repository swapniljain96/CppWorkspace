#include <iostream>
#include<map>
template <typename type>
struct mycomp
{
  bool operator()(const type &first,const type &second ) const{
      return first>second;
  }
  
};

using namespace std;
int main() 
{ 
   map<int,string,mycomp<int>> mp;
   mp.insert(make_pair(10,"abc"));
   mp.insert(make_pair(30,"def"));
   mp.insert(make_pair(20,"xyz"));
   
   std::cout<<"In Map Using greater library function Comparater\n";
   for(auto &ele:mp)
   {   std::cout<<ele.first<<"--"<<ele.second<<endl; }
 
   map<int,string,less<int>> lmp;
   lmp.insert(make_pair(10,"abc"));
   lmp.insert(make_pair(30,"def"));
   lmp.insert(make_pair(20,"xyz"));
   
   std::cout<<"In Map Using bydefault/less library function Comparater\n";
   for(auto &ele:lmp)
   {   std::cout<<ele.first<<"--"<<ele.second<<endl; }
  
   system("pause");
   return 0;
}
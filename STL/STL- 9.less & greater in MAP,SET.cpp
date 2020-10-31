#include <iostream>
#include<map>
#include<set>

using namespace std;
int main() 
{  //in Map
   map<int,string,greater<int>> mp;
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
 

   
   
   
   
   
   // in Sets
   std::cout<<"In SETS Using bydefault/less library function Comparater\n";
   set<int,less<int>> st;
   st.insert(17);st.insert(23);st.insert(3);st.insert(40);st.insert(90);
   for(auto &ele: st)
   {   std::cout<<ele<<endl;}

   std::cout<<"In SETS Using greater library function Comparater\n";
   set<int,greater<int>> gst;
   gst.insert(17);gst.insert(23);gst.insert(3);gst.insert(40);gst.insert(90);
   for(auto &ele: gst)
   {   std::cout<<ele<<endl;}

   
   system("pause");
   return 0;
}
#include <iostream>
#include<map>
#include<set>

using namespace std;

//Set:Assocaiotive Containers.. Just like Maps
//have only one value(Key as value) 

int main() 
{ // Sets
   set<int> st;
   st.insert(100);st.insert(200);st.insert(300);st.insert(40);st.insert(90);
   for(auto &stvl: st)
   {   std::cout<<stvl<<endl;}

   st.erase(100);
   st.erase(st.begin());
   for(auto &stvl: st)
   {   std::cout<<stvl<<endl;}


    //MultiSet
    std::cout<<"Multiset\n";
    
    multiset<int> mst;
    mst.insert(10);mst.insert(40);mst.insert(10);mst.insert(150);mst.insert(10);
    for(auto &stvl: mst)
   {   std::cout<<stvl<<endl;}


   system("pause");
   return 0;
}
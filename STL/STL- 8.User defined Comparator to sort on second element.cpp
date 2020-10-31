#include <iostream>
#include<set>
template <typename type>
struct mycomp
{
  bool operator()(const type &first,const type &second ) const{
      return first.second>second.second;
  }
  
};

using namespace std;
int main() 
{ 
  std::cout<<"By using primitive comparator to sort on 1st key\n";  
  set <pair<int,int>,greater<pair<int,int>>> st;
  st.insert({40,10});   st.insert({20,200});    st.insert({30,250}); 
  for(auto &i: st)
  { std::cout<<i.first<<"--"<<i.second<<endl; }
 
  std::cout<<"By using user-def comparator to sort on 2nd key\n";  
  set <pair<int,int>,mycomp<pair<int,int>>> cst;
  cst.insert({40,10});   cst.insert({20,200});    cst.insert({30,250}); 
  for(auto &i: cst)
  { std::cout<<i.first<<"--"<<i.second<<endl; }
 system("pause");
   return 0;
}
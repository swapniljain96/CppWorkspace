#include <iostream>
#include<vector>
#include<forward_list>
#include<algorithm>
#include<numeric>

using namespace std;
//Functional Programming with Map(),Filter() and Reduce()
int main() 
{   
    //map - tranform
    vector<int> v {1,2,3,4,5,6,7};
    //vector<int> vout(v.size());  /////// v.size() is to assign the size to vout vector

    vector<int> vout;  //back_inserter(vout) does is that it calls the push back
                       //so it can be use with only container that have push back 
    
    //map
    transform(v.begin(),v.end(),back_inserter(vout),[](int & value ) {return value*4; });
     for(auto &i:v)
    {   std::cout<<" "<<i;}
    
     std::cout<<"\n ";
    for(auto &i:vout)
    {   std::cout<<i<<endl;}
    system("pause");
    return 0;
}
#include <iostream>
#include<map>
#include<algorithm>

using namespace std;

int main()
{   
    //how to use pair <key,zalue>
    pair<int,int> p=make_pair(10,20);
    std::cout<<"Pair Test:"<<p.first<<"--"<<p.second<<"\n"<<endl;
    /////////////////////////////////////////////////////////////////
    //map<key,zalue>
    map<int,int> mp;
    mp[4]=400;
    mp[3]=300;
    mp.insert(make_pair(10,100));
    //mp.insert(make_pair(10,700)); here this will no work as key 10

    mp[10]=500;//this will ozer write the prezious 10 zalue to 500
   //iterate  
   for(auto it=mp.begin();it!=mp.end();it++)
    {  std::cout<<it->first<<"--"<<it->second<<endl;   }

    multimap<int,int> mmp;
    
    //mmp[10]=446  does not work here bcoz it doesnt know which 10 to update
    mmp.insert(make_pair(4,4000));
    mmp.insert(make_pair(10,1000));
    mmp.insert(make_pair(3,3000));
    mmp.insert(make_pair(10,8000));
    mmp.insert(make_pair(10,7000));
    
    for(auto it=mmp.begin();it!=mmp.end();it++)
        {  std::cout<<it->first<<"--"<<it->second<<endl;   }

    system("pause");
    return 0;
}
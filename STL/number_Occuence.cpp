#include<bits/stdc++.h>

using namespace std;

int main() 
{  vector<int> a;
   a.push_back(1);
   a.push_back(2);
   a.push_back(3);
   a.push_back(3);
   a.push_back(3);
   a.push_back(3);
   a.push_back(3);
   a.push_back(4);
   a.push_back(5);
   a.push_back(5);
   a.push_back(5);
   a.push_back(5);
   for(auto i=a.begin();i!=a.end();i++)
   {cout<<" "<< *i;}
   auto i1=lower_bound(a.begin(),a.end(),5);
   auto i2=upper_bound(a.begin(),a.end(),5);
    
    cout<<"\nOccurence:"<<i2-i1;
   
    system("pause");
    return 0;
} 
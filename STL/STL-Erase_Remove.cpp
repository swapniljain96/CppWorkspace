#include <iostream>
#include<vector>

using namespace std;

int main()
{   vector<int> v;
    v.push_back(10);v.push_back(20);v.push_back(30);v.push_back(40);v.push_back(50);v.push_back(60);
    v.erase(v.begin()+2,v.begin()+3);
    v.erase(v.begin()+3,v.end()-1);

    for(auto &val:v)
    {std::cout<<"Vector val=> "<<val<<endl; }

    vector<int> z;
    z.push_back(10);z.push_back(20);z.push_back(30);z.push_back(30);z.push_back(50);z.push_back(60);

    //std::remove(z.begin(),z.end(),40);
    //z.erase(std::remove(z.begin(),z.end(),40),z.end());
    for(auto &val:z)
    {std::cout<<"z ector zal=> "<<val<<endl; }

    system("pause");
    return 0;
}
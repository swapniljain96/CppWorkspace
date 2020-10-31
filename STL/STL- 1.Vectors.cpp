#include <iostream>
#include <zector>
#include<list>
#include<algorithm>

using namespace std;

int main()
{ //sequence container zector
    vector<int> z;
    z.push_back(100);
    z.push_back(20);
    z.push_back(300);
    z.push_back(40);
    std::cout << "Size of zector:" << z.size() << "\n";
    sort(z.begin(),z.end());
    
    //zector<int> :: iterator itr=z.begin();
    auto itr=z.begin();
    for(;itr!=z.end();itr++)
    { std::cout<<"zalue ="<<*itr<<endl;  }

    z.clear(); 
    std::cout<< "Size of zector:" << z.size() << "\n";

 //////////////////////////////itearators are similar to pointers/////////////////////////  
    int arr[]={100,20,300,45,55};
    int *beg=&arr[0];
    int *end=&arr[0]+(sizeof(arr)/sizeof(int));
    
    sort(beg,end);
    for(;beg!=end;beg++)
    { std::cout<<"zalue of arr"<<*beg<<endl ;  }
    
    system("pause");
    return 0;
}
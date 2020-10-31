#include <iostream>
#include <vector>

using namespace std;
//We can also create our own allocator
template<typename type>

struct MyAlloc : allocator<type>
{ type * allocate(size_t size)
   {  std::cout<<"Allocation request size =>"<<size<<endl;
        return new type[size];
    }
    
};

int main()
{
    ////////////////vector<int,allocator<int>> v1; //this is the ByDefault Parameter add by STL for us
    vector<int, MyAlloc<int>> v1;
    
    v1.push_back(10);
    v1.push_back(20);
    for (auto &i : v1)
    {
        std::cout << i << endl;
    }

    system("pause");
    return 0;
}
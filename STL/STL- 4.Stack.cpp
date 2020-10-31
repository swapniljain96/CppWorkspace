 #include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>

using namespace std;

//STL Containers Adapters: Stack,Queue & Priority Queue
int main() 
{   
    // stack<int,deque<int>> stk;------  Stack as a deque  ByDefault
    // stack<int,vector<int>> stk;-----  Stack as a vector
    // stack<int,list<int>> stk;-----    Stack as a Linked List
    
     stack<int> stk;
     stk.push(100);  stk.push(200);  stk.push(300);
     while(!stk.empty())        //while(stk.size()!=0)   
    {
        std::cout<<stk.top()<<endl;
        stk.pop();
    }
  
    system("pause");
    return 0;
}
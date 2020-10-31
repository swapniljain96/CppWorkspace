#include <iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>

using namespace std;

//STL Containers Adapters: Stack,Queue & Priority Queue
int main() 
{   
    // queue<int,deque<int>> stk;------  Queue as a deque  ByDefault
    // queue<int,list<int>> stk;-----    Queue as a Linked List
    
    // queue<int,vector<int>> stk;----- this can't use 
    
    queue<int> que;
    que.push(100);  que.push(200);  que.push(300);
     while(!que.empty())        
     {
        //std::cout<<que.front()<<endl;
        std::cout<<que.back()<<endl;
        
        que.pop();
    }
  
    system("pause");
    return 0;
}
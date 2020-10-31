#include <iostream>
#include<stack>
#include<queue>

using namespace std;

//STL Containers Adapters: Stack,Queue & Priority Queue
int main() 
{   
    // queue<int,deque<int>> stk;------  Queue as a deque  ByDefault
    // queue<int,vector<int>> stk;-----  Vectors as a deque  ByDefault
    
    //priority_queue<int,vector<int>,std::greater<int>> que;

    priority_queue<int> que;
    que.push(100);  que.push(30);  que.push(400);   que.push(117);  que.push(537);
    
    while(!que.empty())        
     {
        std::cout<<que.top()<<endl;
        que.pop();
    }
  
    system("pause");
    return 0;
}
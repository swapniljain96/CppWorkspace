#include<iostream>
 
using namespace std;
int n,x,y,front=0,rear=1,val;
int arr[100001];
struct point
{ int num,dist; };

point queue[1000001]; int bfs()
{   queue[front]={x,0};
    int visited[n+1];
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    visited[x]=1;
    point p1;
    while(front!=rear)
    {
        p1=queue[front++];
         int num=p1.num;
 
       int dist=p1.dist;
  if(num==y)
  return p1.dist;
      //break                               // 2 2 4 4 3 
    int t1,t2;                 // 1 2 3 4 5     
        arr[num]=arr[num]%n;
        
        if(num+arr[num]<=n)
        t1=num+arr[num];
        else
        t1=(arr[num]-(n-num));  //  3 4 5 4 3
        if(num-arr[num]>=1)     //  1 2 3 5 6
        t2=num-arr[num];
        else
        t2=(n-(arr[num]-num));
        
        
    if(visited[t1]==0)
    {
        visited[t1]=1;
        queue[rear++]={t1,dist+1};
        
    }
    if(visited[t2]==0)
    {
        visited[t2]=1;
        queue[rear++]={t2,dist+1};
    }   
 }
 return -1; 
    
}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {cin>>n>>x>>y;
     front=0;
     rear=1;
        for(int i=1;i<=n;i++) { cin>>arr[i];  }
       cout<<bfs()<<endl;
    }   
}
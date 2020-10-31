#include <bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;
void func(vector<int> &t,char &rnd)
{  int ecnt=0;
  for(auto i=t.begin();i!=t.end();i++)
  {   if(*i%2 == 0)
       { ecnt++; }
  }
  
  t.clear();
  int bval,jval;
  
  if(rnd=='B')
  { bval=ecnt;
    jval=0;
  }
  else
  { jval=ecnt;
    bval=0;
  }
  
  if(jval==bval)
  { cout<<"Ben";}
  
  if(jval>bval)
  {cout<<"Jim";}
  if(jval<bval)
  {cout<<"Ben";}
}

int main()
{
  int T,s,temp;
  char rnd;
  vector<int> t;
  cin>>T;
  for(int i=0;i<T;i++)
  { if(i%2==0)
     { rnd='B';}
    else
     { rnd='J';}
    cin>>s;
    for(int i=0;i<s;i++)
     {  cin>>temp;
        t.push_back(temp);
     }
    func(t,rnd);
  }
  
  return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int ben = 0, jim = 0;
    while(n > 0){
      int val, val2;
      cin>>val;
      if(val%2 == 0)
        ben++;
      n--;
      if(n > 0){
        cin>>val2;
        if(val2%2 == 0)
        jim++;
      }
      n--;
    }
    if(ben >= jim)
      cout<<"Ben\n";
    else
      cout<<"Jim\n";  
  }
  
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

string winner(int n, int arr[])
{
  
  
  vector <int> v_b;
  vector <int> v_j;
  for(int i = 0; i < n; i+=2)
  {
    if(arr[i] % 2 == 0)
      v_b.push_back(arr[i]);
  }
  for(int i = 1; i < n; i+=2)
  {
    if(arr[i] % 2 == 0)
      v_j.push_back(arr[i]);
  }
  if(v_b.size() >= v_j.size())
    return "Ben";
  else
    return "Jim";
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
      cin >> arr[i];
    cout << winner(n, arr) << endl;
  }
  
  return 0;
}*/

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int t,n,m,p,jim,ben; 
  //write your code here
  cin>>t;
  while(t--)
  {
    cin>>n;
    p=0;
    ben=0;
    jim=0;
    while(n--)
    {
      cin>>m;
      
      if(m%2==0)
      {
      if(p%2==0)
      {
        ben++;
      }
      else
      {
        jim++; 
      } }
      p++;
      
    }
    if(jim<ben) cout<<"Ben"<<"\n";
    else if(jim>ben) cout<<"Jim"<<"\n";
    else cout<<"Ben"<<"\n";
  }
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  //write your code here
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,s1=0,s2=0;
    ll i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>x;
      if(i%2==0 && x%2==0)
      s1++;
      
       if(i%2!=0 && x%2==0)
        s2++;
    }
    if(s1>=s2)
    cout<<"Ben"<<endl;
    else
    cout<<"Jim"<<endl;
  }
  return 0;
}*/
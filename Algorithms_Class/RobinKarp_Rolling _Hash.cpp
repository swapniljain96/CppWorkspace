#include<iostream>
#include<vector>
using namespace std;
int func(vector<int> &t,vector<int> &p,int base)
{ 
  int tval=0,pval=0,i=0,flag=0,power=1;
  int m=p.size(),q=7;
  for(i=0;i<m;i++)
    {  pval=((pval*2) + p.at(i)%q); 
       tval=((tval*2) + t.at(i)%q);
       power=power*2;
    }
    
    while(i<t.size())
    { if(pval==tval)
        { flag=1;
          break;  
        }
      else
      { tval=(tval*2+t.at(i))- (t.at(i-m)*power) ;
        i++;
      } 
    }

    if(pval==tval||flag == 1)
    {return 1;}
    else
    {
      return 0;
    }  
}

int main()
{  vector<int> t={1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,0},p={1,1,1,1,1};
    int res=func(t,p,base);
    if(res==1)
    { cout<<"Substring Present\n"; }
    else
    { cout<<"Substring Absent\n"; }
     cin.get();
   
}
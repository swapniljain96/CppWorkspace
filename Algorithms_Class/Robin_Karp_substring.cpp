#include<iostream>
#include<vector>
using namespace std;
int func(vector<int> &t,vector<int> &p,int base)
{ 
  int tval=0,pval=0,i=0,flag=0,power=1;
  int m=p.size();
  for(i=0;i<m;i++)
    {  pval=(pval*base) + p.at(i); 
       tval=(tval*base) + t.at(i);
       power=power*base;
    }
    
    while(i<t.size())
    { if(pval==tval)
        { flag=1;
          break;  
        }
      else
      { tval=(tval*base+t.at(i))- (t.at(i-m)*power) ;
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
{  //vector<int> t={1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,0},p={1,1,1,0}; 
   vector<int> t={10,7,8,9,4,5,23,21,6,17,20,13,40,31},p={10,7,8,77}; 
   int base=0,res;
   cout<<"Enter the base value of the numerical string:";
   cin>>base;
   
    res= func(t,p,base);
    if(res==1)
    { cout<<"Substring Present\n"; }
    else
    { cout<<"Substring Absent\n"; }
     
     system("pause");
     return 0;
}
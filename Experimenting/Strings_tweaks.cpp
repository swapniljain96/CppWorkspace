#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{   string ss[2];
    ss[0]="Swapnil";
    ss[1]="Jain";
    for(int i=0;i<ss.size();i++)
    {  cout<<ss[i];  }
 
    /*string ss,src; 
    cout<<"Enter your string:";           // to find substring in a given string
    std::cin>>ss;
    std::cout<<"Your string is:"<<ss<<endl;
    std::cout<<"Enter substring you want to find its there or not:";
    std::cin>>src;           
    bool res=ss.find(src)!=string::npos;
    if(res==1)
    { cout<<"Your string is present:"<<endl;  }
    else
    { cout<<"Your string is absent:"<<endl;   }  */
    
    

    /*vector<string> v ={"abc","abgr","abklm"};
    minl=v[0].size();
    for(int i=0;i<v.size();i++)
    {   if(maxl<v[i].size())
        { maxl=v[i].size();  }
        if(minl>v[i].size())
        { minl=v[i].size();  }
    }
    cout<<"Maximum String length:"<<maxl<<endl;
    cout<<"Minimum String length:"<<minl<<endl;
    if(v[0].at(0)==v[1].at(0) && v[1].at(0)==v[2].at(0))
    {  cout<<"First letter of all strings are same."<<endl; } 
    */
    /*cout<<"Enter your string:";           // to input the string by cin in string variable
    cin>>ss;
    cout<<"Your string is:"<<ss<<endl;*/

    /*cout<<"Enter your string:";
    while(1)
    {   cin>>ss;
        v.push_back(ss);                     // to input the string in vector
        if(ss=="!")
        {break;} 
              
    }

    cout<<"Your string is:";
    for(int i=0;i<v.size();i++)
    { cout<<v[i];      }
     cout<<"\n";*/

    /*v.push_back("dog");
    v.push_back("cat");                             //String find in vector
    v.push_back("mouse");
    v.push_back("tiger");

    auto i=find(v.begin(),v.end(),"vvdog");
    
    if(i!=v.end())
    { cout<<"String: "<<*i<<" found"<<endl;}
    else
    {cout<<"String not found"<<endl; }*/

   /* string name= string("Swapnil")+"Jain";
    bool con=name.find("nil")!=string::npos;
    if(con)
    { cout<<"SubString Present "; }
    else
    {    cout<<"Substring not present";  }
    

    bool con= ss.find(subs)!=string::npos;
    
    cout<<con<<endl; */
    
    system("pause");
    return 0;
    
}

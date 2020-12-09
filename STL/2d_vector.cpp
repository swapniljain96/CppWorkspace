#include<bits/stdc++.h>

using namespace std;

int main() 
{  //Method 1
   vector<vector<int>> a;
    for(int i=0;i<3;i++)
     { vector<int> t;
      for (int j=0; j < 2; j++)
        { t.push_back(i); } 
       a.push_back(t); 
     }
    for(int i=0;i<a.size();i++)
     { for (int j=0; j < a[i].size(); j++)
        { cout<<a[i][j]<<" "; }
        cout<<"\n";
     }
    cout<<"\nNo. of Rows:"<<a.size();
    cout<<"\nNo. of Columns:"<<a[0].size();

    //Method 2
    int r=4;
    int c=5;
    vector<vector<int>> m2;
    m2.resize(r,vector<int> (c));
     for(int i=0;i<3;i++)
     { for (int j=0; j < 2; j++)
        { m2[i][j]=rand()%100+1; } 
     }
     for(int i=0;i<m2.size();i++)
     { for (int j=0; j <m2[i].size(); j++)
        { cout<<m2[i][j]<<" "; }
        cout<<"\n";
     }
    cout<<"\nNo. of Rows:"<<m2.size();
    cout<<"\nNo. of Columns:"<<m2[0].size();
    system("pause");
    return 0;
} 
#include<bits/stdc++.h>

using namespace std;

int main() 
{  vector<vector<int>> a;
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
    system("pause");
    return 0;
} 
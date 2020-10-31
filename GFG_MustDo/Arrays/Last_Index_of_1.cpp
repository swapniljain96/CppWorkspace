#include <bits/stdc++.h>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    { string ss;
      cin>>ss;
      cout<<"String is:"<<ss<<"\n";
      cout<<"String size:"<<ss.size()<<"\n";
      for(int i=ss.size();i>=0;i--)
      { if(ss[i]=='1')
        {   cout<<i<<"\n";
            break;
        }
      }
    }
    cout << "\n";
	system("pause");
	return 0;
}

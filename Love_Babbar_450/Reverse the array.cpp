// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	cout << reverseWord(s) << endl;
	}
    cout<<"\n";
	system("pause");
    return 0;
} 

// } Driver Code Ends

string reverseWord(string str){
    int n=str.size();
    cout<<"\nString size:"<<n<<"\n";
    int start=0;
    int end=n-1;
    if(n%2==1)
    { for(int i=start,j=end;i<=(n/2);i++,j--)
      { char c;
        c=str[i];
        str[i]=str[j];
        str[j]=c;
      }
    }
    if(n%2==0)
    { for(int i=start,j=end;i<=(n/2)-1;i++,j--)
      { char c;
        c=str[i];
        str[i]=str[j];
        str[j]=c;
      }
    }
    
    return str;
  }


/*//User function Template for C++

string reverseWord(string str){
    string ss;
    for(string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
     {ss=ss+(*rit);}
     return ss;
  
}*/
// https://www.hackerrank.com/challenges/sum-vs-xor/editorial

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the sumXor function below.
long sumXor(long n) {
     long c = 0;
    while(n){
     c += n%2?0:1;  //This runs perfectly fine
     n/=2; 
    }
   c=pow(2,c);
  return c;
    
    /* int cnt=0;           my method take O(n) time but we need O(logn) or O(1)
    for(int i=0;i<n;i++)
    { if((n+i)==(n^i))
      { cnt++;}
      else {
      continue;
      }
    }   
    return cnt; */
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

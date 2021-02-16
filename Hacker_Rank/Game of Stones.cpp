// https://www.hackerrank.com/challenges/game-of-stones-1/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.
string gameOfStones(int n) {
    if (n>=7)
    { n=n%7; }
    if(n==0||n==1)
    { return "Second";}
    else 
    { return "First";}
   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;x`
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() 
{ 
 string myString = "10 15 20 23";
 stringstream iss( myString );
 int number;
 std::vector<int> myNumbers;
 while ( iss >> number )
  {  myNumbers.push_back( number ); }
   
    cout<<"\n";
    systyem("pause");
    return 0;
} 
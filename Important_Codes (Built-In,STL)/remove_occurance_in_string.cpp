// https://www.geeksforgeeks.org/remove-all-occurrences-of-a-character-from-a-string-using-stl/
// C++ program of the above approach 
#include <algorithm> 
#include <iostream> 
using namespace std; 

// Function to remove all occurences 
// of C from the string S 
string removeCharacters(string S, char c) 
{ 

	S.erase(remove( 
				S.begin(), S.end(), c), 
			S.end()); 

	return S; 
} 

// Driver Code 
int main() 
{ 

	// Given String 
	string S = "GFG is Fun"; 
	char C = 'F'; 
	cout << "String Before: " << S << endl; 

	// Function call 
	S = removeCharacters(S, C); 

	cout << "String After: " << S << endl; 
	return 0; 
} 

// Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
// Sample Input:
// [3 4 1 4 1]
// Sample Output:
// 1
// If there are multiple possible answers ( like in the sample case above ), output any one.
// If there is no duplicate, output -1

// Method 1 Cycle finding algorithm
int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    if(n==1) 
        return -1;
    //The basic approach used is of finding cycle in an array
    int slow=A[0];
    int fast=A[0];
    //We have taken 2 variables slow will move 1 step ahead and access element at slow position
    //while fast will move 2 steps ahead and access element at A[fast] position
    int count=0;
    //Count is used to prevent the infinite loop
    do{
        slow=A[slow];
        fast=A[A[fast]];
        count++;
    }while(slow!=fast && count<n);
    //If I have traversed n times then I know there is no duplicate
    if(count==n) 
        return -1;
    //Else I will find the number by finding the starting point of the cycle
    fast=A[0];
    while(slow!=fast){
        slow=A[slow];
        fast=A[fast];
    }
    return slow;
}


// Method 2 Using Pigeon Hole Principle
TC=O(n) SC=O(n) //here uses vector by accepts bcoz space of vector is less then map/set
int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> v(A.size(), 0);
    for(int x:A)    {
        v[x]++;                    
        if(v[x]==2) return x;  // here we uses Pigeon Hole Principle means if any number occurs
    }                          // twice then its cell value will be 2
}


// Method 3 Using Set
TC=O(n) SC=O(n) //not accepts due to SC contraints
int Solution::repeatedNumber(const vector<int> &a) {
    int ans;
    for(int x:a)
    {  if(s.find(x)==s.end())
        s.insert(x);
        else
        { ans=x;
         break; }
    }
    return ans;
}

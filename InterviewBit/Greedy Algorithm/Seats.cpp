/* There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

Example

Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -

              . . . . x . . x x . . . x . .

Now to make them sit together one of approaches is -
                  . . . . . . x x x x . . . . .

Following are the steps to achieve this -
1 - Move the person sitting at 4th index to 6th index -  
    Number of jumps by him =   (6 - 4) = 2

2 - Bring the person sitting at 12th index to 9th index - 
    Number of jumps by him = (12 - 9) = 3

So now the total number of jumps made = 
    ( 2 + 3 ) % MOD = 
    5 which is the minimum possible jumps to make them seat together.

There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.

For example bring them all towards the starting of the row i.e. start placing them from index 0. 
In that case the total number of jumps will be 
    ( 4 + 6 + 6 + 9 ) % MOD 
    = 25 which is very costly and not an optimized way to do this movement */

// Main Idea behind solution.
// we have to pick a seat number p and all person will seat close to this seat number
// So, cost for a person intially sitting at x will be abs(p-x). // abs as x may be left of p or right of p.
// So, total error = sum(p-x) for each x.
// Now the concept of median comes in picture. Median is a point separates the two halves of data,
// So, if we pick the point p as median of the all indices the sum(p-x) will be minimised.
// So, approach is to find median of indices and then calculate error for each person.

#define MOD 10000003
int Solution::seats(string A)
{
    vector<int> v;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == 'x')
            v.push_back(i);
    }

    int mid = floor(v.size() / 2);
    int cp = v[mid];
    //cp is median position index in the string A, all other
    //members should be seated attached to cp.
    //sum is number of jumps
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i];
        int end = cp - mid + i;

        sum = (sum + abs(end - start)) % MOD;
    }

    return sum;
}
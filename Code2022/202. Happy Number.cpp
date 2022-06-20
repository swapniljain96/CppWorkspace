/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false

Constraints:
1 <= n <= 231 - 1 */

// Using Set M1
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int num = 0;
            num = (n % 10);
            n = n / 10;
            sum = sum + (num * num);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        set<int> s;
        while (1)
        {
            int d = getSum(n);
            if (d == 1)
                return true;
            if (s.find(d) != s.end())
                return false;
            s.insert(d);
            n = d;
        }
        return false;
    }
};

//  using set M2
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int num = 0;
            num = (n % 10);
            n = n / 10;
            sum = sum + (num * num);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        set<int> s;
        while (s.find(n) == s.end())
        {
            s.insert(n);
            if (n == 1)
                return true;
            n = getSum(n);
        }
        return false;
    }
};

// Using Floyd Cycle Detection
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int num = 0;
            num = (n % 10);
            n = n / 10;
            sum = sum + (num * num);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = getSum(n);
        while (fast != slow && fast != 1)
        {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }
        return fast == 1;
    }
};
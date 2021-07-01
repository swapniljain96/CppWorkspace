// A car travels from a starting position to a destination which is `target` miles east of the starting position.

// Along the way, there are gas stations.  Each `station[i]` represents a gas station that is `station[i][0]` miles east of the starting position, and has `station[i][1]` liters of gas.

// The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

// When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

// What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return `-1`.

// Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &a)
    {
        priority_queue<int> fuel;
        a.push_back({target, 0});
        int reach = startFuel, ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            while (!fuel.empty() and reach < a[i][0])
            {
                ans++;
                reach += fuel.top();
                fuel.pop();
            }
            if (reach < a[i][0])
            {
                return -1;
            }
            fuel.push(a[i][1]);
        }
        return ans;
    }
};
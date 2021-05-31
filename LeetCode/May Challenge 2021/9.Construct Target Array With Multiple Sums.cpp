class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> q;
        long sum = 0;
        for (auto num : target) {
            q.push(num);
            sum += num;
        }
        
        while (q.top()!=1) {
            int curval = q.top();
            
            q.pop();
            
            long rest = sum - curval;
            
            if (rest == 0) return false;
            if (rest == 1) return true;
            if(rest >= curval) return false;

            rest = curval % rest;
            if (rest == 0) return false;
            
            sum = sum -(curval - rest);
            q.push(rest);
        }
        return true;
    }
};
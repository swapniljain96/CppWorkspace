class Solution {
    public:    
    int countPrimes(int n) {
      bool a[n+1];
      for (int i = 2; i < n; i++) { a[i] = true;  }
      
        for (int i = 2; i * i < n; i++) {
        if (!a[i]) continue;
        for (int j = i * i; j < n; j += i) {
             a[j] = false;
         }
    }
     int cnt = 0;
     for (int i = 2; i < n; i++) {
       if (a[i]) cnt++;
    }
   return cnt;}
};
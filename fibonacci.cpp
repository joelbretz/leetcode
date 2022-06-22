class Solution {
public:
    int fib(int n) {
       //F(0) = 0
       if(!n)
           return 0;
        
       //F(1) = 1, F(2) = 1
       if(n < 3)
           return 1;
       int a = 1, b = 1, prev;
        for(int i = 3; i <= n; ++i) {
            prev = a + b;
            a = b;
            b = prev;
        }
        return b;
    }
};

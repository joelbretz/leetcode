class Solution {
public:
    int tribonacci(int n) {
        
        if(!n)
            return 0;
        else if(n < 3)
            return 1;
        
        int a = 0, b = 1, c = 1, v ;
        for(int i = 3; i <= n ; ++i) {
            v = a + b + c;
            a = b;
            b = c;
            c = v;
        }
        return c;
    }
};

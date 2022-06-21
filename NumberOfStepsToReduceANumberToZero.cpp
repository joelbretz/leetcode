class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num) {
            // odd, subract 1
            if((num & 0x1) == 0x1) { 
                --num;
            }
            else {
                num /= 2;
            }
            ++steps;
        }
        return steps;
    }
};

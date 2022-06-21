class Solution {
public:
    
    // naive solution, use mod.
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1; i <= n; ++i) {
            bool multOfThree = ((i % 3) == 0);// : true : false;
            bool multOfFive = ((i % 5) == 0);// : true : false;
            
            string t;
            if(multOfThree)
                t += "Fizz";
            if(multOfFive)
                t += "Buzz";
            
            if(t.empty())
                t += to_string(i);
            
            answer.push_back(t);
        }
        return answer;
    }
};

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
  int guessNumber(int n) {

    long lo = 1, hi = n, val;

    while(lo <= hi) {
      val = (lo + hi) / 2;
      auto response = guess(val);
      if( response == 0)
        return val;
      else if(response == -1) // number is higher
        hi = val - 1;
      else {
        lo = val + 1;
        
      } 
    }
    return -1;
  }
};

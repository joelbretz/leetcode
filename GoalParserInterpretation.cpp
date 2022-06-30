class Solution {
  public:

  // the straight forward, obv solution
  // opted for switch instead of long if/else
  string interpret(string command) {
    string parsed; int i = 0;
    while(i < command.length()) {
      char c = command[i];
      switch(c) {
        case 'G':
          parsed += "G";
          i+=1;
          break;
        case '(':
          if(command[i+1] == ')') {
            parsed += "o";
            i+=2;
          }
          else if(command[i+1] == 'a') {
            parsed += "al";
            i += 4;
          }
          break;
        default:
          i++;
          break;
      }
    }
    return parsed;
  }
};

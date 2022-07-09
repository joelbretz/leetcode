class Solution {
  public:

  // utility function:
  // obvious, basic implementation of atoi for string 
  long getNum(string s) {
    long a = 0, b = 1;
    for(int i = s.length() - 1; i >= 0; i--) {
      a += (s[i] - '0') * b;
      b *= 10;
    }
    return a;
  }
  // utility function:
  // same comment as above except to_string()
  // actually worse though. i use string as stack then reverse it
  string convertString(long long val) {
    string output;
    int n;
    if(!val) return "0";
    while(val){
      n = val % 10;
      output.push_back(n + '0');
      val /= 10; 
    }
    reverse(output.begin(), output.end());
    return output;
  }

  // this is the "long int" version from like late 2nd semester CS:
  // Multiplies str1 and str2, and prints result.
  string multiply(string num1, string num2)
  {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
      return "0";

    vector<int> result(len1 + len2, 0);

    // Below two indexes for ind positions in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--) {
      int carry = 0;
      int n1 = num1[i] - '0';

      // To shift position to left after every
      // multiplication of a digit in num2
      i_n2 = 0;

      // Go from right to left in num2            
      for (int j=len2-1; j>=0; j--) {
        // Take current digit of second number
        int n2 = num2[j] - '0';

        // Multiply with current digit of first number
        // and add result to previously stored result
        // at current position.
        int sum = n1*n2 + result[i_n1 + i_n2] + carry;

        // Carry for next iteration
        carry = sum/10;

        // Store result
        result[i_n1 + i_n2] = sum % 10;

        i_n2++;
      }

      // store carry in next cell
      if (carry > 0)
        result[i_n1 + i_n2] += carry;

      // To shift position to left after every
      // multiplication of a digit in num1.
      i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
      i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
      return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
      s += std::to_string(result[i--]);

    return s;
  } 

  // parse the strings then roll.
  // this works until the product cant fit into long long.
  string multiplyLL(string num1, string num2) {
    long val1 = getNum(num1), val2=getNum(num2); 

    long long product = val1 * val2;
    //cout << val1 << "*" << val2 << "=" << product << endl;
    //cout << (char)(val1 + '0') << "*" << (char)(val2 + '0') << "=" << product << endl;

    string o = convertString(product);
    //cout << o << endl;

    return o;
  }

  // disallowed solution using stringstream to convert
  // the inputs to integer directly.  #rebelalliance
  //    note: this is going explode past the easy/short testcases
  string multiplyRebel(string num1, string num2) {
    stringstream ss1(num1);
    stringstream ss2(num2);
    long long u, v, w;
    ss1 >> u; ss2 >> v;
    cout << u << ", " << v << endl;
    w = u * v;
    stringstream ss3;
    ss3 << w;
    return ss3.str();
  }
};

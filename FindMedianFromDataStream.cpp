// use two heaps.
// O(1) access to median
// increase speed up of insertion
class MedianFinder {
  // maxHeap store smaller half of numbers
  // minHeap store larger half of numbers
  priority_queue<int> lower; // maxHeap
  priority_queue<int, vector<int>, greater<int>> upper;
  
  public:
  void addNum(int num) {
    // insert into smaller half
    lower.push(num);
    // move largest element to upper to keep things balanced
    upper.push(lower.top());
    lower.pop();
    
    // maintain half in each OR lower size + 1 = upper size
    if(lower.size() < upper.size()) {
      lower.push(upper.top());
      upper.pop();
    }
  }
  double findMedian() {
    // if lower.size > upper.size return lower top
    // else return the average of the 2 elements on the front
    if(lower.size() > upper.size())
      return lower.top();
    //else
    return ((double) lower.top() + upper.top()) * 0.5;
  }
};

// use a vector to store the data
// add = O(logn) keep data sorted. use lower_bound to find poisiton
// find O(sort time = nlogn ) - sort data and find median 
class MedianFinder2_TLE {
  vector<int> data; 

  public:
  // Adds to data, keeps input stream sorted
  void addNum(int num) {
    if (data.empty())
      data.push_back(num);
    else
      data.insert(lower_bound(data.begin(), data.end(), num), num);     // binary search and insertion combined
  }

  // Returns the median of current data stream
  double findMedian() {
    int n = data.size();
    return n & 1 ? data[n / 2] : ((double) data[n / 2 - 1] + data[n / 2]) * 0.5;
  }
};

// use a vector to store the data
// add = O(1) vector insert at end
// find O(sort time = nlogn ) - sort data and find median 
class MedianFinder1_TLE {
  vector<int> data;

  public:
  // Adds a number into the data structure.
  void addNum(int num) {
    data.push_back(num);
  }

  // Returns the median of current data stream
  double findMedian() {
    sort(data.begin(), data.end());

    int n = data.size();
    return (n & 1 ? data[n / 2] : ((double) data[n / 2 - 1] + data[n / 2]) * 0.5);
  }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

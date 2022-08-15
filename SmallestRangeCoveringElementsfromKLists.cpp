class Solution {
  public:
  struct Node {
    int data, row, col;
    Node(int val, int r, int c) : data(val), row(r), col(c) {}
  };
  struct compareNode {
    bool operator() (Node *a, Node *b) {
      return a->data > b->data;
    }
  };
  
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    
    // Use a min heap of size k
    priority_queue<Node*, vector<Node*>, compareNode> minHeap;
    // initialize min, max and range
    int currMin = INT_MAX, currMax = INT_MIN, currRange = INT_MAX;
    // loop over input data and build the min heap
    for(int i = 0; i < k; ++i) {
      currMax = max(currMax, nums[i][0]);
      Node*  temp = new Node(nums[i][0], i, 0);
      minHeap.push(temp);
    }
    // the start and end range of our answer
    int start = currMin, end = currMax;
    while(true) {
      Node* min = minHeap.top();
      minHeap.pop();
      currMin = min->data;
      
      // update start/end if we got a smaller range
      if(currMax - currMin < currRange) {
        start = currMin;
        end = currMax;
        currRange = currMax - currMin;
      }
      // if we don't have any more elements in the row of min element, we're done
      if(min->col + 1 == nums[min->row].size())
        break;
      
      // if we still have atleast one element push it inside the min heap
      Node *next = new Node(nums[min->row][min->col + 1], min->row, min->col + 1);
      minHeap.push(next);
      // update the currMax if the next element is bigger than this
      if(next->data > currMax)
        currMax = next->data;
    }
    return {start, end};
  }
};

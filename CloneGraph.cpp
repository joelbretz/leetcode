/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  #if 0 
  void printAdj(map<int,vector<int>>& adj) {
    for(auto elem : adj) {
      cout << elem.first << ": ";
      for(auto next : elem.second) 
        cout << next << " " ;
      cout << endl;
    }
  }  

  void buildMap(map<int,vector<int>>& adj, set<int>& vis, Node* node) {
    //cout << "buildMap( ..., ..., " << node->val << " )" << endl;  
    vis.insert(node->val);
    for(auto neighbor : node->neighbors) {
      //cout << " add " << neighbor->val << " to adj list for " << node->val << endl;
      adj[node->val].push_back(neighbor->val);
      if(vis.find(neighbor->val) == vis.end())
        buildMap(adj,vis,neighbor);
    }
    //cout << endl;
  }
  #endif
  map<Node*,Node*> cloneMap;
  
  public:
  Node* cloneGraph(Node* node) {
    if(node == nullptr)
      return node;
    
    // base case, we've been here before, just return the
    // clone
    if(cloneMap.find(node) != cloneMap.end())
      return cloneMap[node];
    
    // create a new nodde
    Node* cloneNode = new Node(node->val);
    // insert into cloneMap
    cloneMap[node] = cloneNode;
    
    // iterate over neighbors and call cloneGraph recursively
    for(auto neighbor : node->neighbors) {
      cloneNode->neighbors.push_back(cloneGraph(neighbor));
    }
    return cloneNode;
  }
  #if 0
  Node* cloneGraphAdj(Node* node) {
    if(node == nullptr)
      return node;
    
    set<int> visited;
    map<int,vector<int>> adjMap;
    buildMap(adjMap,visited,node);
    printAdj(adjMap);
    
    for(auto elem : adjMap) {
      cout << elem.first << ": ";
      for(auto next : elem.second) 
        cout << next << " " ;
      cout << endl;
    }
    return nullptr;
  }
  #endif
}

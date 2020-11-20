#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

vector<int> maxSum( BinaryTree* tree ) {
    if ( !tree ) { return vector<int>{0, INT_MIN}; }
    
    auto l = maxSum(tree->left);
    int l1(l[0]), l2(l[1]);
    
    auto r = maxSum(tree->right);
    int r1(r[0]), r2(r[1]);
    
    int maxChild   = max (l1, r1);
    int maxSum     = max (maxChild + tree->value, tree->value);
    int maxSumRoot = max (l1 + tree->value + r1, maxSum);
    int maxPath    = max (l2, max(r2, maxSumRoot) );
    
    return vector<int>{ maxSum, maxPath };
}

int maxPathSum(BinaryTree tree) {
  vector<int> arr = maxSum(&tree);
  return arr[1];
}

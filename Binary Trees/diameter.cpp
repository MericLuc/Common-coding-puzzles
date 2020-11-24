#include <deque>

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left, *right;

  BinaryTree(int val) : value(val), left(nullptr), right(nullptr) {}
};

int diam(BinaryTree* curNode) {
    return !curNode ? 0 : 1 + max(diam(curNode->left), diam(curNode->right));
}

int binaryTreeDiameter(BinaryTree *tree) {
    int ret(-1), cur(-1);
    deque<BinaryTree*> queue;
    queue.push_back(tree);
    
    while ( !queue.empty() )
    {
        BinaryTree* curNode = queue.front();
        queue.pop_front();

        if ( curNode ) {
            cur = diam(curNode->left) + diam(curNode->right);
            if ( cur > ret ) { ret = cur; }
            queue.push_back(curNode->left );
            queue.push_back(curNode->right);
        }
    }
    
    return ret;
}
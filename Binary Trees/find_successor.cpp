class BinaryTree {
public:
  int value;
  BinaryTree *left{nullptr}, *right{nullptr}, *parent{nullptr};

  BinaryTree(int p_val) : value(p_val) { }
};

BinaryTree* getLeftMostChild(BinaryTree* node) {
    BinaryTree* curNode { node };
    while ( curNode->left ) { curNode = curNode->left; }
    return curNode;
}

BinaryTree* getRightMostParent(BinaryTree* node) {
    BinaryTree* curNode { node };
    if ( curNode->parent && curNode->parent->right == curNode )
        curNode = curNode->parent;
    
    return curNode->parent;
}

// O(H) time | O(1) space - where H is the height of the tree
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  return node->right ? getLeftMostChild(node->right) : getRightMostParent(node);
}
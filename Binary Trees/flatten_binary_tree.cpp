#include <vector>

class BinaryTree {
public:
  int         value;
  BinaryTree *left = nullptr, *right = nullptr;

  BinaryTree(int value);
};

std::vector<BinaryTree*> getNodes( BinaryTree*               tree, 
                                   std::vector<BinaryTree*>* arr ) {
    if ( tree ) {
        getNodes ( tree->left, arr );
        arr->push_back( tree );
        getNodes ( tree->right, arr );
    }
    return *arr;
}

BinaryTree* flattenBinaryTree( BinaryTree* root ) {
  auto nodes = getNodes( root, new std::vector<BinaryTree*>() );
    for ( int i = 0; i < std::size(nodes) - 1; ++i ) {
        BinaryTree* leftN{nodes[i]}, *rightN{nodes[i+1]};
        leftN ->right = rightN;
        rightN->left  = leftN;
    }
  return nodes[0];
}

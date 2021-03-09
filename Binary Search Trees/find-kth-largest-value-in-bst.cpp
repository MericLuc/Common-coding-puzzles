/*!
 * @brief Get the Kth largest value in a BST
 *        From https://www.algoexpert.io/questions/Find%20Kth%20Largest%20Value%20In%20BST
 */

#include <vector>

class BST {
public:
  int  value;
  BST* left {nullptr};
  BST* right{nullptr};

  BST(int val): value(val) { }
};

void inOrder(BST* n, std::vector<int>& sortedNodes) {
	if ( !n ) { return; }
	inOrder(n->left, sortedNodes);
	sortedNodes.push_back(n->value);
	inOrder(n->right, sortedNodes);
}

// O(n) time | O(n) space
// n : The number of nodes in the BST
int findKthLargestValueInBst(BST* tree, int k) {
	std::vector<int> sortedNodes;
	
  inOrder(tree, sortedNodes);
	return std::size(sortedNodes) >= k ? 
		sortedNodes[ std::size(sortedNodes) - k ] : -1;
}

#include <vector>
#include <deque>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};

void inOrder(BST* cur, vector<int>& m)
{
	if ( cur )
	{
		inOrder    (cur->left , m);
		m.push_back(cur->value   );
		inOrder    (cur->right, m);
	}
}

void preOrder(BST* cur, vector<int>& m)
{
	if ( cur ) 
	{ 
		m.push_back(cur->value); 
		if ( cur->left  ) { preOrder( cur->left , m); }
		if ( cur->right ) { preOrder( cur->right, m); }
	}
}

void postOrder(BST* cur, vector<int>& m)
{
	if ( cur ) 
	{
		if ( cur->left  ) { postOrder( cur->left , m); }
		if ( cur->right ) { postOrder( cur->right, m); }
		m.push_back(cur->value); 
	}
}

vector<int> inOrderTraverse(BST *tree, vector<int> m) {
  inOrder(tree, m);
  return m;
}

vector<int> preOrderTraverse(BST *tree, vector<int> m) {
	preOrder(tree, m);
  return m;
}

vector<int> postOrderTraverse(BST *tree, vector<int> m) {
  postOrder(tree, m);
  return m;
}

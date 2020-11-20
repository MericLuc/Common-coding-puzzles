class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool test(BST* n, int min, int max )
{
	if      ( !n                                ) { return true;  }
	else if ( n->value < min || n->value >= max ) { return false; }
	else
	{
		if ( n->left  && !test(n->left , min     , n->value) ) { return false; }
		if ( n->right && !test(n->right, n->value, max     ) ) { return false; } 
	}
	return true;
}

bool validateBst(BST *tree) { return test(tree, INT_MIN, INT_MAX); }
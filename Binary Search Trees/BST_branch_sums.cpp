using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left        = NULL;
    right       = NULL;
  }
};

void explore( BinaryTree* cur, vector<int>& res, int sum )
{
	if ( cur )
	{
		sum += cur->value;
		if ( !cur->left && !cur->right ) { res.push_back(sum); }
		
		explore(cur->left , res, sum);
		explore(cur->right, res, sum);
	}
}

vector<int> branchSums(BinaryTree *root) 
{
  vector<int> l_res;
  explore(root, l_res, 0);
  return l_res;
}
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == NULL) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == NULL) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minHeightBst( vector<int> m, BST* cur = nullptr ) {
	if ( m.empty() ) { return nullptr; }
	
	int l_idx = static_cast<int>(m.size())/2;
  int l_val = m[l_idx];
	
	if ( !cur ) { cur = new BST(l_val); }
	else        { cur->insert(l_val)  ; }
	
	if ( l_idx ) {
		minHeightBst( vector<int>(m.begin(),         m.begin()+l_idx ), cur );
		minHeightBst( vector<int>(m.begin()+l_idx+1, m.end()         ), cur );
	}
  return cur;
}

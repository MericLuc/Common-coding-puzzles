#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) : value(val), left(nullptr), right(nullptr) {}

  BST &insert(int val) {
		if      ( val < value  ) 
		{ 
			if ( !left ) { left = new BST(val); }
			else 				 { left->insert(val);   }
		}
		else
		{ 
			if ( !right ) { right = new BST(val); }
			else 				  { right->insert(val);   }
		}

    return *this;
  }

  bool contains(int val) {
    if      ( value == val         ) { return true;								  }
		else if ( value > val && left  ) { return left ->contains(val); }
		else if ( value < val && right ) { return right->contains(val); }
    return false;
  }
	
	int minVal(void) const { 
		return left ? left->minVal() : value;
	}

  BST &remove(int val, BST* p = nullptr) {
		if      ( val <  value && left  ){ left ->remove(val, this); }
		else if ( val >  value && right ){ right->remove(val, this); }
		else if ( value == val ) 
		{
			if ( left && right )
			{
				value = right->minVal();
				right->remove(value, this);
			}
			else if ( !p )
			{
				if      ( left  ) { value = left ->value; right = left->right; left  = left ->left;  }
				else if ( right ) { value = right->value; left  = right->left; right = right->right; }
			}
			else if ( p->left  == this ) { p->left  = left ? left : right; }
			else if ( p->right == this ) { p->right = left ? left : right; }
		}
    return *this;
  }
};

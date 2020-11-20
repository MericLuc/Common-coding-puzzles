#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *d1,
                                         AncestralTree *d2) {
  AncestralTree* cur(d1);
	vector<AncestralTree*> v1, v2;
	
	if ( d1 == d2 ) { return d1; }
	
	while( cur ) 
	{ 
		if ( cur == d2 ) { return cur; }
		v1.push_back(cur); 
		cur = cur->ancestor; 
	}
	
	cur = d2;
	while( cur ) 
	{ 
		if      ( cur == d1 )                                   { return cur; }
		else if ( find(v1.begin(), v1.end(), cur) != v1.end() ) { return cur; }
		cur = cur->ancestor; 
	}
	
  return NULL;
}

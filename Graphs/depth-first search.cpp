#include <vector>
using namespace std;

class Node {
public:
  string         name;
  vector<Node *> children;

  Node( string str ): name(str) { }

  vector<string> depthFirstSearch( vector<string> *m ) 
	{
		m->push_back(name);
		for ( auto& it : children ) { it->depthFirstSearch(m); }
		
    return *m;
  }

  Node *addChild(string name) 
	{
    children.push_back(new Node(name));
    return this;
  }
};

#include <vector>
#include <deque>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *m) 
	{
		deque<Node *> queue{this};
		
		while( !queue.empty() ) 
		{
			Node* n = queue.front();
			queue.pop_front();
			m->push_back( n->name );
			
			for ( auto& it : n->children ) { queue.push_back(it); }
		}
    return *m;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
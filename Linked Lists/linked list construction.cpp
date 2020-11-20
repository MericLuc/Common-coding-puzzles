using namespace std;

class Node {
public:
  int value;
  Node *prev, *next;

  Node(int value);
};

class DoublyLinkedList {
public:
  Node *head, *tail;

  DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	
  void setHead(Node *n) 
	{
		if ( !head ) { head = n; tail = n;    }
                else         { insertBefore(head, n); }
  }

  void setTail(Node *n) 
	{
		if ( !tail ) { head = n; tail = n;    }
                else	     { insertAfter (tail, n); }
  }

  void insertBefore( Node *bfr, Node *n ) 
	{
		if ( n == head && n == tail ) { return; }
		remove(n);
		n->prev = bfr->prev;
		n->next = bfr;
		
		if ( !bfr->prev ) { head = n;            }
		else              { bfr->prev->next = n; }
		bfr->prev = n;
  }

  void insertAfter ( Node *aft, Node *n ) 
	{
		if ( n == head && n == tail ) { return; }
		remove(n);
		n->prev = aft;
		n->next = aft->next;
		
		if ( !aft->next ) { tail = n;            }
		else							{ aft->next->prev = n; }
		aft->next = n;
  }

  void insertAtPosition(int pos, Node *n) 
	{
		if ( pos == 1 ) { setHead(n); }
		else
		{
			int cmpt(1);
			Node* cur = head;
			
			while( cur && cmpt++ < pos ) { cur = cur->next;      }
			if   ( cur                 ) { insertBefore(cur, n); }
			else			                   { setTail     (n);      }
		}
  }

  void removeNodesWithValue(int val) 
	{
		Node* cur = head, *next = nullptr;
		
		while( cur )
		{
			next = cur->next;
			if ( cur->value == val ) { remove(cur); }
			cur = next;
		}
  }

  void remove(Node *n) 
	{
		if ( n == head ) { head = head->next;       }
		if ( n == tail ) { tail = tail->prev;       }
		if ( n->prev   ) { n->prev->next = n->next; }
		if ( n->next   ) { n->next->prev = n->prev; }
		n->prev = nullptr;
		n->next = nullptr;
  }

  bool containsNodeWithValue(int value) 
	{
		Node* cur = head;
		while( cur && cur->value != value ) { cur = cur->next; }
    return cur;
  }
};

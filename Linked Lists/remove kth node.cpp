#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  LinkedList* first = head;
    LinkedList* sec   = head;
    
    while( k-- ) { sec = sec->next; } // Assuming the linkedList has always at least k nodes
    
    if( !sec ) { // If the element to remove is the head
        head->value = head->next->value; 
        head->next  = head->next->next; 
        return;
    }
    
    while ( sec->next ) { sec = sec->next; first = first->next; }
    first->next = first->next->next;
}

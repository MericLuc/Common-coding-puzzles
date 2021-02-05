/*!
 * @brief Merge two sorted linked list IN PLACE.
 *        From https://www.algoexpert.io/questions/Merge%20Linked%20Lists
 */

#include <vector>

class LinkedList {
public:
  int         value;
  LinkedList* next{ nullptr };

  LinkedList(int p_val) : value(p_val) {}
};

LinkedList* mergeLinkedLists(LinkedList* h1, LinkedList* h2) {
    LinkedList *p1{ h1 }, *p2{ h2 }, *prev{ nullptr };
    while ( p1 && p2 ) {
        if ( p1->value < p2->value ) { prev = p1; p1 = p1->next; }
        else { 
            if ( prev ) prev->next = p2;
            prev = p2; 
            p2 = p2->next; 
            prev->next = p1; 
        }
    }
    if ( !p1 ) prev->next = p2;
  return h1->value < h2->value ? h1 : h2;
}

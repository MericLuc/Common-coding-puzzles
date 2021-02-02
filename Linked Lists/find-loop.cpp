/*!
 * @brief Find a loop in a linked list
 *        From https://www.algoexpert.io/questions/Find%20Loop
 */

#include <vector>

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

// Note that we know the linked list had a loop
LinkedList *findLoop(LinkedList *head) {
    LinkedList *first{ head->next }, *sec{ head->next->next };
    
    while ( first != sec ) { first = first->next; sec = sec->next->next; }
    first = head;
    
    while ( first != sec ) { first = first->next; sec = sec->next; }
    return first;
}

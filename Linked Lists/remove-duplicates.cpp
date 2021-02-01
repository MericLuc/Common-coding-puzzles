/*!
 * @brief Remove duplicates from sorted linked list
 */

class LinkedList {
public:
  int         value;
  LinkedList* next{nullptr};

  LinkedList(int p_val) : value(p_val) { }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* lst) {
    LinkedList* curN(lst), *nextN(nullptr);
    while ( curN ) {
        nextN = curN->next;
        while ( nextN && nextN->value == curN->value ) { nextN = nextN->next; }
        curN->next = nextN;
        curN       = nextN;
    }
    return lst;
}

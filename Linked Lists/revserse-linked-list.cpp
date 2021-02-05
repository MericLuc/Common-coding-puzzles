/*!
 * @brief Reverse a linked list.
 *        From  https://www.algoexpert.io/questions/Reverse%20Linked%20List
 */

class LinkedList {
public:
  int         value;
  LinkedList* next{nullptr};

  LinkedList(int p_val): value(p_val) {}
};

LinkedList* reverseLinkedList(LinkedList* head) {
    LinkedList *prvN{nullptr}, *curN{head}, *nxtN{nullptr};
    while ( curN ) {
        nxtN = curN->next;
        curN->next = prvN;
        prvN = curN;
        curN = nxtN;
    }
  return prvN;
}

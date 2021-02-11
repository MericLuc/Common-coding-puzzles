/*!
 * @brief Sum of Linked Lists
 *        From https://www.algoexpert.io/questions/Sum%20of%20Linked%20Lists
 */

class LinkedList {
public:
  int value;
  LinkedList* next{nullptr};

  LinkedList(int p_val) : value(p_val) { }
};

LinkedList* sumOfLinkedLists(LinkedList* l1,
                             LinkedList* l2) {
    LinkedList *ret{new LinkedList(0)}, *cur{ret};
    int carry{0};
    while ( l1 || l2 || carry ) {
        cur->next  = new LinkedList(carry);
        cur        = cur->next;
        carry      = 0;
        if ( l1 ) { cur->value += l1->value; l1 = l1->next; }
        if ( l2 ) { cur->value += l2->value; l2 = l2->next; }
        
        if ( cur->value >= 10 ) { cur->value -= 10; carry = 1; }
    }
    
    return ret->next;
}
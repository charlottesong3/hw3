#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

#include "llrec.h"

//


void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == NULL) { //creating base case 

        smaller = NULL;

        larger = NULL;

    return;
    }

    //O(N) because every items goes thorugh once

    Node* current = head;

    head = head->next;

    llpivot(head, smaller, larger, pivot);

      if (current->val <= pivot) {

        current->next = smaller;

        smaller = current;
    }
      
    //self explanatory BUT smaller are values less than pivot 
    // larger are those greater than pivot

      else {
        current->next = larger;

        larger = current;
    }

}


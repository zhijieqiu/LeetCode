//Select a Random Node from a Singly Linked List
/*
  i = 1, probability of selecting first node = 1/N
i = 2, probability of selecting second node =
                   [probability that first node is not selected] * 
                   [probability that second node is selected]
                  = ((N-1)/N)* 1/(N-1)
                  = 1/N  
*/
/* C program to randomly select a node from a singly
   linked list */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
 
/* Link list node */
struct node
{
    int key;
    struct node* next;
};
 
// A reservoir sampling based function to print a
// random node from a linked list
void printRandom(struct node *head)
{
    // IF list is empty
    if (head == NULL)
       return;
 
    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));
 
    // Initialize result as first node
    int result = head->key;
 
    // Iterate from the (k+1)th element to nth element
    struct node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
           result = current->key;
 
        // Move to next node
        current = current->next;
    }
 
    printf("Randomly selected key is %d\n", result);
}
 
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST  */
 
/* A utility function to create a new node */
struct node *newNode(int new_key)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the key  */
    new_node->key  = new_key;
    new_node->next =  NULL;
 
    return new_node;
}
 
 
/* A utility function to insert a node at the beginning
  of linked list */
void push(struct node** head_ref, int new_key)
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the key  */
    new_node->key  = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
 
// Driver program to test above functions
int main()
{
    struct node *head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
 
    printRandom(head);
 
    return 0;
}

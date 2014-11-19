#include <cstdio>
#include <cstdlib>
/****************************************************************************
 * Node info
 ****************************************************************************/
struct Node {
    // Data field
    int id;
    // Pointer field
    Node* next;
};
// root stores the first node of a list
Node *root = NULL;

/****************************************************************************
 * Function field
 ****************************************************************************/
/* 
 * Prototype:
 *      Node *createNode(int);
 * Function:
 *      Create a new node.
 * Parameter: 
 *      A int of id.
 * Return value:
 *      A new node.
 */
Node *createNode(int id) {
    // Allocate memory for new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    // Initialize node
    newNode->id = id;
    newNode->next = NULL;
    // Return new node
    return newNode;
}
/* 
 * Prototype:
 *      void addFront(int);
 * Function:
 *      Add node to the front of list.
 * Parameter: 
 *      A int of id.
 * Return value:
 *      No return value.
 */
void addFront(int id) {
    // Create a new for id
    Node *newNode = createNode(id);
    // Check if list is empty or not
    if (root == NULL) {
        // List is empty, so root should point to the new node
        root = newNode;
    } else {
        // List existed, just add node to the front
        newNode->next = root;
        root = newNode;
    }
}
/* 
 * Prototype:
 *      void removeBack();
 * Function:
 *      Remove the last node from the list.
 *      If the list is empty, do nothing.
 * Parameter: 
 *      No parameter.
 * Return value:
 *      No return value.
 */
void removeBack() {
    // Check if list is empty or not
    if (root == NULL) {
        // List is empty, just do nothing
        return;
    }
    // Scan for the last node from root
    Node *iterator = root;
    Node *prev = NULL;
    while (iterator->next != NULL) {
        prev = iterator;
        iterator = iterator->next;
    }
    // Check the last node equals to root or not
    if (iterator == root) {
        // List has only one node
        free(root);
        root = NULL;
    } else {
        // Remove the last node
        prev->next = NULL;
        free(iterator);
    }
}
/* 
 * Prototype:
 *      void dumpList();
 * Function:
 *      Print list.
 * Parameter: 
 *      No parameter.
 * Return value:
 *      No return value.
 */
void dumpList() {
    Node *iterator = root;
    while (iterator != NULL) {
        printf("id = %d -> \n", iterator->id);
        iterator = iterator->next;
    }
    printf("NULL\n");
}
int main(int argc, char *argv[])
{
    for (int i = 1; i <= 5; i++) {
        addFront(i);
    }
    dumpList();
    printf("Remove one node from back\n");
    removeBack();
    dumpList();
    printf("Remove one node from back\n");
    removeBack();
    dumpList();
    printf("Remove one node from back\n");
    removeBack();
    dumpList();
    printf("Remove one node from back\n");
    removeBack();
    dumpList();
    printf("Remove one node from back\n");
    removeBack();
    dumpList();
    return 0;
}

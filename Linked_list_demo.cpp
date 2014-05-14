#include <cstdio>
#include <cstdlib>
// Node info
struct Node {
    int id;
    Node* next;
};
Node *root = NULL;
// Function
Node *createNode(int id) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}
void addFront(int id) {
    Node *newNode = createNode(id);
    if (root == NULL) {
        // List is empty
        root = newNode;
    } else {
        newNode->next = root;
        root = newNode;
    }
}
void removeBack() {
    if (root == NULL) {
        // Do nothing
        return;
    }
    Node *iterator = root;
    Node *prev = NULL;
    while (iterator->next != NULL) {
        prev = iterator;
        iterator = iterator->next;
    }
    if (iterator == root) {
        // one node
        free(root);
        root = NULL;
    } else {
        prev->next = NULL;
        free(iterator);
    }
}
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












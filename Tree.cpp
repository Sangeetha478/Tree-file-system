#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

// Tree node structure
struct Node {
    char name[50];
    struct Node* children[MAX_CHILDREN];
    int childCount;
};

// Create a new node
struct Node* createNode(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->childCount = 0;
    return newNode;
}

// Add child to a node
void addChild(struct Node* parent, struct Node* child) {
    parent->children[parent->childCount++] = child;
}

// DFS Traversal
void printTree(struct Node* root, int level) {
    if (root == NULL) return;

    // Indentation for hierarchy
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s\n", root->name);

    for (int i = 0; i < root->childCount; i++) {
        printTree(root->children[i], level + 1);
    }
}

int main() {
    // Create nodes
    struct Node* root = createNode("Root");
    struct Node* docs = createNode("Documents");
    struct Node* pics = createNode("Pictures");
    struct Node* file1 = createNode("file1.txt");
    struct Node* file2 = createNode("file2.txt");
    struct Node* img = createNode("image.jpg");

    // Build tree
    addChild(root, docs);
    addChild(root, pics);
    addChild(docs, file1);
    addChild(docs, file2);
    addChild(pics, img);

    // Print tree
    printf("File System Structure:\n");
    printTree(root, 0);

    return 0;
}

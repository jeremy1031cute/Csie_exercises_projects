// you can slightly modify the sample code if you want

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tNode{
    int data;
    struct tNode *Lchild, *Rchild;
};

// Insert new data to Binary Search Tree.
void insert(struct tNode *curNode, int newData) {
    // while-loop version
    while(true) {
        if (newData < curNode->data) {
            if (curNode->Lchild == NULL) { //create new node, assign to Lchild and break
                struct tNode *new_node = (struct tNode *) malloc(sizeof(struct tNode));
                new_node->data = newData;
                new_node->Lchild = NULL;
                new_node->Rchild = NULL;

                curNode->Lchild = new_node;
                printf("%d\n", new_node->data);
                break;
            } else{ //continue with curNode->Lchild
                curNode = curNode->Lchild;
            }
        }
        else if (newData > curNode->data) {
            if (curNode->Rchild == NULL) { //create new node, assign to Rchild and break
                struct tNode *new_node = (struct tNode *) malloc(sizeof(struct tNode));
                new_node->data = newData;
                new_node->Lchild = NULL;
                new_node->Rchild = NULL;

                curNode->Rchild = new_node;
                printf("%d\n", new_node->data);
                break;
            } else { //continue with curNode->Rchild
                curNode = curNode->Rchild;
            }
        }
        printf("%d ", curNode->data);
    }
}

// To determine whether the target data exists in the tree
int find(struct tNode *curNode, int target) {
    while(true) {
        if (curNode == NULL) { // If we reach NULL, it means we can't find the target, return 0 (i.e. false).
            return 0;
        } else if (target == curNode->data) { // If we find the target in curNode, return 1 (i.e. true).
            return 1;
        } else{ // Otherwise, compare the target and the data of curNode to determine the target in which child (either Lchild or Rchild).
            if (target > curNode->data)
                curNode = curNode->Rchild;
            else
                curNode = curNode->Lchild;
        }
    }
}

void deleteTree(struct tNode* curNode) {
    if (curNode == NULL)
        return;
    deleteTree(curNode->Lchild);
    deleteTree(curNode->Rchild);
    free(curNode);
}

int main() {
    int numQuery = 0;
    int tmpNum;
    scanf("%d", &numQuery);//times of actions you can do

    struct tNode *root = (struct tNode *) malloc(sizeof(struct tNode));
    (*root) = (struct tNode) {.data = 0, .Lchild = NULL, .Rchild = NULL};
    // use a virtual node represent the root (store 0)

    for(int i = 0; i < numQuery; i++) {
        int operation_type, data;
        scanf("%d%d", &operation_type, &data);
        if (operation_type == 1) {
            // insert data
            // To find the target position where to insert, we start from root and compare the data of root and new data.
            insert(root, data);
        } else if (operation_type == 2) {
            // To determine whether the target data exists in the tree.
            // To find the target data, we start from root and compare the data of root and new data like insert function.
            if (find(root, data)) {
                printf("%d is in tree\n", data);
            } else {
                printf("%d is not in tree\n", data);
            }
        }
    }

    // free memory
    deleteTree(root);
    return 0;
}

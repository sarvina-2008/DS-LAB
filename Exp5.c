#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insertion in BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Search in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum
struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Find maximum
struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Deletion in BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;
    struct Node* temp;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Display (Inorder)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;

        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            temp = search(root, key);
            if (temp != NULL)
                printf("Key %d found in BST.\n", key);
            else
                printf("Key %d not found in BST.\n", key);
            break;

        case 4:
            temp = findMin(root);
            if (temp != NULL)
                printf("Minimum key = %d\n", temp->key);
            else
                printf("Tree is empty.\n");
            break;

        case 5:
            temp = findMax(root);
            if (temp != NULL)
                printf("Maximum key = %d\n", temp->key);
            else
                printf("Tree is empty.\n");
            break;

        case 6:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}

OUTPUT:

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 25

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 15

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 40

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 8

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 20

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 35

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 1
Enter key to insert: 60

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 6
Inorder Traversal: 8 15 20 25 35 40 60 

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 2
Enter key to delete: 8

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 3
Enter key to search: 20
Key 20 found in BST.

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 4
Minimum key = 15

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 5
Maximum key = 60

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 6
Inorder Traversal: 15 20 25 35 40 60 

--- Binary Search Tree Menu ---
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Display (Inorder)
7. Exit
Enter your choice: 7









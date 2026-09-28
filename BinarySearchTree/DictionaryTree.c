#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
    char word[50];
    char meaning[100];

    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word,word);
    strcpy(newNode->meaning,meaning);
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root,char word[], char meaning[]) {
    if (root == NULL)
        return createNode(word, meaning);

    if(strcmp(word,root->word) < 0) {
        root->left = insertNode(root->left,word,meaning);
    }else if(strcmp(word,root->word) > 0) {
        root->right = insertNode(root->right,word,meaning);
    }else{
        printf("ALREADY EXISTS");
    }
    return root;
}

void search(struct Node* root, char word[]) {
    if (root == NULL) {
        printf("Word not found\n");
        return;
    }

    if (strcmp(word, root->word) == 0)
        printf("Meaning of '%s' is: %s\n", word, root->meaning);
    else if (strcmp(word, root->word) < 0)
        search(root->left, word);
    else
        search(root->right, word);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    printf("1. Insert Word\n");
    printf("2. Search Word\n");
    printf("3. Display Dictionary\n");
    printf("4. Exit\n");


    while (1) {

        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';

                printf("Enter Meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = '\0';

                root = insertNode(root, word, meaning);
                break;

            case 2:
                printf("Enter Word to Search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';

                search(root, word);
                break;

            case 3:
                printf("Dictionary Words\n");
                inorder(root);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
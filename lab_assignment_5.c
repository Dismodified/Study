#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Parses the string in the linkedList.
// If the linked list is head -> |a|->|b|->|c|
// then toCString function will return "abc"
char* toCString(node* head) {
    int lengthHead = length(head);
  // Allocated memory for the string.
    char* str = (char*)malloc((lengthHead + 1) * sizeof(char));
    if (str == NULL) {
    }
  
    int i = 0;
    while (head != NULL) {
        str[i++] = head->letter;
        head = head->next;
    }
    str[i] = '\0';
    return str;
}

// Inserts character to the linkedlist
// If the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
  // Allocated memory for new node.
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
    }
    newNode->letter = c;
    newNode->next = NULL;
    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Deletes all nodes in the linkedList.
void deleteList(node** pHead) {
  // Head is assigned to NULL
    while (*pHead != NULL) {
        node* temp = *pHead;
        *pHead = (*pHead)->next;
      
        free(temp);
    }
}

int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list stack
struct Node {
    char data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
char pop(struct Node** top) {
    if (*top == NULL) {
        return '\0'; // Return null character if the stack is empty
    }
    struct Node* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to get the top element of the stack without removing it
char peek(struct Node* top) {
    return (top != NULL) ? top->data : '\0';
}

// Function to display the current text (Undo stack)
void displayText(struct Node* undoStack) {
    struct Node* temp = undoStack;
    printf("Current text: ");
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to perform undo operation
void undo(struct Node** undoStack, struct Node** redoStack) {
    char poppedChar = pop(undoStack);
    if (poppedChar != '\0') {
        push(redoStack, poppedChar); // Add the popped character to the redo stack
    } else {
        printf("Nothing to undo\n");
    }
}

// Function to perform redo operation
void redo(struct Node** undoStack, struct Node** redoStack) {
    char poppedChar = pop(redoStack);
    if (poppedChar != '\0') {
        push(undoStack, poppedChar); // Add the popped character back to the undo stack
    } else {
        printf("Nothing to redo\n");
    }
}

int main() {
    struct Node* undoStack = NULL; // Stack for undo
    struct Node* redoStack = NULL; // Stack for redo

    // Simulate operations (Write, Undo, Redo)
    push(&undoStack, 'A');
    push(&undoStack, 'B');
    push(&undoStack, 'C');

    displayText(undoStack); // Output: ABC

    printf("Performing undo...\n");
    undo(&undoStack, &redoStack);
    displayText(undoStack); // Output: AB

    printf("Performing undo...\n");
    undo(&undoStack, &redoStack);
    displayText(undoStack); // Output: A

    printf("Performing redo...\n");
    redo(&undoStack, &redoStack);
    displayText(undoStack); // Output: AB

    return 0;
} 
OUTPUT:

Current text: CBA
Performing undo...
Current text: BA
Performing undo...
Current text: A
Performing redo...
Current text: BA

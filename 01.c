#include <stdio.h>
#include <stdlib.h>

#define MAX 3 // Altering this value changes the size of the stack

int st[MAX], top = -1; // Stack array and top pointer

// Function declarations
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char *argv[]) {
    int val, option;

    // Main menu loop
    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        // Switch case to handle each operation
        switch(option) {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;

            case 2:
                val = pop(st);
                if(val != -1)
                    printf("\n The value deleted from stack is: %d", val);
                break;

            case 3:
                val = peek(st);
                if(val != -1)
                    printf("\n The value stored at top of stack is: %d", val);
                break;

            case 4:
                display(st);
                break;

        }
    } while(option != 5); // Loop continues until option 5 (EXIT) is selected

    return 0;
}

// Function to push an element onto the stack
void push(int st[], int val) {
    if(top == MAX - 1) {
        printf("\n STACK OVERFLOW");
    } else {
        top++;
        st[top] = val;
    }
}

// Function to pop the top element from the stack
int pop(int st[]) {
    int val;
    if(top == -1) {
        printf("\n STACK UNDERFLOW");
        return -1;
    } else {
        val = st[top];
        top--;
        return val;
    }
}

// Function to display all elements in the stack
void display(int st[]) {
    int i;
    if(top == -1)
        printf("\n STACK IS EMPTY");
    else {
        for(i = top; i >= 0; i--)
            printf("\n %d", st[i]);
        printf("\n");
    }
}

// Function to peek at the top element of the stack
int peek(int st[]) {
    if(top == -1) {
        printf("\n STACK IS EMPTY");
        return -1;
    } else {
        return (st[top]);
    }
}

OUTPUT:


 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 1

 Enter the number to be pushed on stack: 23

 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 1

 Enter the number to be pushed on stack: 34

 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 1

 Enter the number to be pushed on stack: 66

 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 2

 The value deleted from stack is: 66
 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 3

 The value stored at top of stack is: 34
 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 4

 34
 23

 *****MAIN MENU*****
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
 5. EXIT
 Enter your option: 5


=== Code Execution Successful ===

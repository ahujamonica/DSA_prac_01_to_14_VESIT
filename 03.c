#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
 
void insert();
void delete();
void display();
 
int front = -1, rear = -1;
int queue[maxsize];
 
void main() {
	int choice = 0;
	while (choice != 4) {
    	printf("\nChoose the Operation to perform:\n");
    	printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
    	printf("\nEnter your choice ? ");
    	scanf("%d", &choice);
    	switch (choice) {
        	case 1:
            	insert();
            	break;
        	case 2:
            	delete();
            	break;
        	case 3:
            	display();
            	break;
        	case 4:
            	exit(0);
            	break;
        	default:
            	printf("\nEnter valid choice??\n");
    	}
	}
}
 
void insert() {
	int item;
	printf("\nEnter the element\n");
	scanf("%d", &item);
	if (rear == maxsize - 1) {
    	printf("\nOVERFLOW\n");
    	return;
	}
	if (front == -1 && rear == -1) {
    	front = 0;
    	rear = 0;
	} else {
    	rear = rear + 1;
	}
	queue[rear] = item;
	printf("\nValue inserted ");
}
 
void delete() {
	int item;
	if (front == -1 || front > rear) {
    	printf("\nUNDERFLOW\n");
    	return;
	} else {
    	item = queue[front];
    	if (front == rear) {
        	front = -1;
        	rear = -1;
    	} else {
        	front = front + 1;
    	}
    	printf("\nValue deleted ");
	}
}
 
void display() {
	int i;
	if (rear == -1) {
    	printf("\nEmpty queue\n");
	} else {
    	printf("\nPrinting values .....\n");
    	for (i = front; i <= rear; i++) {
        	printf("\n%d\n", queue[i]);
    	}
	}
}

OUTPUT:

Choose the Operation to perform:

1. Insert an element
2. Delete an element
3. Display the queue
4. Exit

Enter your choice ? 1

Enter the element
10

Value inserted

Choose the Operation to perform:

1. Insert an element
2. Delete an element
3. Display the queue
4. Exit

Enter your choice ? 1

Enter the element
20

Value inserted

Choose the Operation to perform:

1. Insert an element
2. Delete an element
3. Display the queue
4. Exit

Enter your choice ? 3

Printing values .....

10
20

Choose the Operation to perform:

1. Insert an element
2. Delete an element
3. Display the queue
4. Exit

Enter your choice ? 2

Value deleted

Choose the Operation to perform:

1. Insert an element
2. Delete an element
3. Display the queue
4. Exit

Enter your choice ? 3

Printing values .....

20

Choose the Operation to perform:

1. Insert an element
2. Delete an element
3. Display the queue
4. Exit

Enter your choice ? 4

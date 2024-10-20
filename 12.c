#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

// Structure to store contact information
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function to add a contact to the phone book
void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", contacts[*count].name); // Read string with spaces
    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[*count].phone); // Read string with spaces
    (*count)++;
    printf("Contact added!\n");
}

// Function to perform binary search on contacts by name
int binarySearch(Contact contacts[], int count, const char *searchName) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(contacts[mid].name, searchName);

        if (cmp == 0) {
            return mid; // Contact found
        } else if (cmp < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Contact not found
}

// Function to display all contacts
void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts in phone book.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to sort contacts alphabetically by name
void sortContacts(Contact contacts[], int count) {
    // Simple bubble sort to sort contacts by name
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
                // Swap contacts
                Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
}

// Main function with phone book menu
int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                sortContacts(contacts, count); // Sort after adding a new contact
                break;
            case 2: {
                char searchName[NAME_LENGTH];
                printf("Enter the name to search: ");
                scanf(" %[^\n]", searchName);
                int result = binarySearch(contacts, count, searchName);
                if (result != -1) {
                    printf("Found: %s - %s\n", contacts[result].name, contacts[result].phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 3:
                displayContacts(contacts, count);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

OUTPUT:
Phone Book Menu:
1. Add Contact
2. Search Contact
3. Display Contacts
4. Exit
Enter your choice: 1
Enter name: John Doe
Enter phone number: 123-456-7890
Contact added!

Phone Book Menu:
1. Add Contact
2. Search Contact
3. Display Contacts
4. Exit
Enter your choice: 1
Enter name: Jane Smith
Enter phone number: 987-654-3210
Contact added!

Phone Book Menu:
1. Add Contact
2. Search Contact
3. Display Contacts
4. Exit
Enter your choice: 3
Contacts:
1. Jane Smith - 987-654-3210
2. John Doe - 123-456-7890

Phone Book Menu:
1. Add Contact
2. Search Contact
3. Display Contacts
4. Exit
Enter your choice: 2
Enter the name to search: John Doe
Found: John Doe - 123-456-7890

Phone Book Menu:
1. Add Contact
2. Search Contact
3. Display Contacts
4. Exit
Enter your choice: 4
Exiting...

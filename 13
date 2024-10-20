#include <stdio.h>

// Function for selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function for bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the adjacent elements if they are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function for insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code: Menu-driven program for sorting
int main() {
    int n, choice;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nSorting Menu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Create a copy of the original array to avoid modifying it after sorting
        int tempArr[n];
        for (int i = 0; i < n; i++) {
            tempArr[i] = arr[i];
        }

        switch (choice) {
            case 1:
                selectionSort(tempArr, n);
                printf("Array after Selection Sort:\n");
                printArray(tempArr, n);
                break;
            case 2:
                bubbleSort(tempArr, n);
                printf("Array after Bubble Sort:\n");
                printArray(tempArr, n);
                break;
            case 3:
                insertionSort(tempArr, n);
                printf("Array after Insertion Sort:\n");
                printArray(tempArr, n);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

OUTPUT:

Enter the number of elements in the array: 5
Enter the elements of the array:
34 7 23 32 5

Sorting Menu:
1. Selection Sort
2. Bubble Sort
3. Insertion Sort
4. Exit
Enter your choice: 1
Array after Selection Sort:
5 7 23 32 34

Sorting Menu:
1. Selection Sort
2. Bubble Sort
3. Insertion Sort
4. Exit
Enter your choice: 2
Array after Bubble Sort:
5 7 23 32 34

Sorting Menu:
1. Selection Sort
2. Bubble Sort
3. Insertion Sort
4. Exit
Enter your choice: 3
Array after Insertion Sort:
5 7 23 32 34

Sorting Menu:
1. Selection Sort
2. Bubble Sort
3. Insertion Sort
4. Exit
Enter your choice: 4
Exiting...


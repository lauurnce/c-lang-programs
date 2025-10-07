#include <stdio.h>
#include <stdlib.h> // Required for malloc() and exit()

// ---------------------------------------------------
// ## 1. Structure Definition
// ---------------------------------------------------

// Define the structure for a node in the linked list
struct Node {
    int data;           // Data field to store the integer value
    struct Node *next;  // Pointer to the next node in the list
};

// Global pointer that always points to the first node (HEAD)
struct Node *head = NULL;

// ## Function Prototypes
void insertAtBeginning(int data);
void deleteFromBeginning();
void displayList();
void menu();

// ---------------------------------------------------
// --- Main Function ---
// ---------------------------------------------------

int main() {
    int choice, data;

    while (1) {
        menu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\n\t*** Invalid input! Please enter a number. ***\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                if (scanf("%d", &data) == 1) {
                    insertAtBeginning(data);
                } else {
                    printf("\n\t*** Invalid data input. ***\n");
                    while (getchar() != '\n');
                }
                break;
            case 2:
                deleteFromBeginning();
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("\nExiting program. Goodbye! 👋\n");
                // Optional: Free allocated memory before exit (good practice)
                struct Node *current = head;
                struct Node *next;
                while (current != NULL) {
                    next = current->next;
                    free(current);
                    current = next;
                }
                exit(0);
            default:
                printf("\n\t*** Invalid choice! Please select an option from 1 to 4. ***\n");
        }
        printf("\n");
    }
    return 0;
}

// ---------------------------------------------------
// ## 2. Linked List Operations
// ---------------------------------------------------

/**
 * Inserts a new node at the beginning of the list (new HEAD).
 */
void insertAtBeginning(int data) {
    // Step 1: Allocate memory for the new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\n\t❌ Memory allocation failed (Heap is full).\n");
        return;
    }

    // Step 2: Assign data and link the new node
    newNode->data = data;
    newNode->next = head; // New node points to the old HEAD

    // Step 3: Update the HEAD pointer
    head = newNode; // The new node is now the HEAD

    printf("\n\t✅ Successfully inserted %d at the beginning.\n", data);
}

/**
 * Deletes the first node (HEAD) of the list.
 */
void deleteFromBeginning() {
    if (head == NULL) {
        printf("\n\t❌ The list is EMPTY. Cannot delete.\n");
        return;
    }

    // Step 1: Save a reference to the node to be deleted (the current HEAD)
    struct Node *nodeToDelete = head;
    int deletedData = nodeToDelete->data;

    // Step 2: Move the HEAD pointer to the next node
    head = head->next;

    // Step 3: Free the memory of the old HEAD node
    free(nodeToDelete);

    printf("\n\t✅ Successfully deleted %d from the beginning.\n", deletedData);
}

/**
 * Traverses and prints all elements in the list from start to end.
 */
void displayList() {
    if (head == NULL) {
        printf("\n\tThe list is currently EMPTY.\n");
        return;
    }

    struct Node *current = head;
    printf("\n--- LINKED LIST CONTENTS ---\n");

    // Traverse the list until 'current' reaches NULL (the end)
    while (current != NULL) {
        printf("[ %d ] -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
    printf("----------------------------\n");
}

// ---------------------------------------------------
// ## 3. Menu
// ---------------------------------------------------

/**
 * Displays the interactive menu options to the user.
 */
void menu() {
    printf("\n====================================\n");
    printf("    SINGLY LINKED LIST DEMO\n");
    printf("====================================\n");
    printf("1. INSERT at Beginning\n");
    printf("2. DELETE from Beginning\n");
    printf("3. DISPLAY List\n");
    printf("4. EXIT\n");
    printf("------------------------------------\n");
}
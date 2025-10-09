#include <stdio.h>
#include <stdlib.h> // For exit() and system() functions

// --- Configuration ---
#define MAX_SIZE 5 // Maximum capacity of the queue

// --- Global Queue Variables ---
int queue[MAX_SIZE];
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element

// --- Function Prototypes ---
void enqueue(int data);
int dequeue();
void display();
int isFull();
int isEmpty();
int getChoice();

// --- Queue Utility Functions ---

/**
 * @brief Checks if the queue is full.
 * @return 1 if full, 0 otherwise.
 */
int isFull() {
    // Queue is full if the next position after rear is front
    // (Handles the circular nature)
    return (rear + 1) % MAX_SIZE == front;
}

/**
 * @brief Checks if the queue is empty.
 * @return 1 if empty, 0 otherwise.
 */
int isEmpty() {
    // Queue is empty if front is -1
    return front == -1;
}

// --- Queue Operations ---

/**
 * @brief Adds an element to the rear of the queue (Enqueue).
 * @param data The integer data to add.
 */
void enqueue(int data) {
    if (isFull()) {
        printf("\n🛑 **Queue Overflow!** Cannot enqueue. The queue is full.\n");
        return;
    }

    if (isEmpty()) {
        // If the queue is empty, set both front and rear to 0
        front = 0;
    }

    // Move rear pointer circularly and insert the element
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("\n✅ Enqueued: %d\n", data);
}

/**
 * @brief Removes an element from the front of the queue (Dequeue).
 * @return The integer data removed, or -1 if the queue was empty.
 */
int dequeue() {
    int data = -1;

    if (isEmpty()) {
        printf("\n🛑 **Queue Underflow!** Cannot dequeue. The queue is empty.\n");
        return data; // returns -1
    }

    data = queue[front];

    if (front == rear) {
        // If the queue had only one element, reset to empty state
        front = -1;
        rear = -1;
    } else {
        // Move front pointer circularly
        front = (front + 1) % MAX_SIZE;
    }

    printf("\n🗑️ Dequeued: %d\n", data);
    return data;
}

/**
 * @brief Prints all elements in the queue from front to rear.
 */
void display() {
    if (isEmpty()) {
        printf("\n✨ **Queue is empty!** Nothing to display.\n");
        return;
    }

    printf("\n📊 **Queue Elements** (Front -> Rear):\n");
    printf("-----------------------------------\n");

    int i = front;
    // Loop continues until i reaches rear, covering the circular nature
    do {
        printf("| %d ", queue[i]);
        if (i == front) printf("(FRONT)");
        if (i == rear) printf("(REAR)");
        printf("\n");
        i = (i + 1) % MAX_SIZE; // Move to the next element circularly
    } while (i != (rear + 1) % MAX_SIZE); // Stop one step *after* rear

    printf("-----------------------------------\n");
}

// --- Input Validation Function ---

/**
 * @brief Prompts the user for a menu choice and validates the input.
 * @return The validated integer choice (1-4).
 */
int getChoice() {
    int choice;
    char buffer[256];
    int valid = 0;

    // Loop until a valid choice is entered
    while (!valid) {
        printf("\n-----------------------------------\n");
        printf("       Circular Queue Menu\n");
        printf("-----------------------------------\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        // Read input as a string/line to handle non-integer input gracefully
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
             // Handle EOF or read error
             printf("\nError reading input. Exiting.\n");
             exit(1);
        }

        // Attempt to parse an integer from the buffer
        if (sscanf(buffer, "%d", &choice) == 1) {
            // Check if the integer is within the valid range
            if (choice >= 1 && choice <= 4) {
                valid = 1; // Valid choice found
            } else {
                printf("⚠️ **Invalid choice!** Please enter a number between 1 and 4.\n");
            }
        } else {
            // sscanf failed, meaning input wasn't a number
            printf("⚠️ **Invalid input type!** Please enter a number.\n");
        }
    }
    return choice;
}

// --- Main Program ---

int main() {
    int choice;
    int data;

    // Optional: Clear screen for cleaner output (may not work on all systems)
    // system("cls"); // For Windows
    // system("clear"); // For Unix/Linux/macOS

    printf("Welcome to the Circular Array Queue Program (Max Size: %d)\n", MAX_SIZE);

    while (1) {
        choice = getChoice();

        switch (choice) {
            case 1:
                printf("Enter the element to Enqueue: ");
                // Input validation for the integer data to be enqueued
                if (scanf("%d", &data) == 1) {
                    enqueue(data);
                } else {
                    printf("⚠️ **Invalid input!** Please enter a valid integer.\n");
                    // Clear the input buffer after failed scanf
                    while (getchar() != '\n');
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\n👋 Exiting Program. Goodbye!\n");
                exit(0); // Exit the program
                break;

            default:
                // This case should not be reached due to validation in getChoice()
                printf("An unexpected error occurred.\n");
                break;
        }

        // Clear the input buffer after successful scanf (for choice 1)
        // This is necessary to prevent remaining newline/characters from affecting the next getChoice()
        if (choice != 1) {
            // If the user didn't hit '1', the buffer might still have a newline from getChoice's fgets
            // Let's ensure that any lingering input is consumed before the next menu prompt
            // However, getChoice() uses fgets which handles the newline, so this is mostly defensive
        }

    } // end while(1)

    return 0; // Should not be reached, but good practice
}
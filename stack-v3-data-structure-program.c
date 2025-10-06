#include <stdio.h>
#include <stdlib.h> // For exit()

// --- Stack Configuration ---
#define MAX_SIZE 5 // Define a fixed size for the stack

int stack[MAX_SIZE]; // The array to hold stack elements
int top = -1;        // Tracks the index of the element at the top

// ## Function Prototypes
void bulk_push(); // New function for bulk input
void pop();
void peek();
void display();
void menu();

// -------------------------------------------------------------------
// --- Main Function ---
// -------------------------------------------------------------------

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n\t*** Invalid input! Please enter a number. ***\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: bulk_push(); break; // Call the bulk input function
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5:
                printf("\nExiting program. Demonstration complete! 👋\n");
                exit(0);
            default:
                printf("\n\t*** Invalid choice! Please select an option from 1 to 5. ***\n");
        }
        printf("\n");
    }
    return 0;
}

// -------------------------------------------------------------------
// --- Stack Operation Functions ---
// -------------------------------------------------------------------

/**
 * BULK PUSH: Allows user to input multiple elements at once, up to the remaining capacity.
 */
void bulk_push() {
    int capacity = MAX_SIZE - (top + 1); // Calculate remaining slots
    int count = 0; // To track successful pushes
    int num_to_push;

    if (capacity <= 0) {
        printf("\n\t❌ STACK OVERFLOW! The stack is already full. (Max size: %d)\n", MAX_SIZE);
        return;
    }

    printf("\n\tThe stack has %d slots remaining.\n", capacity);

    // Determine how many numbers to ask for
    if (capacity == MAX_SIZE) {
        num_to_push = MAX_SIZE;
        printf("Please enter up to %d space-separated numbers to fill the stack:\n", MAX_SIZE);
    } else {
        // This handles the specific scenario where capacity is 1 (top is 3, 4 elements already)
        num_to_push = capacity;
        printf("Please enter %d number(s) to fill the remaining slot(s):\n", num_to_push);
    }
    
    // Use a loop to read input for the available capacity
    for (int i = 0; i < num_to_push; i++) {
        int data;
        // Check if there is still space AND if the input is a valid integer
        if (top < MAX_SIZE - 1 && scanf("%d", &data) == 1) {
            top++;             // Step 1: Increment 'top' index
            stack[top] = data; // Step 2: Place data
            count++;           // Successfully pushed one number
        } else if (top >= MAX_SIZE - 1) {
             // Stop loop if full, even if the user typed more numbers
             break;
        } else {
            // Handle non-integer input
            printf("\n\t*** Invalid input! Pushing stopped. ***\n");
            // Clear the rest of the input buffer
            while (getchar() != '\n'); 
            break;
        }
    }
    
    if (count > 0) {
        printf("\n\t✅ Successfully PUSHED %d number(s) onto the stack.\n", count);
    } else if (count == 0 && capacity > 0) {
        printf("\n\t⚠️ No numbers were pushed.\n");
    }

    // Clear any leftover numbers the user may have typed beyond the capacity
    while (getchar() != '\n'); 
}


/**
 * POP: Removes and returns the element from the TOP of the stack.
 */
void pop() {
    if (top < 0) {
        // Condition: Stack Underflow (Empty)
        printf("\n\t❌ STACK UNDERFLOW! The stack is empty. Nothing to pop.\n");
    } else {
        int popped_data = stack[top];
        top--; // Decrement 'top' index (the element is now 'removed')
        printf("\n\t✅ POPPED %d. New top is at index %d.\n", popped_data, top);
    }
}

/**
 * PEEK: Shows the element at the TOP of the stack without removing it.
 */
void peek() {
    if (top < 0) {
        printf("\n\t⚠️ The stack is empty. Cannot PEEK.\n");
    } else {
        printf("\n\t🔍 The element at the TOP (index %d) is: %d\n", top, stack[top]);
    }
}

/**
 * DISPLAY: Prints all elements from TOP to BOTTOM.
 */
void display() {
    if (top < 0) {
        printf("\n\tThe stack is currently EMPTY.\n");
        return;
    }

    printf("\n--- Stack Contents (LIFO: Top to Bottom) ---\n");
    for (int i = top; i >= 0; i--) {
        printf("| %3d |", stack[i]);
        if (i == top) {
            printf(" <-- TOP (Last In, First Out)");
        }
        printf("\n");
    }
    printf("--------------------------------------------\n");
}

/**
 * MENU: Displays the interactive options.
 */
void menu() {
    printf("\n====================================\n");
    printf("     LIFO STACK DEMONSTRATION (Max Size: %d)\n", MAX_SIZE);
    printf("====================================\n");
    printf("1. BULK PUSH (Add Multiple Items)\n");
    printf("2. POP (Remove the top item)\n");
    printf("3. PEEK (View the top item)\n");
    printf("4. DISPLAY (Show all items)\n");
    printf("5. EXIT\n");
    printf("------------------------------------\n");
}
#include <stdio.h>
#include <stdlib.h> // For exit()
#include <ctype.h>  // For isspace() - useful for clearing buffers

// --- Stack Configuration ---
#define MAX_SIZE 5 

int stack[MAX_SIZE];
int top = -1; // -1 means stack is empty

// ## Function Prototypes
void push();
void pop();
void peek();
void display();
void menu();
void clear_input_buffer();

// -------------------------------------------------------------------
// --- Main Function ---
// -------------------------------------------------------------------

int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice (1-5): ");

        // Primary Input Validation: Check if the input is a single integer
        if (scanf("%d", &choice) != 1) {
            printf("\n\t❌ Invalid input! Please enter a number for the menu option.\n");
            clear_input_buffer(); // Clear invalid input from the buffer
            continue;
        }

        // Secondary Validation: Check if the number is within the valid range
        if (choice < 1 || choice > 5) {
            printf("\n\t❌ Invalid choice! Please select an option from 1 to 5.\n");
            continue;
        }

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5:
                printf("\nExiting program. Goodbye! 👋\n");
                exit(0);
        }
        printf("\n");
    }
    return 0;
}

// -------------------------------------------------------------------
// --- Utility Function for Input Validation ---
// -------------------------------------------------------------------

/**
 * Clears the input buffer to discard any extra characters or non-integer input.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -------------------------------------------------------------------
// --- Stack Operation Functions ---
// -------------------------------------------------------------------

/**
 * PUSH: Adds an element to the TOP of the stack, with input validation.
 */
void push() {
    int data;

    if (top >= MAX_SIZE - 1) {
        printf("\n\t❌ STACK OVERFLOW! The stack is full. (Max size: %d)\n", MAX_SIZE);
        return;
    }

    printf("Enter integer element to PUSH: ");
    
    // Data Input Validation
    if (scanf("%d", &data) != 1) {
        printf("\n\t❌ Invalid data input! Only integers are allowed. Push failed.\n");
        clear_input_buffer();
    } else {
        top++;             // Step 1: Increment 'top' index
        stack[top] = data; // Step 2: Place data
        printf("\n\t✅ PUSHED %d. New top is at index %d.\n", data, top);
        clear_input_buffer(); // Clear any trailing characters (e.g., spaces after the number)
    }
}

/**
 * POP: Removes and returns the element from the TOP of the stack.
 */
void pop() {
    if (top < 0) {
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

    printf("\n--- Stack Contents (Top to Bottom) ---\n");
    for (int i = top; i >= 0; i--) {
        printf("| %3d |", stack[i]);
        if (i == top) {
            printf(" <-- TOP");
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}

/**
 * MENU: Displays the interactive options.
 */
void menu() {
    printf("\n====================================\n");
    printf("     ROBUST STACK DEMONSTRATION\n");
    printf("====================================\n");
    printf("1. PUSH (Add an item)\n");
    printf("2. POP (Remove the top item)\n");
    printf("3. PEEK (View the top item)\n");
    printf("4. DISPLAY (Show all items)\n");
    printf("5. EXIT\n");
    printf("------------------------------------\n");
}
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 5 

int stack[MAX_SIZE]; 
int top = -1;       

void push();
void pop();
void peek();
void display();
void menu();


int main() {
    int choice;

    while (1) {
        menu();
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\n\t*** Invalid input! Please enter a number. ***\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: push(); break;
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


void push() {
    int data;

    if (top >= MAX_SIZE - 1) {
        // Condition: Stack Overflow (Full)
        printf("\n\t❌ STACK OVERFLOW! The stack is full. (Max size: %d)\n", MAX_SIZE);
    } else {
        printf("Enter element to PUSH: ");
        if (scanf("%d", &data) == 1) {
            top++;            // Step 1: Increment 'top' index
            stack[top] = data; // Step 2: Place data at the new 'top'
            printf("\n\t✅ PUSHED %d. New top is at index %d.\n", data, top);
        } else {
            printf("\n\t*** Invalid input. Push operation failed. ***\n");
            while (getchar() != '\n');
        }
    }
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
        top--; // Step 1: Decrement 'top' index (the element is now 'removed')
        printf("\n\t✅ POPPED %d. New top is at index %d.\n", popped_data, top);
    }
}


void peek() {
    if (top < 0) {
        printf("\n\t⚠️ The stack is empty. Cannot PEEK.\n");
    } else {
        printf("\n\t🔍 The element at the TOP (index %d) is: %d\n", top, stack[top]);
    }
}


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
    printf("-------\n");
}

void menu() {
    printf("\n====================================\n");
    printf("     LIFO STACK DEMONSTRATION\n");
    printf("====================================\n");
    printf("1. PUSH (Add an item)\n");
    printf("2. POP (Remove the top item)\n");
    printf("3. PEEK (View the top item)\n");
    printf("4. DISPLAY (Show all items)\n");
    printf("5. EXIT\n");
    printf("------------------------------------\n");
}
#include <stdio.h>
#include <stdlib.h> 


#define MAX_SIZE 5 // maximum size of the stack

int stack[MAX_SIZE]; // Array to store stack elements
int top = -1;        // 'top' is the index of the last element; -1 means stack is empty


void push(int data);
void pop();
void display();
void menu();


int main() {
    int choice, data;

    // Display the menu and handle user input in a loop
    while (1) {
        menu();
        printf("Enter your choice: ");

        // Check if input is a valid integer
        if (scanf("%d", &choice) != 1) {
            printf("\n\t*** Invalid input! Please enter a number. ***\n");
            // Clear the input buffer to prevent infinite loop
            while (getchar() != '\n');
            continue; // Skip to the next iteration
        }

        switch (choice) {
            case 1:
                printf("Enter the element to PUSH: ");
                // Check if input is a valid integer
                if (scanf("%d", &data) != 1) {
                    printf("\n\t*** Invalid input! Please enter an integer. ***\n");
                    while (getchar() != '\n');
                } else {
                    push(data);
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program. Goodbye! 👋\n");
                exit(0); // Exit the program successfully
            default:
                printf("\n\t*** Invalid choice! Please select an option from 1 to 4. ***\n");
        }
        printf("\n"); // Add a newline for better readability between operations
    }
    return 0;
}


void push(int data) {
    if (top >= MAX_SIZE - 1) {
        // Stack Overflow condition
        printf("\n\t*** STACK OVERFLOW! Cannot push %d. Stack is full. ***\n", data);
    } else {
        // Increment top and place the new data
        top++;
        stack[top] = data;
        printf("\n\tSuccessfully PUSHED %d onto the stack.\n", data);
    }
}


void pop() {
    if (top < 0) {
        // Stack Underflow condition
        printf("\n\t*** STACK UNDERFLOW! Cannot pop. Stack is empty. ***\n");
    } else {
        // Get the top element, then decrement top
        int popped_data = stack[top];
        top--;
        printf("\n\tSuccessfully POPPED %d from the stack.\n", popped_data);
    }
}

//para sa display ng stack 
void display() {
    if (top < 0) {
        printf("\n\tThe stack is currently EMPTY.\n");
        return;
    }

    printf("\n--- STACK CONTENTS (Top to Bottom) ---\n");
    for (int i = top; i >= 0; i--) {
        printf("| %3d |", stack[i]);
        if (i == top) {
            printf(" <-- TOP");
        }
        printf("\n");
    }
    printf("-------\n");
}


void menu() {
    printf("\n==================================\n");
    printf("    STACK OPERATIONS MENU (Size: %d)\n", MAX_SIZE);
    printf("==================================\n");
    printf("1. PUSH (Add Element)\n");
    printf("2. POP (Delete Top Element)\n");
    printf("3. DISPLAY (Show Stack)\n");
    printf("4. EXIT\n");
    printf("----------------------------------\n");
}
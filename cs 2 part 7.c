#include <stdio.h>

int main() {
    int N, sum, i;
    char choice;

    do {
        // Input the number
        printf("Input N: ");
        if (scanf("%d", &N) != 1 || N <= 0) { 
            printf("Invalid input. Please enter a positive integer.\n");

            // Clear the input buffer
            while (getchar() != '\n'); // Discard invalid input from the buffer

            // Ask user if they want to repeat the process
            printf("\nDo you want to try again? (y/Y): ");
            scanf(" %c", &choice);
            // If the user's input is not 'y' or 'Y', print a thank you message and exit the loop
            if (choice != 'y' && choice != 'Y') {
                printf("\nThank you for using the program. Goodbye!\n");
                break;
            }
            continue;
        }

        // Calculate proper divisors and their sum
        sum = 0;
        printf("Proper divisors are: ");
        for (i = 1; i < N; i++) {
            if (N % i == 0) {
                printf("%d", i);
                sum += i;

                // Add a comma and space if not the last divisor
                if (i < N / 2) {
                    printf(", ");
                }
            }
        }

        // Print the sum of proper divisors with step-by-step breakdown
        printf("\nSum of proper divisors: ");
        int temp_sum = 0;
        for (i = 1; i < N; i++) {
            if (N % i == 0) {
                printf("%d", i);
                temp_sum += i;

                // Add '+' if not the last divisor
                if (i < N / 2) {
                    printf(" + ");
                }
            }
        }
        printf(" = %d\n", sum);

        // Compare the sum with the input number and determine type
        if (sum < N) {
            printf("%d < %d is DEFICIENT\n", sum, N);
        } else if (sum == N) {
            printf("%d = %d is PERFECT\n", sum, N);
        } else {
            printf("%d > %d is ABUNDANT\n", sum, N);
        }

        // Ask user if they want to repeat the process
        printf("\nDo you want to check another number? (y/Y): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("\nThank you for using the program. Goodbye!\n");
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

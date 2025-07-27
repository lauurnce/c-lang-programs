#include <stdio.h>

int main() {
    // Initialization
    int N, i, r, f, sum;

    // Loop
    do {
        // Ask the user for an input
        printf("Enter a non-negative integer here: ");
        scanf("%d", &N);

        // If the entered input is a negative number or 0 the program will exit
        if (N <= 0) {
            printf("\nInvalid input entered. Exiting the program.\n");
            continue;
        }
        // If the user inputs a valid integer
        else {
            // Display N and N!
            printf("\nN = %d", N);
            printf("\nN! = ");

            // Loop and multiplication
            f = 1;
            sum = 0;
            for(i = 1; i <= N; i++) {
                printf("%d", i);
                f *= i;
                sum += i;
                if (i < N) {
                    printf(" x ");
                }
            }
            
            // Display the sum of the numbers from 1 to N
            printf("\nN = %d", sum);
        }

        // Ask the user if they want to try again
        printf("\nDo you want to try again? \n(Type 1 if YES or Type 0 if NO): ");
        scanf("%d", &r);

    } while (r == 1);

    // Exiting the program
    printf("\nThank you for using the program. Goodbye.\n");
    return 0;
}

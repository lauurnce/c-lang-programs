#include <stdio.h>

int main() {
 float weight, cost;
 int type_of_letterCode;
 char choice;
 do {
 printf("Enter the weight of the letter (in grams): ");
 scanf("%f", &weight);
 printf("Enter the letter code (1 for ordinary letter, 2 for special 
letter): ");
 scanf("%d", &type_of_letterCode);

 
 if (weight <= 1.0) {
 
 if (type_of_letterCode == 1) {
 cost = 20.00; 
 } else if (type_of_letterCode == 2) {
 cost = 40.00; 
 }
 } else {
 
 if (type_of_letterCode == 1) {
 cost = 20.00 + 15.00; 
 } else if (type_of_letterCode == 2) {
 cost = 40.00 + 25.00; 
 }
 }
 
 printf("The cost of the letter is Php %.2f\n", cost);
 printf("Do you want to enter another letter? \n (Y/y for YES):");
 scanf(" %c", &choice); 
 } while (choice == 'Y' || choice == 'y'); 
 printf("Thank you for using the service!\n");
 return 0;

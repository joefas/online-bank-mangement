#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for account and date
struct Date {
    int month, day, year;
};

struct Account {
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amount;
    struct Date dob;
    struct Date deposit;
};

// Function prototypes
void createAccount();
void viewDetails();
// Add more functions for other operations

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\n\n\t\t\tONLINE BANK MANAGEMENT SYSTEM\n");
        printf("\n\t\t1. Create New Account\n");
        printf("\t\t2. View Account Details\n");
        printf("\t\t3. Exit\n");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewDetails();
                break;
            case 3:
                printf("\nExiting the system. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to create a new account
void createAccount() {
    struct Account newAccount;

    // Get account details from the user
    printf("\nEnter the name: ");
    scanf("%s", newAccount.name);

    // Add more prompts to get other account details

    // Save the account details to a file or database
    FILE *file = fopen("accounts.dat", "ab");
    if (file != NULL) {
        fwrite(&newAccount, sizeof(struct Account), 1, file);
        fclose(file);
        printf("\nAccount created successfully!\n");
    } else {
        printf("\nError opening file to save account details.\n");
    }
}

// Function to view account details
void viewDetails() {
    int accountNumber;
    struct Account account;

    // Get account number from the user
    printf("\nEnter the account number: ");
    scanf("%d", &accountNumber);

    // Search for the account in the file or database
    FILE *file = fopen("accounts.dat", "rb");
    int found = 0;

    if (file != NULL) {
        while (fread(&account, sizeof(struct Account), 1, file) == 1) {
            if (account.acc_no == accountNumber) {
                found = 1;
                // Display account details
                printf("\nAccount Details:\n");
                printf("Name: %s\n", account.name);
                // Display other account details
                break;
            }
        }

        fclose(file);

        if (!found) {
            printf("\nAccount not found.\n");
        }
    } else {
        printf("\nError opening file to read account details.\n");
    }
}


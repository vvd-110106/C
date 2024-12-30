#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int userCount = 0;

// In ra Menu dau tien
void printHello() { 
    printf("\n   *** Bank Management System Using C ***\n");
    printf("               CHOOSE YOUR ROLE \n");
    printf("      ==============================\n");
    printf("      [1]. Admin \n");
    printf("      [2]. User \n");
    printf("      [3]. Exit the Program \n");
    printf("      ==============================\n");
}

// In ra menu quan li nguoi dung cho Admin
void managerMenu() {
    printf("\n   ===== User Management System =====\n");
    printf("           User Management Menu:\n");
    printf("       [1]. Display user list \n");
    printf("       [2]. Add new user\n");
    printf("       [3]. Delete user\n");
    printf("       [4]. Edit user information \n");
    printf("       [5]. Search for user\n");
    printf("       [0]. Exit\n");
}

// Hien thi danh sach nguoi dung
void printUsers() {
    if (userCount == 0) {
        printf("No users available.\n");
        return;
    }
    printf("\nUser List:\n");
    printf("Name\t|\tPhone Number\t|\tEmail\t|\tStatus\n");
    for (int i = 0; i < userCount; i++) {
    	printf("-------------------------------------------------------------------------------------------\n");
        printf("%s\t|\t%s\t|\t%s\t|\t%s\n", users[i].name, users[i].phone, users[i].email, users[i].status);
    }
}

// Them nguoi dung moi
void addUser() {
    // Cap phat lai bo nho cho mang users khi them nguoi dung moi
    users = realloc(users, (userCount + 1) * sizeof(struct User));
    if (users == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Yeu cau nguoi dung nhap thong tin
    printf("Enter user name: ");
    getchar();
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';
    printf("Enter user phone number: ");
    scanf("%s", newUser.phone);
    printf("Enter user email: ");
    scanf("%s", newUser.email);
    strcpy(newUser.password, newUser.phone);
    strcpy(newUser.status, "open");
    users[userCount] = newUser;
    userCount++;
    printf("User added successfully!\n");
}

// Menu quan li Admin
void adminMenu() {
    int choiceAdmin;
    int exitLoop = 0;

    while (!exitLoop) {
        managerMenu();
        printf("Enter The Choice: ");
        scanf("%d", &choiceAdmin);

        switch(choiceAdmin) {
            case 1:
                printUsers();
                break;
            case 2:
                addUser();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                exitLoop = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


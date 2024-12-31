#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int userCount = 0;

// Ham in ra menu chao
void printHello() { 
    printf("\n   *** Bank Management System Using C ***\n");
    printf("               CHOOSE YOUR ROLE \n");
    printf("      ==============================\n");
    printf("      [1]. Admin \n");
    printf("      [2]. User \n");
    printf("      [3]. Exit the Program \n");
    printf("      ==============================\n");
}
// Ham in ra menu quan ly nguoi dung cho Admin
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

// Ham kiem tra do dai hop le cua chuoi
int is_valid_string(char *str) {
    if(str != NULL && strlen(str) > 0){
    	return;
	}
}
// Ham kiem tra tinh duy nhat cua thong tin
int is_unique(char *id, char *phone, char *email, char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 || strcmp(users[i].phone, phone) == 0 ||
            strcmp(users[i].email, email) == 0 || strcmp(users[i].name, id) == 0) {
            return 0;
        }
    }
    return 1;
}
// Ham hien thi danh sach nguoi dung
void printUsers() {
    if (userCount == 0) {
        printf("No users available.\n");
        return;
    }
    printf("\nUser List:\n");
    printf("Name\t|\tPhone Number\t|\tEmail\t|\tUsername\t|\tStatus\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\n", users[i].name, users[i].phone, users[i].email, users[i].username, users[i].status);
    }
}
// Ham them nguoi dung moi
void addUser() {
    // Cap phat bo nho cho danh sach nguoi dung khi them nguoi dung moi
    users = realloc(users, (userCount + 1) * sizeof(struct User));
    if (users == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Cap phat bo nho cho cac truong thong tin cua nguoi dung moi
    newUser.name = (char *) malloc(50 * sizeof(char));
    newUser.phone = (char *) malloc(20 * sizeof(char));
    newUser.email = (char *) malloc(50 * sizeof(char));
    newUser.username = (char *) malloc(20 * sizeof(char));
    newUser.password = (char *) malloc(20 * sizeof(char));
    newUser.status = (char *) malloc(10 * sizeof(char));
    if (!newUser.name || !newUser.phone || !newUser.email || !newUser.username || !newUser.password || !newUser.status) {
        printf("Memory allocation failed for user fields.\n");
        return;
    }
    // Nhap thong tin nguoi dung
    printf("Enter user name: ");
    getchar();
    fgets(newUser.name, 50, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0'; 
    printf("Enter user phone number: ");
    scanf("%s", newUser.phone);
    printf("Enter user email: ");
    scanf("%s", newUser.email);
    printf("Enter login name: ");
    scanf("%s", newUser.username);

    // Kiem tra tinh hop le
    if (!is_valid_string(newUser.name) || !is_valid_string(newUser.phone) || !is_valid_string(newUser.email) || !is_valid_string(newUser.username)) {
        printf("User information cannot be empty.\n");
        return;
    }
    // Kiem tra tinh duy nhat cua thong tin nguoi dung
    if (!is_unique(newUser.name, newUser.phone, newUser.email, newUser.username)) {
        printf("Duplicate information found. Please make sure ID, phone, email, and username are unique.\n");
        return;
    }
    // Thiet lap mat khau va trang thai mac dinh
    strcpy(newUser.password, newUser.phone);
    strcpy(newUser.status, "open");
    // Them nguoi dung vao danh sach
    users[userCount] = newUser;
    userCount++;
    printf("User added successfully!\n");
}

// Ham tim kiem nguoi dung theo ten
void searchUserByName(char *name) {
    int found = 0;
    if (strlen(name) < 2) {
        printf("\nSearch Réults:\n");
	    printf("Name\t|\tPhone Number\t|\tEmail\t|\tUsername\t|\tStatus\n");
	    printf("-----------------------------------------------------------------------------------------------\n");
	    printf("User not found. \n");
        return;
    }
    printf("\nSearch Results:\n");
    printf("Name\t|\tPhone Number\t|\tEmail\t|\tUsername\t|\tStatus\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    char searchNameLower[50];
    for (int i = 0; name[i]; i++) {
        searchNameLower[i] = tolower(name[i]);
    }
    searchNameLower[strlen(name)] = '\0';
    for (int i = 0; i < userCount; i++) {
        // Chuyen ten trong co so du lieu thanh chu thuong
        char userNameLower[50];
        for (int j = 0; users[i].name[j]; j++) {
            userNameLower[j] = tolower(users[i].name[j]);
        }
        userNameLower[strlen(users[i].name)] = '\0';
        if (strcmp(userNameLower, searchNameLower) == 0) {
            found = 1;
            // Neu tim thay nguoi dung, in ra thong tin nguoi dung
            printf("%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\n", users[i].name, users[i].phone, users[i].email, users[i].username, users[i].status);
        }
    }

    // Neu khong tim thay nguoi dung, thong bao khong co ket qua
    if (!found) {
        printf("No users found with the given name.\n");
    }
}
// Ham menu quan ly cua Admin
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
                {
                    char searchName[50];
                    printf("Enter the user name to search for: ");
                    getchar();
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';
                    searchUserByName(searchName);
                }
                break;
            case 0:
                exitLoop = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


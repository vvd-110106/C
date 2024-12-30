#include <stdbool.h>

struct User {
    char name[50];
    char phone[20];
    char email[50];
    char password[20];
    char status[10];
};

struct Date {
    int month, day, year;
};

struct User* users = NULL;
struct User newUser;

#include <stdbool.h>

struct User {
    char name[50];     // T�n ng�?i d�ng
    char phone[20];    // S? �i?n tho?i
    char email[50];    // Email
    char username[20]; // T�n ��ng nh?p
    char password[20]; // M?t kh?u
    char status[10];   // Tr?ng th�i ng�?i d�ng
};

// Cau tr�c Date
struct Date {
    int month, day, year;
};
struct User* users = NULL;
struct User newUser;


	

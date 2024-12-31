#include <stdbool.h>

struct User {
    char name[50];     // Tên ngý?i dùng
    char phone[20];    // S? ði?n tho?i
    char email[50];    // Email
    char username[20]; // Tên ðãng nh?p
    char password[20]; // M?t kh?u
    char status[10];   // Tr?ng thái ngý?i dùng
};

// Cau trúc Date
struct Date {
    int month, day, year;
};
struct User* users = NULL;
struct User newUser;


	

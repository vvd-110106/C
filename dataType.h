#include <stdbool.h>

struct User {
    char *name;
    char *phone;
    char *email;
    char *username;
    char *password;
    char *status;
};

// Cau trúc Date
struct Date {
    int month, day, year;
};
struct User* users = NULL;
struct User newUser;
	

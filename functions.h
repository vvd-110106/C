#include "dataType.h"

// Nguyen mau ham
void printHello();                                                                            // Hien thi Menu ban dau
void managerMenu();                                                                           // In ra quan ly nguoi dung cho admin
void printUsers();                                                                            // Hien thi danh sach nguoi dung
void addUser();                                                                               // Them nguoi dung
void searchUserByName(char *name);                                                            // Tim kiem nguoi dung
void adminMenu();                                                                             // Ham quan ly cua chuc nang admin
int is_valid_string(char *str);                                                               // Kiem tra do dai cua thong tin (Tra ve 1 la hop le, 0 la khong hop le)
int is_unique(char *id, char *phone, char *email, char *username);                                                                              // Hien thi Menu ban dau                        // Kiem tra tinh duy nhat cua thong tin

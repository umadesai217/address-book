
#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO: Add your structures here */ 
typedef struct {
    char* name;      // Full name (dynamically allocated)
    int age;         // Age
    char* phone;     // Phone number (dynamically allocated)
} Person;

/* Structure to represent the address book */
typedef struct {
    Person* persons;  
    size_t size;      
} Address_book;

/* Function declarations. Do not modify! Implement those functions in address_book.c */
void print_person(const Person* person);
void print_address_book(const Address_book* address_book);

Address_book* create_address_book(void);
void destroy_address_book(Address_book* address_book);

#endif /* __ADDRESS_BOOK_H__ */

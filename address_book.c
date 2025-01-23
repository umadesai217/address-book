#include <stdio.h>
#include <stdlib.h>
#include "address_book.h"

/* Define structures */
typedef struct {
    char name[50];
    char phone[15];
} Person;

typedef struct {
    Person contacts[100];
    int size;
} Address_book;

/* Function to print a person's details */
void print_person(const Person* person) {
    if (person) {
        printf("Name: %s, Phone: %s\n", person->name, person->phone);
    }
}

/* Function to print the entire address book */
void print_address_book(const Address_book* address_book) {
    if (!address_book) return;
    
    printf("Address Book:\n");
    for (int i = 0; i < address_book->size; i++) {
        print_person(&address_book->contacts[i]);
    }
}

/* Function to create a new address book */
Address_book* create_address_book(void) {
    Address_book* new_book = (Address_book*)malloc(sizeof(Address_book));
    if (new_book) {
        new_book->size = 0;
    }
    return new_book;
}

/* Function to destroy the address book */
void destroy_address_book(Address_book* address_book) {
    if (address_book) {
        free(address_book);
    }
}

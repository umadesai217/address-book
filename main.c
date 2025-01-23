#include <stdio.h>
#include <string.h>
#include "address_book.h"

/* Function to add a person to the address book */
void add_person(Address_book* address_book, const char* name, const char* phone) {
    if (address_book->size < 100) { // Ensure we don't exceed the array size
        strcpy(address_book->contacts[address_book->size].name, name);
        strcpy(address_book->contacts[address_book->size].phone, phone);
        address_book->size++;
    }
}

int main() {
    // Create an address book
    Address_book* my_book = create_address_book();
    if (!my_book) {
        printf("Failed to create address book.\n");
        return 1;
    }

    // Add some people to the address book
    add_person(my_book, "Alice Johnson", "555-1234");
    add_person(my_book, "Bob Smith", "555-5678");

    // Print the address book
    print_address_book(my_book);

    // Clean up memory
    destroy_address_book(my_book);

    return 0;
}

#include "address_book.h"

int main() {
    // Create an address book from user input
    Address_book* my_book = create_address_book();
    
    // Print the address book
    print_address_book(my_book);

    // Free allocated memory
    destroy_address_book(my_book);

    return 0;
}

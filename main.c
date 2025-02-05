#include <stdio.h>
#include "address_book.h"

int main() {
    Address_book*book = create_address_book(); // Create address book

    if (book == NULL) {
        printf("Failed to create address book.\n");
        return 1; // Returns an error code if the book creation fails
    }

    print_address_book(book); // Prints contents

    // Frees memory
    destroy_address_book(book);

    return 0;
}

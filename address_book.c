#include "address_book.h"

/* Print a person's details */
void print_person(const Person* person) {
    if (person == NULL) {
        printf("Person data is NULL.\n");
        return;
    }
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Phone number: %s\n", person->phone);
}

/* Print all people in the address book */
void print_address_book(const Address_book* address_book) {
    if (address_book == NULL || address_book->persons == NULL || address_book->size == 0) {
        printf("==== Address book (0 entries) ====\n");
        printf("No contacts available.\n");
        return;
    }

    printf("==== Address book (%zu entries) ====\n\n", address_book->size);

    for (size_t i = 0; i < address_book->size; i++) {
        print_person(&address_book->persons[i]);
        if (i < address_book->size - 1) {
            printf("\n"); // Add a blank line between persons
        }
    }
}

/* Create an address book by reading input from the user */
Address_book* create_address_book(void) {
    // Allocate memory for the address_book structure
    Address_book* book = (Address_book*)malloc(sizeof(Address_book));
    if (!book) {
        printf("Memory allocation failed for address book.\n");
        return NULL;
    }

    // Ask the user for the number of persons
    size_t num_persons;
    printf("Enter the number of persons in the address book: ");
    scanf("%zu", &num_persons);
    getchar(); // Consume newline left by scanf

    // Allocate memory for the persons array
    book->persons = (Person*)malloc(num_persons * sizeof(Person));
    if (!book->persons) {
        printf("Memory allocation failed for persons.\n");
        free(book);
        return NULL;
    }
    book->size = num_persons;

    // Loop to get details for each person
    for (size_t i = 0; i < num_persons; i++) {
        printf("\nEnter details for person %zu:\n", i + 1);

        // Allocate memory and read full name
        char name[100];
        printf("Full Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        book->persons[i].name = strdup(name);

        // Read age
        printf("Age: ");
        scanf("%d", &book->persons[i].age);
        getchar();

        // Allocate memory and read phone number
        char phone[50];
        printf("Phone Number: ");
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = 0;
        book->persons[i].phone = strdup(phone);
    }

    return book;
}

/* Free memory allocated for address book */
void destroy_address_book(Address_book* address_book) {
    if (!address_book) return;

    // Free memory for each person
    for (size_t i = 0; i < address_book->size; i++) {
        free(address_book->persons[i].name);
        free(address_book->persons[i].phone);
    }

    free(address_book->persons);
    free(address_book);
}

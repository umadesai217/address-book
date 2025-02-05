#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address_book.h"

//to print a person
void print_person(const Person *p) {
	//checks validity of person
	if (p == NULL) {
		return;
	} 
	printf("Name: %s\n", p->name);
	printf("Age: %d\n", p->age);
	printf("Phone number: +%s\n", p->phoneNumber);
}

//to print out an address book
void print_address_book(const Address_book* address_book) {
	//checks validity of address book
	if (address_book == NULL) {
		return;
	} 
	
	printf("\n======Address Book (%zu entries)======\n\n", address_book->size);
	
	for (size_t i = 0; i < address_book ->size; i++) {
		print_person(&address_book->persons[i]);
		if (i < address_book->size -1) {
			printf("\n");
		}
	}
}

//to create an address book
Address_book*create_address_book(void) {
	Address_book*book = (Address_book*)malloc(sizeof(Address_book));
	
	book->size = 0;
	book->persons = NULL;
	
	printf("Enter the number of people: ");
	scanf("%zu", &book->size);
	getchar();
	
	book->persons = (Person*)malloc(book->size*sizeof(Person));
	
	for (size_t i = 0; i < book ->size; i++) {
		printf("Enter details for person %zu: \n", i+1);
		//getchar();
		printf("Full Name: ");
		fgets(book->persons[i].name, sizeof(book->persons[i].name),stdin);
		book->persons[i].name[strcspn(book->persons[i].name, "\n")] = '\0'; // Removes newline

        printf("Age: ");
        scanf("%d", &book->persons[i].age);
        getchar(); // Consumes newline before next input

        printf("Phone Number: ");
        fgets(book->persons[i].phoneNumber, sizeof(book->persons[i].phoneNumber), stdin);
        book->persons[i].phoneNumber[strcspn(book->persons[i].phoneNumber, "\n")] = '\0'; // Removes newline
		
	}
	return book;
}
//to destroy an address book
void destroy_address_book(Address_book* address_book) {
    if (address_book == NULL) {
        return;
    }

    free(address_book->persons); 
    free(address_book); 
}  
	
	

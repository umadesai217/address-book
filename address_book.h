#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__
/* TODO: Add your structures here */ 
//person
typedef struct Person {
	char name[100];
	int age;
	char phoneNumber[20];
} Person;

//address book
typedef struct Address_book {
	struct Person *persons;
	size_t size;
} Address_book;
	
/* Function declarations. Do not modify! Implement those functions in address_book.c */
void print_person(const Person* person);
void print_address_book(const Address_book* address_book);

Address_book* create_address_book(void);
void destroy_address_book(Address_book* address_book);

#endif /* __ADDRESS_BOOK_H__ */

#include <stdlib.h>
#include <stdio.h>

typedef struct Student{

    char* imie;
    char* nazwisko;
    int rok_urodzenia;
    Student* next;
   

};

extern Student* H;


void add_element();
void take_element();
void search_element();
void write_elements();
int counts_elements();
void delete_elements();
void end_program();
char* get_string(const char*);
int get_number();
void write_to_file();
void read_from_file();
char* fget_string(FILE*);
int fget_number(FILE*);


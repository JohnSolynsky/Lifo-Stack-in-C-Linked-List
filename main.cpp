#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

typedef enum menu
{
    x,
    dodaj,
    pobierz,
    wyszukaj,
    wypisz,
    policz,
    usun,
    zapisz_do_pliku,
    wczytaj_z_pliku,
    zakoncz
    

};


int main()
{
 
  
    char c;
    int a;
    char* option = (char*)malloc(sizeof(char) * 3);
    int len;

    if (!option)
    {
        printf("problem z alokacja pamieci!");
        exit(1);
    }

   
    do
    {
        printf("LIFO - Lista\n-----------------------------------\n");
        printf("1.dodaj element\n2.Pobierz element\n3.Wyszukaj element\n4.Wypisz elementy\n5.Policz\n6.Usun strukture\n7.Zapisz do Pliku\n8.Wczytaj z pliku\n9.Zakoncz\n");


        fgets(option, 3, stdin);
        len = strlen(option);

        c = atoi(option);

        if (option[len - 1] != '\n')
        {
            while (getchar() != '\n');
            c = 10;
        }
        
        switch (c)
        {
            case dodaj:
                system("cls");
                add_element();
                break;

            case pobierz:
                system("cls");
                take_element();
                break;

            case wyszukaj:
                system("cls");
                search_element();
                break;

            case wypisz:
                system("cls");
                write_elements();
                break;

            case policz:
                system("cls");
                counts_elements();
                break;

            case usun:
                system("cls");
                delete_elements();
                break;

            case zapisz_do_pliku:
                system("cls");
                write_to_file();
                break;

            case wczytaj_z_pliku:
                system("cls");
                read_from_file();
                break;

            case zakoncz:
                system("cls");
                end_program();
                break;

            default:
                system("cls");
                printf("Blad wyboru!\n\n");
                break;

        }

   

    }while (true);
    


}


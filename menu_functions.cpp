#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma warning(disable: 4996)

Student* H = NULL;


void display_list(Student* B,int i)                           //Wyœwietlenie listy studentów
{
    printf("\nStudent %d: \n", i);
    printf("Imie: %s\n", B->imie);
    printf("Nazwisko: %s\n", B->nazwisko);
    printf("Rok urodzenia: %d\n\n", B->rok_urodzenia);
}


void add_element()                                      //Dodanie elementu
{
    
    printf("DODAWANIE UZYTKOWNIKA\n---------------------------------------\n");

    Student* B = (Student*)malloc(sizeof(Student));

    if (!B)
    {
        printf("Blad alokacji pamieci!");
        exit(1);
    }

    
    B->imie = get_string("imie");

    B->nazwisko = get_string("nazwisko");

    B->rok_urodzenia=get_number();

    B->next = H;

    H = B;

   

    system("cls");
    printf("Dodano pomyslnie!\n\n");
   
}

void take_element()                                  //Pobranie elementu
{
    if (H == NULL)
    {
        system("cls");
        printf("Stos jest pusty!\n\n");
        
    }
    else
    {
        Student* B = H;

        H = H->next;

        free(B->imie);
        B->imie = NULL;

        free(B->nazwisko);
        B->imie = NULL;

        free(B);

        B = NULL;

        printf("Pobrano pomyslnie!\n\n");

    }
   
}

void search_element()                           //Wyszukanie elementu
{
    Student* B = H;
    int warunek = 0;
    int i=1;
    char c;
    char* tab;
    int nr;

    char* option = (char*)malloc(sizeof(char) * 3);
    int len;

    if (!option)
    {
        printf("problem z alokacja pamieci!");
        exit(1);
    }

    if (H == NULL)
    {
        system("cls");
        printf("Stos jest pusty!\n\n");
        return;

    }
   
    do
    {
        printf("SZUKANIE ELEMENTU\n-----------------------------------\n");
        printf("1.Przez imie\n2.Przez nazwisko\n3.Przez date urodzenia\n");

        fgets(option, 3, stdin);
        len = strlen(option);

        c = atoi(option);

        if (option[len - 1] != '\n')
        {
            while (getchar() != '\n');
            c = 10;
        }

        if (c != 1 && c != 2 && c != 3)
        {
            system("cls");
            printf("Blad wyboru!\n\n");
        }
         

    } while (c!=1 && c!=2 && c!=3);

    

    if (c == 1)
    {
        tab = get_string("imie");
        system("cls");
        printf("WYSZUKANI STUDENCI PRZEZ IMIE: %s\n-----------------------------------\n", tab);

        do
        {
            if (strcmp(B->imie, tab) == 0)
            {
                display_list(B, i);
                warunek = 1;
            }

             B = B->next;
             i++;

        } while (B != NULL);
         
    }
    else if(c==2)
    {
        tab = get_string("nazwisko");
        system("cls");
        printf("WYSZUKANI STUDENCI PRZEZ NAZWISKO: %s\n-----------------------------------\n", tab);

        do
        {
            if (strcmp(B->nazwisko, tab) == 0)
            {
                display_list(B, i);
                warunek = 1;
            }

            B = B->next;
            i++;

        } while (B != NULL);

    }
    else if (c == 3)
    {
        nr = get_number();
        system("cls");
        printf("WYSZUKANI STUDENCI PRZEZ ROK URODZENIA: %d\n-----------------------------------\n", nr);

        do
        {
            if (B->rok_urodzenia == nr)
            {
                display_list(B, i);
                warunek = 1;
            }
            B = B->next;
            i++;

        } while (B != NULL);

    }

    if (warunek == 0)
        printf("\nNie odnaleziono zadnego studenta!\n\n");
   
    printf("Kliknij dowolny klawisz by kontynuowac...");
    getchar();
    system("cls");

}

void write_elements()                               //Wypisanie struktury
{
    Student *B = H;

    int i = 1;

    if (B == NULL)
    {
        printf("Stos jest pusty!\n\n");
        return;
    }
    else
    {
        printf("LISTA STUDENTOW\n---------------------------------------\n");

        do
        {
            display_list(B, i);

            i++;

            B = B->next;

        } while (B != NULL);

        printf("Kliknij dowolny klawisz by kontynuowac...");
        getchar();
        system("cls");
    }

}

int counts_elements()                      //policzenie elementów
{
    int n=0;

    Student* B = H;

    if (B != NULL)
        do
        {
            n++;
            B = B->next;

        } while (B != NULL);
  
    printf("Struktura ma %d elementow\n\n", n);

    return n;
}


void delete_elements()                          //usuniecie elementow
{
    Student* B;

    if (H == NULL)
    {
        printf("Stos jest pusty!\n\n");
        return;
    }
    else
    {
        do
        {
            B = H;

            H = H->next;

            free(B->imie);
            B->imie = NULL;

            free(B->nazwisko);
            B->imie = NULL;

            free(B);
            B = NULL;

        } while (H != NULL);
     
        printf("Pomyslnie usunieto strukture!\n\n");
    }

}

void end_program()                  //zakonczenie programu
{
    if(H!=NULL)
    delete_elements();

    exit(0);
}


void write_to_file()    //Zapis struktury do pliku
{
    int len;
    if (H == NULL)
    {
        printf("Stos jest pusty!\n\n");
        return;
    }

    Student* B = H;

    FILE* f = fopen("dane.bin", "wb");

    if (!f)
    {
        printf("Blad otwarcia pliku dane!\n\n");
        return;
    }

    int n = counts_elements();

    system("cls");

    fwrite(&n, sizeof(int), 1, f);

    do
    {
        len = strlen(B->imie) + 1;

        fwrite(&len, sizeof(int), 1, f);

        fwrite(B->imie, sizeof(char),len, f);

        len = strlen(B->nazwisko) + 1;

        fwrite(&len, sizeof(int), 1, f);

        fwrite(B->nazwisko, sizeof(char), len, f);

        fwrite(&B->rok_urodzenia, sizeof(int), 1, f);

        B = B->next;

    } while (B != NULL);

    fclose(f);

    printf("Pomyslnie zapisano strukture do pliku!\n\n");
}

void read_from_file()                       //Odczyt struktury z pliku
{
    int i = 0;
    int n;
    int nr;

    FILE* f = fopen("dane.bin", "rb");

    if (!f)
    {
        printf("Blad otwarcia pliku dane!\n\n");
        return;
    }

    fread(&n, sizeof(int), 1, f);

   do
   {
        Student* B = (Student*)malloc(sizeof(Student));

        B->imie = fget_string(f);
        B->nazwisko = fget_string(f);
        B->rok_urodzenia = fget_number(f);

        B->next = H;
        H = B;


        i++;

   } while (i < n);


   printf("Pomyslnie pobrano dane z txt!\n\n");

}
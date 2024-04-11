#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

#pragma warning(disable: 4996)

char* get_string(const char* option)
{
    int warunek;

    int len;

    char* data = (char*)malloc(sizeof(char) * N);

    if (!data)
    {
        printf("Problem z alokacja pamieci!");
        exit(1);
    }

    do
    {
        warunek = 0;

        printf("Podaj %s: ",option);
        fgets(data, N, stdin);

        len = strlen(data);

        if (data[len - 1] != '\n')
        {
            printf("Za duzo znakow!");

            while (char c = getchar() != '\n');

            warunek = 1;
        }


        if (len == 1)
        {
            printf("Pole nie moze byc puste!");
            warunek = 1;
        }

        data[len - 1] = '\0';
        int j = 0;

        while (data[j] != '\0')
        {
            if ((data[j] < 65 || data[j] > 90) && (data[j] < 97 || data[j] > 122) && data[j] != ' ')
            {
                printf("Bledny typ danych!\n");
                warunek = 1;
                break;
            }

            j++;
        }

    } while (warunek==1);


   

    char *str = (char*)malloc(sizeof(char) * len);
   
    if (!str)
    {
        printf("Blad alokacji pamieci!");
    }

    str = data;
   
    return str;
}

int get_number()
{
    int warunek;

    int len;

    char* data = (char*)malloc(sizeof(char) * N);

    int rok;

    if (!data)
    {
        printf("Problem z alokacja pamieci!");
        exit(1);
    }

    do
    {
        warunek = 0;

        printf("Podaj rok: ");
        fgets(data, N, stdin);

        len = strlen(data);

        if (data[len - 1] != '\n')
        {
            printf("Za duzo znakow!");
            warunek = 1;
            while (char c = getchar() != '\n');
        }


        if (len == 1)
        {
            printf("Pole nie moze byc puste!");
            warunek = 1;
        }

        data[len - 1] = '\0';

        rok = atoi(data);

        if (rok < 1900)
        {
            printf("Bledny rok urodzenia!\n");
            warunek = 1;
        }
    } while (warunek == 1);


    return rok;
  
}



char* fget_string(FILE* f)
{
    char* data = (char*)malloc(sizeof(char) * N);
    int len;
    if (!data)
    {
        printf("Problem z alokacja pamieci!");
        exit(1);
    }

    fread(&len, sizeof(int), 1, f);

    fread(data, sizeof(char), len, f);

    char* str = (char*)malloc(sizeof(char) * len);

    if (!str)
    {
        printf("Problem z alokacja pamieci!");
        exit(1);
    }

    str = data;

    return str;

}

int fget_number(FILE* f)
{
    int num;

    fread(&num, sizeof(int), 1, f);

    return num;
}
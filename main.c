#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BACKSPACE_KEY 8

#define START 1
#define EXIT 2
working = 1;

process()
{
    setlocale(LC_ALL, "");
    char* string = (char*)calloc(1, sizeof(char));
    string[0] = '\0';
    char symbol = 0;
    int size = 1;

    printf("Введите ваш текст: ");
    while (symbol != '\n')
    {
        symbol = getchar();
        printf("%c", symbol);
        fflush(stdout);
    }
}


int main()
{
    int message = 0;
    setlocale(LC_ALL, "");

    while (working)
    {
        printf("===================================\n");
        printf("Добро пожаловать в программу!\n");
        printf("1. Запуск программы\n");
        printf("2. Выход\n");
        printf("===================================\n");

        scanf("%d", &message);
        fflush(stdout);
        switch(message)
        {
        case START:
            printf("Введите ваш текст:");
            char symbol = 0;
            char* string = (char*)calloc(1, sizeof(char));
            string[0] = '\0';
            int size = 1;

            while (symbol != '\n')
            {
                symbol = getchar();
                fflush(stdout);
                printf("%c", symbol);
            }
            break;
        case EXIT:
            printf("Выходим из програмыы\n");
            working = 0;
            break;
        default:
            printf("Unusual Enter\n");
        }
    }

    return 0;
}

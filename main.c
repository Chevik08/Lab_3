#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#define BACKSPACE_KEY 8
#define START_CHAR_RANGE -232
#define END_CHAR_RANGE 232
#define START 1
#define SEE 2
#define INFO 3
#define EXIT 4

int working = 1;

void info(char* userStr)
{
    setlocale(LC_ALL, "");
    for (int i = 0; i < strlen(userStr); i++)
    {
        if (userStr[i] == 32)
            printf("Пробел\n");
        else if (userStr[i] == 44)
        {
            printf("Знак препинания\n");
        }
        else
        {
            printf("Символ\n");
        }
    }
}

void string(char* userStr)
{
    free(userStr);
    userStr = (char*)malloc(1 * sizeof(char));
    _wsetlocale(LC_ALL, "");
    userStr[0] = '\0';
    char curChar = 0;
    int curSize = 1;
    printf("Enter your string: ");
    while(curChar != '\n')
    {
        curChar = getchar();
        int deltaVal = 0;
        int lengthDif = 0;
        if (curChar == BACKSPACE_KEY)
        {
            deltaVal = -1;
            lengthDif = 1;
        }
        else
        {
            if (curChar >= START_CHAR_RANGE && curChar <= END_CHAR_RANGE)
            {
            deltaVal = 1;
            lengthDif = 2;
            }
            else
                continue;
        }
        int newSize = curSize + deltaVal;
        if (newSize == 0)
            continue;
        char* tmpStr = (char*)malloc(newSize * sizeof(char));
        if (tmpStr)
        {
            for (int i = 0; i < newSize - lengthDif; ++i)
                tmpStr[i] = userStr[i];

            if (curChar != BACKSPACE_KEY)
                tmpStr[newSize - 2] = curChar;
            tmpStr[newSize - 1] = '\0';
            free(userStr);
            userStr = tmpStr;
            curSize = newSize;
        }
        else
        {
            printf("Why?");
            break;
        }
    }
    printf("\nEntered string: ");
    for (int i = 0; i < strlen(userStr); i++)
        printf("%c", userStr[i]);
    printf("\n");
}

int main()
{
    _wsetlocale(LC_ALL, "");
    int message = 0;
    char* userStr = (char*)malloc(1 * sizeof(char));
    while (working)
    {
        printf("===================================\n");
        printf("Welcome to the program!\n");
        printf("1. Enter your string\n");
        printf("2. See your string\n");
        printf("3. See an info about your word\n");
        printf("4. Exit\n");
        printf("===================================\n");

        scanf("%d", &message);
        switch(message)
        {
        case START:
            fflush(stdin);
            string(userStr);
            break;
        case SEE:
            printf("%s\n", userStr);
            break;
        case INFO:
            info(userStr);
            break;
        case EXIT:
            printf("Quiting from the program\n");
            free(userStr);
            working = 0;
            break;
        default:
            printf("Unusual Enter\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define BACKSPACE_KEY 8
#define START_CHAR_RANGE 32
#define END_CHAR_RANGE 1103
#define START 1
#define EXIT 2

int working = 1;

void string()
{
    setlocale(LC_ALL, "");
    char* userStr = (char*)malloc(1 * sizeof(char));
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

            printf("%c", curChar);
    }
    printf("\nEntered string: %s", userStr);
    printf("\n");
}

int main()
{
    int message = 0;
    char* userStr = (char*)malloc(1 * sizeof(char));
    while (working)
    {
        printf("===================================\n");
        printf("%p\n", 'п');
        printf("Welcome to the program!\n");
        printf("1. Enter your string\n");
        printf("2. Exit\n");
        printf("===================================\n");

        scanf("%d", &message);
        fflush(stdout);
        switch(message)
        {
        case START:
            fflush(stdout);
            fflush(stdin);
            string(userStr);
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

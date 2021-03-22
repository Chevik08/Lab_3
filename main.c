#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define BACKSPACE_KEY 8
#define START_CHAR_RANGE -1105
#define END_CHAR_RANGE 1105
#define START 1
#define SEE 2
#define INFO 3
#define LOAD 4
#define EXIT 5

int working = 1;

void load(char* userStr)
{
    FILE* file;
    file = fopen("C:/Users/Пользователь/Desktop/Projects/Lab_3/Test/load.txt", "wt");
    fprintf(file, userStr);
    fclose(file);
}

void info(char* userStr)
{
    setlocale(LC_ALL, "");
    int blank = 0;
    int marks = 0;
    int Big_lits = 0;
    int Litl_lits = 0;
    for (int i = 0; i < strlen(userStr); i++)
    {
        if (userStr[i] == 32)
            blank += 1;
        else if (userStr[i] >= 33 && userStr[i] <= 47)
            marks += 1;
        else if (userStr[i] >= 58 && userStr[i] <= 64)
            marks += 1;
        else if (userStr[i] >= 91 && userStr[i] <= 96)
            marks += 1;

        if (userStr[i] >= 65 && userStr[i] <= 90)
            Big_lits += 1;
        else if (userStr[i] >= -128 && userStr[i] <= -97)
            Big_lits += 1;
        else if (userStr[i] >= -97 && userStr[i] <= -17)
            Litl_lits += 1;
        else if (userStr[i] >= 97 && userStr[i] <= 122)
            Litl_lits += 1;
    }
    printf("В тексте было найдено:\n");
    printf("Пробелов: %d\n", blank);
    printf("Знаков препинания: %d\n", marks);
    printf("Заглавных букв: %d\n", Big_lits);
    printf("Прописных букв: %d\n", Litl_lits);
    printf("\n");
}

char* string(char* userStr)
{
    _wsetlocale(LC_ALL, "");
    free(userStr);
    userStr = (char*)malloc(1*sizeof(char));
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

    return userStr;
}

int main()
{
    int message = 0;
    char* userStr = NULL;
    userStr = (char*)malloc(1*sizeof(char));
    while (working)
    {
        printf("===================================\n");
        printf("Welcome to the program!\n");
        printf("1. Enter your string\n");
        printf("2. See your string\n");
        printf("3. See an info about your word\n");
        printf("4. Export to the file\n");
        printf("5. Exit\n");
        printf("===================================\n");

        scanf("%d", &message);
        fflush(stdin);
        switch(message)
        {
        case START:
            userStr = string(userStr);
            printf("%s\n", userStr);
            break;
        case SEE:
            for (int i = 0; i < strlen(userStr); i++)
                printf("%c", userStr[i]);
            printf("\n");
            break;
        case INFO:
            info(userStr);
            break;
        case LOAD:
            load(userStr);
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

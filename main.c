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
#define EXP 4
#define LOAD 5
#define EXIT 6

int working = 1;

void exp(char* userStr, int* param)
{
    FILE* file;
    file = fopen("C:/Users/student/Desktop/FastFolder/Lab_3/load.txt", "a+");
    fprintf(file,"%s\n", userStr);
    fprintf(file, "В тексте было найдено:\n");
    fprintf(file, "Пробелов: %d\n", param[0]);
    fprintf(file, "Знаков препинания: %d\n", param[1]);
    fprintf(file, "Заглавных букв: %d\n", param[2]);
    fprintf(file, "Прописных букв: %d\n", param[3]);
    fprintf(file, "\n");
    fclose(file);
}

void load()
{
    setlocale(LC_ALL, "");
    FILE* file;
    char buffer[128];
    file = fopen("C:/Users/student/Desktop/FastFolder/Lab_3/load.txt", "r");
    printf("You file:\n");
    while (fscanf(file,"%c", buffer)==1)
    {
        printf("%s", buffer);
    }
    fclose(file);
}

void info(char* userStr, int* param)
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
        else if (userStr[i] == -16)
            Big_lits += 1;
        else if (userStr[i] >= -128 && userStr[i] <= -97)
            Big_lits += 1;
        else if (userStr[i] >= -97 && userStr[i] <= -17)
            Litl_lits += 1;
        else if (userStr[i] >= 97 && userStr[i] <= 122)
            Litl_lits += 1;
    }

    param[0] = blank;
    param[1] = marks;
    param[2] = Big_lits;
    param[3] = Litl_lits;
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
            printf("Memory Error/n");
            break;
        }
    }
    printf("\nEntered string: ");

    return userStr;
}

int main()
{
    int message = 0;
    char* userStr = NULL;
    userStr = (char*)malloc(1*sizeof(char));
    int* param = (int*)calloc(4, sizeof(int*));
    while (working)
    {
        printf("===================================\n");
        printf("Welcome to the program!\n");
        printf("1. Enter your string\n");
        printf("2. See your string\n");
        printf("3. See an info about your string\n");
        printf("4. Export to the file\n");
        printf("5. See your file\n");
        printf("6. Exit\n");
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
        info(userStr, param);
        printf("В тексте было найдено:\n");
        printf("Пробелов: %d\n", param[0]);
        printf("Знаков препинания: %d\n", param[1]);
        printf("Заглавных букв: %d\n", param[2]);
        printf("Прописных букв: %d\n", param[3]);
        printf("\n");
            break;
        case EXP:
            info(userStr, param);
            exp(userStr, param);
            break;
        case LOAD:
            load();
            break;
        case EXIT:
            printf("Quiting from the program\n");
            free(userStr);
            free(param);
            working = 0;
            break;
        default:
            printf("Unusual Enter\n");
        }
    }

    return 0;
}

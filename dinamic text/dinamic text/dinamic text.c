#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toupper(char ch)
{
    if (ch >= 97 && ch <= 122)
    {
        ch = ch - 32;
    }
    return ch;
}

int isspace(char ch)
{
    if (ch == 32)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ispunct(char ch)
{
    if (ch == 33 || ch == 44 || ch == 46 || ch == 63)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void right_text(char text[])
{
    int i=0, j=0, len;
    len = strlen(text);
    char temp_text[1000] = { 0 };
    while (isspace(text[i]) == 1)
    {
        i = i + 1;
    }

    for (j = 0; i < len; i++, j++)
    {
        if (isspace(text[i]) == 1)
        {
            temp_text[j] = text[i];
            while (i + 1 < len && (isspace(text[i + 1]) == 1))
            {
                i = i + 1;
            }
        }

        if (ispunct(text[i]) == 1)
        {
            temp_text[j] = text[i];
            if (isspace(text[i + 1]) == 0 && i+1<len)
            {
                temp_text[j + 1] = ' ';
                j = j + 1;
            }

        }

        if (ispunct(text[i]) != 1 && isspace(text[i]) != 1 && i<len)
        {
            temp_text[j] = text[i];
        }
    }

    temp_text[1] = toupper(temp_text[1]);

    for (i = 2; i < 2*len; i++)
    {
        if (temp_text[i-2] == '.' || temp_text[i-2] == '!' || temp_text[i-2] == '?')
        {
            temp_text[i] = toupper(temp_text[i]);
        }
    }
    printf("your correct is: \n%s\n", temp_text);
}



char* GetText(FILE* stream, char terminator)
{
    int size = 0;
    int i;
    int capacity = 1024; // начальный размер буфера
    char* buffer = malloc(capacity);
    if (buffer == NULL) 
    {
        printf("MEMORY ALLOCATION ERROR");
    }
    int c;
    while ((c = getc(stream)) != EOF && c != terminator) 
    {
        buffer[size++] = c;
    }
    
    char* newtext = malloc(size+8);
    for (i = 0; i < size; i++)
    {
        newtext[i] = buffer[i];
    }

    if (newtext == NULL) 
    {
        printf("MEMORY RE-ALLOCATION ERROR");
    }

    newtext[size] = '\0';
    return newtext;
}

int main()
{
    char terminator = '#';
    char* text;

    printf("write 'c' for get text from console or 'f' for upload from file: ");
    int input_type = getchar();

    if (input_type == 'c') 
    {
        printf("write, please, your text (and write '#' for end of text):\n");
        text = GetText(stdin, terminator);
    }
    else if (input_type == 'f') {
        printf("write name of your file: ");
        char filename[256];
        scanf("%255s", filename);
        FILE* file = fopen(filename, "r");
        if (file == NULL) 
        {
            printf("ERROR OPENING FILE");
        }
        text = GetText(file, terminator);
        fclose(file);
    }
    else {
        printf("INVALID INPUT\n");
    }

    printf("your text is: \n%s\n", text);

    right_text(text);
    
    free(text);
    return 0;
}
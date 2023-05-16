#include <stdio.h>
#define ARRAY_SIZE 5


// fFG..ddf RRF


char toupper(char ch)
{
	if (ch >= 97 && ch <= 122)
		ch = ch - 32;
	return ch;
}

int isspace(char ch)
{
	if (ch == 32)
	{
		return 1;
	}
	else return 0;
}

int ispunct(char ch)
{
	if (ch == 33 || ch == 44 || ch == 46 || ch == 63)
	{
		return 1;
	}
	else return 0;
}



void right_text(char text[])
{
	char temp_text[ARRAY_SIZE] = { 0 };
	int i, j, k, len;

	len = strlen(text);

	i = 0;
	while (isspace(text[i]) == 1)
	{
		i = i + 1;
	}

	for (j = 0; i < len && j < len; i++, j++)
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
			if (isspace(text[i + 1]) == 0)
			{
				temp_text[j + 1] = ' ';
				j = j + 1;
			}

		}

		if (ispunct(text[i]) != 1 && isspace(text[i]) != 1)
		{
			temp_text[j] = text[i];
		}
	}

	temp_text[0] = toupper(temp_text[0]);

	for (i = 0; i < len; i++)
	{
		if (temp_text[i] == '.' || temp_text[i] == '!' || temp_text[i] == '?')
		{
			if (i < len)
			{
				temp_text[i + 2] = toupper(temp_text[i + 2]);
			}
		}
	}




	printf("%s\n", temp_text);
}





int main()
{
	printf("enter your text:\n");

	char text[ARRAY_SIZE];

	fgets(text, sizeof(text), stdin);

	printf("right vrsion of your text:\n");

	right_text(text);


	return 0;
}
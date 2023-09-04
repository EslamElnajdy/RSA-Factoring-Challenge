#include "factors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * main - the main program
 * @argc: the count of args.
 * @argv: the array with the args
 * Return: 0
*/
int main(int argc, char *argv[])
{
	FILE *ptr;
	char *buffer;
	size_t count;
	u_int64_t num;
	u_int64_t i;

	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "can't open the file");
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &count, ptr) != -1)
	{
		num = atoi(buffer);

		for (i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				printf("%ld=%ld*%ld\n", num, num / i, i);
				break;
			}
		}
	}

	return (0);
}

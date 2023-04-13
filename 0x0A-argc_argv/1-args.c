#include <stdio.h>
/**
 * main - the main ftn
 * @argc: displays the total no. of arguments passed
 * @argv: displays the arguments passed in terminal
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);
	return (0);
}

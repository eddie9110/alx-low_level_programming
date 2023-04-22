#include "main.h"

/**
 * _strlen - the ftn gives the length of string
 * @s: a string parameter whose length is to be determined
 * Return: int 0
 */


int _strlen_recursion(char *s)
{
	int ek = 0;


	if(*s)
	{
		ek++;

		ek = ek + _strlen_recursion(s+1);
	} return (ek);

}

/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL) return NULL;
	int i = 0, wordStart = 0;
	char *newString = (char *)malloc(100 * sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0') wordStart = i + 1;
		i++;
	}
	i = 0;
	while (str[wordStart] != '\0' && str[wordStart] != ' ')
	{
		newString[i] = str[wordStart];
		i++;
		wordStart++;
	}
	newString[i] = '\0';
	return newString;
}

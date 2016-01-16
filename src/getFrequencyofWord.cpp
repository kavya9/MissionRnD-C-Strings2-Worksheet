/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int length(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
int count_word_in_str_way_1(char *str, char *word){
	if (str == NULL || word == NULL) return 0;
	int i = 0, j, wordLen, count, wordCount = 0;
	wordLen = length(word);
	while (str[i] != '\0')
	{
		j = 0;
		count = 0;
		while (str[i] == word[j] && str[i] != '\0')
		{
			i++;
			j++;
			count++;
		}

		if (count == wordLen)
		{
			count = 0;
			wordCount++;
			i = i - (wordLen - 1);
		}
		else i++;
	}
	return wordCount;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	if (str == NULL || word == NULL) return 0;
	int  i, flag;
	if (*str == '\0')
	{
		return 0;
	}
	i = 0, flag = 0;
	while (word[i] != '\0')
	{
		if (str[i] != word[i])
		{
			flag++;
			break;
		}
		i++;
	}
	if (!flag)
		return count_word_int_str_way_2_recursion(str + 1, word) + 1;
	else return count_word_int_str_way_2_recursion(str + 1, word);
}


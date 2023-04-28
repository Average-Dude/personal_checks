#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@num: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int num)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < num - 1)
    {
        dest[i] = src[i];
        i++;
    }
    if (i < num)
    {
        j = i;
        while (j < num)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@num: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int num)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < num)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < num)
        dest[i] = '\0';
    return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character being searched
 *Return: (s) a pointer to the memory area of @s
 */
char *_strchr(char *s, char c)
{
    do
    {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}

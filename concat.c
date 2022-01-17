/*
** EPITECH PROJECT, 2022
** ex02
** File description:
** concat
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1)) + (strlen(str2)));
    *res = strcat(strdup(str1), str2);
}

void concat_struct(concat_t *str)
{
    str->res = malloc(sizeof(char) * (strlen(str->str1) + (strlen(str->str2))));
    str->res = strcat(strdup(str->str1), str->str2);
}

static void test_concat_strings ( void )
{
    char str1 [] = "I find your lack of faith ... ";
    char str2 [] = " disturbing .";
    char * res = NULL ;
    concat_strings ( str1 , str2 , & res ) ;
    printf ("%s\n", res ) ;
    free ( res ) ;
}

static void test_concat_struct ( void )
{
    char str1 [] = " These aren 't the Droids ";
    char str2 [] = " you 're looking for .";
    concat_t str = {
    . str1 = str1 ,
    . str2 = str2 ,
    . res = NULL
    };
    concat_struct (& str ) ;
    printf ("%s\n", str . res ) ;
    free ( str . res ) ;
}

int main ( void )
{
    test_concat_strings () ;
    test_concat_struct () ;
    return (0) ;
}
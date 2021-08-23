/*
 * Task1, task1.c
 * Purpose: write a function that copies a string to a new one
 * dynamically allocated. The function should return the new string address
 * or NULL in case of error. Avoid using the standard functions from string.h.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * This identifier is used as a code to identify whether a function call was successfull
 * or an error occured.
 */
#define STR_ERR -1

/*
 * The prototype of the function that copies a string to a new one
 * dynamically allocated.
 */
char * copy_string(const char *src_string);

/*
 * The prototype of the function that gets string length.
 */
size_t get_str_length(const char *src_string);

/*
 * The main function of the program.
 * Demonstration of using the function that copies a string to a new one
 * dynamically allocated.
 * DO NOT FORGET to free dynamically allocated memory to prevent memory leakage!
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        char src_str[] = "This is the source string to copy.";
        char *dest_str;

        dest_str = copy_string(src_str);

        if(dest_str != NULL){
                printf("SOURCE STRING: \"%s\", LENGTH=%ld\n", src_str, get_str_length(src_str));
                printf("COPIED STRING: \"%s\", LENGTH=%ld\n", dest_str, get_str_length(dest_str));
                free(dest_str);
        } else {
                printf("An error occured while copying string!\n");
        }

        return 0;
}

/*
 * The function copies a string to a new one dynamically allocated.
 *
 * @param src_string a pointer to an array of char that contains a string to copy to a new one
 * @return a pointer to an array of char allocated dynamically that contains the copy of a source string
 * (i.e. the new string address), or NULL in case of error
 */
char * copy_string(const char *src_string)
{
        if(src_string == NULL){
                return NULL;
        }

        size_t length = get_str_length(src_string);
        if(length == STR_ERR){
                return NULL;
        }

        char *dest_string = NULL;
        dest_string = malloc(length + 1);

        if(dest_string != NULL){
                for(int i = 0; i < length; i++){
                        dest_string[i] = src_string[i];
                }
                dest_string[length] = '\0';
        }

        return dest_string;
}

/*
 * The function gets the length of a C string.
 *
 * @param src_string a pointer to an array of char that contains a string the length of which to find
 * @return the length of a C string or STR_ERR if the function argument is not valid
 */
size_t get_str_length(const char *src_string)
{
        if(src_string == NULL){
                return STR_ERR;
        }

        unsigned int length = 0;

        while(src_string[length] != '\0'){
                length++;
        }

        return length;
}

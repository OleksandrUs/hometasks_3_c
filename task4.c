/*
 * Task4, task4.c
 * Purpose: write the "map" function that receives an array of items, its size, 
 * and a function to apply individually to each item of the array.
 * "map" could modify existing array or return a new one.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 23/08/2021
 */

#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * This identifier is used to indicate the dimension of the array in the demo program.
 */
#define ARRAY_SIZE 5

/*
 * The enumeration describes possible modes of operation of the map() function. 
 */
enum MODE {
        // The map() function creates new array with modified items and returns the pointer on it.
        copy_array = 0,
        // The map() function modifies items in the original array.
        modify_array = 1
};

/*
 * The structure describes an item that contains data and is stored in an array.
 */
struct ITEM {
        int value;
};

/*
 * Function prototypes.
 */
struct ITEM * map(struct ITEM *array, size_t size, void (*func)(struct ITEM *item), enum MODE mode);
void square(struct ITEM *item);
void invert(struct ITEM *item);
void modulus(struct ITEM *item);
void print_item(struct ITEM *item);
void run_demo_1(void);
void run_demo_2(void);

/*
 * The main function of the program (entry point).
 * Demonstration of using the map() function.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        run_demo_1();
        run_demo_2();
        return 0;
}

/*
 * This function receives an array of items, its size,and a function to apply individually 
 * to each item of the array. This function can modify existing array or return a new one.
 * The function returns the pointer to the original (existing) array if mode is modify_array,
 * or the pointer to a new dynamically allocated array with modified elements from the existing
 * array by applying to each of them the func() function that is the parameter of this function.
 * In this case, dynamically allocated memory must be freed after the new array is not needed.
 * 
 * @param array the pointer to the original array of items 
 * @param size the number of elements in the array
 * @param func a pointer to a function that will be applied individually to each element of the array
 * @param mode defines if the items in the existing array will be modified (modify_array) or
 * a new array will be created (copy_array) and items in the original array will remain unchanged. 
 * @return the pointer to an instance of the ITEM data structure (i.e. the first element
 * of an array of items), or NULL if an error occured.
 */
struct ITEM * map(struct ITEM *array, size_t size, void (*func)(struct ITEM *item), enum MODE mode)
{
        if((array == NULL) || (size == 0) || (func == NULL))
        {
                return NULL;
        }

        if(mode == modify_array) {

                for(int i = 0; i < size; i++) {
                        func(&array[i]);
                }

                return array;

        } else if(mode == copy_array) {

                struct ITEM *new_array = (struct ITEM *)malloc(size * sizeof(struct ITEM));
              
                if(new_array != NULL) {

                        for(int i = 0; i < size; i++) {
                                new_array[i] = array[i];
                        }

                        for(int i = 0; i < size; i++) {
                                func(&new_array[i]);
                        }

                        return new_array;
                }
        }
        return NULL;
}

/*
 * The function squares the value of an element.
 *
 * @param a pointer to an instance of the ITEM structure
 */
void square(struct ITEM *item)
{
        item->value = pow(item->value, 2);
}

/*
 * The function inverts the sign of the value of an element.
 *
 * @param a pointer to an instance of the ITEM structure
 */
void invert(struct ITEM *item)
{
        item->value *= -1;
}

/*
 * The function finds the absolute value of an element.
 *
 * @param a pointer to an instance of the ITEM structure
 */
void modulus(struct ITEM *item)
{
        item->value = abs(item->value);
}

/*
 * The function prints the value of an item in the console window.
 * This function does not change the items that are in the array and the 
 * behavior of this function does not depend on the mode parameter in the map() function.
 * But to improve the efficiency and prevent the creation of a copy of
 * the original array, it is recommended to use this function with the mode parameter
 * in the map() function equal to 'modify_array'. 
 */
void print_item(struct ITEM *item)
{
        printf("%d\t", item->value);
}

/*
 * The function is used for demonstration of using the map() function. The elements
 * of the original array are modified by applying to each of them some functions.
 */
void run_demo_1(void)
{
        struct ITEM array[ARRAY_SIZE] = {{1}, {-2}, {3}, {-4}, {5}};
         
        // Print all elements of the original array.
        printf("\n\n=======The \"map\" function modifies all items in the existing array.=======\n");
        printf("\nPrint all items that are in the array.\n");
        map(array, ARRAY_SIZE, print_item, modify_array);

        // Invert the sing of the each element in the array. 
        map(array, ARRAY_SIZE, invert, modify_array);
        printf("\n\nPrint all items after their sign was inverted.\n");
        map(array, ARRAY_SIZE, print_item, modify_array);

        // Find modulus of each element in the array. 
        map(array, ARRAY_SIZE, modulus, modify_array);
        printf("\n\nPrint the absolute value of each item in the array.\n");
        map(array, ARRAY_SIZE, print_item, modify_array);

        // Square each element of the array. 
        map(array, ARRAY_SIZE, square, modify_array);
        printf("\n\nPrint the squares of the elements that are in the array.\n");
        map(array, ARRAY_SIZE, print_item, modify_array);
        
        // Print all elements of the original array.
        printf("\n\nPrint all items that are in the source array (the elements was modified).\n");
        map(array, ARRAY_SIZE, print_item, modify_array);
}

/*
 * The function is used for demonstration of using the map() function. The elements
 * of the original array are not modified and the map() function returns a pointer
 * to a new array that contains modified elements from the original array by applying
 * some functions to each of them.
 */
void run_demo_2(void)
{
        struct ITEM src_array[ARRAY_SIZE] = {{1}, {-2}, {3}, {-4}, {5}};
        struct ITEM *new_array;
        
        // Print all elements of the original array.
        printf("\n\n=======The \"map\" function returns the new array with modified items.=======\n");
        printf("\nPrint all items that are in the source array.\n");
        map(src_array, ARRAY_SIZE, print_item, modify_array);

        // Invert the sing of the each element in the array and put it in the new one. 
        new_array = map(src_array, ARRAY_SIZE, invert, copy_array);
        printf("\n\nPrint all items in the new array after their sign was inverted.\n");
        map(new_array, ARRAY_SIZE, print_item, modify_array);
        free(new_array);

        // Find modulus of each element in the array and put it in the new one. 
        new_array = map(src_array, ARRAY_SIZE, modulus, copy_array);
        printf("\n\nPrint the absolute value of each item in the new array.\n");
        map(new_array, ARRAY_SIZE, print_item, modify_array);
        free(new_array);

        // Square each element of the array and put it in the new one. 
        new_array = map(src_array, ARRAY_SIZE, square, copy_array);
        printf("\n\nPrint the squares of the elements that are in the new array.\n");
        map(new_array, ARRAY_SIZE, print_item, modify_array);
        free(new_array);

        // Print all elements of the original array.
        printf("\n\nPrint all items that are in the source array (elements wasn't modified).\n");
        map(src_array, ARRAY_SIZE, print_item, modify_array);
}

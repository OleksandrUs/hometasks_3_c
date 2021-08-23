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

#define ARRAY_SIZE 5

enum MODE {
        copy_array = 0,
        modify_array = 1
};

struct ITEM{
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
 * Demonstration of using the "map" function.
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

struct ITEM * map(struct ITEM *array, size_t size, void (*func)(struct ITEM *item), enum MODE mode)
{
        if((array == NULL) || (size == 0) || (func == NULL))
        {
                return NULL;
        }

        if(mode == modify_array){

                for(int i = 0; i < size; i++){
                        func(&array[i]);
                }

                return array;

        } else if(mode == copy_array){

                struct ITEM *new_array = (struct ITEM *)malloc(size * sizeof(struct ITEM));
              
                if(new_array != NULL){

                        for(int i = 0; i < size; i++){
                                new_array[i] = array[i];
                        }

                        for(int i = 0; i < size; i++){
                                func(&new_array[i]);
                        }

                        return new_array;
                }
        }
        return NULL;
}

void square(struct ITEM *item)
{
        item->value = pow(item->value, 2);
}

void invert(struct ITEM *item)
{
        item->value *= -1;
}

void modulus(struct ITEM *item)
{
        item->value = abs(item->value);
}

/*
 * This function does not change the items that are in the array and the 
 * behavior of this function does not depend on the mode parameter in the map() function.
 * But to improve the efficiency and prevent the creation of a copy of
 * the array, it is recommended to use this function with the mode parameter
 * in the map() function equal to 'modify_array'. 
 */
void print_item(struct ITEM *item)
{
        printf("%d\t", item->value);
}

void run_demo_1(void)
{
        struct ITEM array[ARRAY_SIZE] = {{1}, {-2}, {3}, {-4}, {5}};
         
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

        printf("\n\nPrint all items that are in the source array (the elements was modified).\n");
        map(array, ARRAY_SIZE, print_item, modify_array);
}

void run_demo_2(void)
{
        struct ITEM src_array[ARRAY_SIZE] = {{1}, {-2}, {3}, {-4}, {5}};
        struct ITEM *new_array;
         
        printf("\n\n=======The \"map\" function returns the new array with modified items.=======\n");
        printf("\nPrint all items that are in the source array.\n");
        map(src_array, ARRAY_SIZE, print_item, modify_array);

        // Invert the sing of the each element in the array. 
        new_array = map(src_array, ARRAY_SIZE, invert, copy_array);
        printf("\n\nPrint all items in the new array after their sign was inverted.\n");
        map(new_array, ARRAY_SIZE, print_item, modify_array);
        free(new_array);

        // Find modulus of each element in the array. 
        new_array = map(src_array, ARRAY_SIZE, modulus, copy_array);
        printf("\n\nPrint the absolute value of each item in the new array.\n");
        map(new_array, ARRAY_SIZE, print_item, modify_array);
        free(new_array);

        // Square each element of the array. 
        new_array = map(src_array, ARRAY_SIZE, square, copy_array);
        printf("\n\nPrint the squares of the elements that are in the new array.\n");
        map(new_array, ARRAY_SIZE, print_item, modify_array);
        free(new_array);

        printf("\n\nPrint all items that are in the source array (elements wasn't modified).\n");
        map(src_array, ARRAY_SIZE, print_item, modify_array);
}

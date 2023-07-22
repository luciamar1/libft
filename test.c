#include <stdio.h>
#include <stdlib.h>

void	valgrind(void)
 {
 	system("valgrind -s --leak-check=full ./so_long");

 }

void paso(char *array)
{
   // free(array);
    *array = 'j';
    //return(array);
}

int main(void)
{
    int i = 4;
    int counter = 0;
    char *array = calloc(5, sizeof(char));
    while(i)
    {
        array[counter++] = 'a';
        i--;
    }
    printf("array == %s\n", array);
    paso(array);
    printf("array == %s\n", array);
    //valgrind();

}
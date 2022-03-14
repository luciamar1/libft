
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void    *ft_memset(void *s, int c, size_t n)
{
        size_t i;

        i = 0;
        while (i < n)
                ((char *)s)[i++] = (unsigned char) c;
        return (s);
}

int main (void)
{
        char    s[20] = "hola soy super guay\n";
        ft_memset(s, '-', 5);
        printf("%s\n", s);
        return (0);
}

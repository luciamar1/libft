#include <unistd.h>
int main(void)
{
        printf("%s\n", get_next_line(STDIN_FILENO));
        printf("%s\n", get_next_line(STDIN_FILENO));
        printf("%s\n", get_next_line(STDIN_FILENO));
        return(0):
}
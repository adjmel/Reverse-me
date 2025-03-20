//gcc source.c -o level1

#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    char input[100];
    char key[] = "__stack_check";

    printf("Please enter key: ");
    scanf("%s", input);

    if (strcmp(input, key) != 0)
        printf("Nope.\n");
    else
        printf("Good job.\n");

    return 0;
}

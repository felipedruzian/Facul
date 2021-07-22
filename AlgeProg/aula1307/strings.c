#include <stdio.h> // gets();
#include <string.h>

int main() {

    char text[2];

    printf("Digite algo: ");
    gets(text);

    printf("Texto digitado: \n");
    puts(text);


    return 0;
}
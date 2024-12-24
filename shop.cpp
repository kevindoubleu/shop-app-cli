#include <stdio.h>

void main() {
    printf("#############################\n");
    printf("#  Welcome to kevin's shop  #\n");
    printf("#############################\n");
    printf("mau pesen apa bro\n");
    printf("1. nasi\n");
    printf("2. bakmi\n");

    char user_input[1];
    printf("hmm gw mau ");
    scanf("%s", &user_input);
    printf("oh lu mau pesen %s oke\n", user_input);
}

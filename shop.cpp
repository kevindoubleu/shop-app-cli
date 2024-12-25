#include <stdio.h>

int main() {
    printf("#############################\n");
    printf("#  Welcome to kevin's shop  #\n");
    printf("#############################\n");
    printf("mau pesen apa bro\n");
    printf("1. nasi\n");
    printf("2. bakmi\n");

    int user_input = 0;
    printf("hmm gw mau ");
    scanf("%d", &user_input);
    printf("oh lu mau pesen nomor %d oke\n", user_input);
}

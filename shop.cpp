#include <stdio.h>

int main() {
    printf("#############################\n");
    printf("#  Welcome to kevin's shop  #\n");
    printf("#############################\n");
    printf("mau pesen apa bro\n");
    printf("1. nasi\n");
    printf("2. bakmi\n");

    int user_input = 0;
    printf("hmm gw mau nomor ");
    scanf("%d", &user_input);

    switch (user_input)
    {
        case 1:
            printf("oh lu mau pesen nasi oke\n");
            break;
        case 2:
            printf("oh lu mau pesen bakmi oke\n");
            break;
        default:
            printf("lu mau pesen apa sih, nomor 1 ato 2 pilih\n");
            break;
    }
}

#include <stdio.h>

int main() {
    printf("#############################\n");
    printf("#   Welcome to my warteg    #\n");
    printf("#############################\n");
    printf("mau pesen apa dek\n");
    printf("1. nasi\n");
    printf("2. bakmi\n");
    printf("2. es krim\n");

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
        case 3:
            printf("oh lu mau es krim aja oke\n");
            break;
        default:
            printf("lu mau pesen apa sih, pilih nomor 1-3\n");
            break;
    }
}

#include <stdio.h>

int main() {
    printf("#############################\n");
    printf("#   Welcome to my warteg    #\n");
    printf("#############################\n");
    printf("mau pesen apa dek\n");
    printf("1. nasi\n");
    printf("2. bakmi\n");
    printf("3. es krim\n");

    int user_input = 0;
    // selama user input diluar dari yg kita expect
    while (user_input < 1 || user_input > 3)
    {
        // tanya user mau apa
        printf("hmm gw mau nomor ");
        scanf("%d", &user_input);

        // kasih feedback ke user tentang pilihannya
        if (user_input == 1)
        {
            printf("oh lu mau pesen nasi oke\n");
        }
        else if (user_input == 2)
        {
            printf("oh lu mau pesen bakmi oke\n");
        }
        else if (user_input == 3)
        {
            printf("oh lu mau es krim aja oke\n");
        }
        else
        {
            printf("lu mau pesen apa sih, pilih nomor 1-3\n");
        }
    }
}

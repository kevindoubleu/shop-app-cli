#include <stdio.h>

int main() {
    // welcome + menu
    printf("#############################\n");
    printf("#   Welcome to my warteg    #\n");
    printf("#############################\n");
    printf("mau pesen apa dek\n");
    printf("1. nasi\n");
    printf("2. bakmi\n");
    printf("3. es krim\n");
    printf("4. exit, ga jadi\n");

    // list feedback buat dikasih ke user
    char feedback_1[] = "oh lu mau pesen nasi oke";
    char feedback_2[] = "oh lu mau pesen bakmi oke";
    char feedback_3[] = "oh lu mau es krim aja oke";
    char feedback_4[] = "oh ga jadi yaudah gpp";
    char feedback_invalid_input[] = "lu mau pesen apa sih, pilih nomor 1-3";

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
            printf("option 1: %s\n", feedback_1);
        }
        else if (user_input == 2)
        {
            printf("option 2: %s\n", feedback_2);
        }
        else if (user_input == 3)
        {
            printf("option 3: %s\n", feedback_3);
        }
        else if (user_input == 4)
        {
            printf("option 4: %s\n", feedback_4);
            break;
        }
        else
        {
            printf("%s\n", feedback_invalid_input);
        }
    }

    printf("terima kasih udah dateng ke my warteg\n");
}

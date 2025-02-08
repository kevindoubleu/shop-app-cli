#include <stdio.h>

void print_welcome_banner() {
    printf("#############################\n");
    printf("#   Welcome to my warteg    #\n");
    printf("#############################\n");
    printf("mau pesen apa dek\n");
}

void print_menu(char menu[][50], int menu_count) {
    for (int menu_number = 0; menu_number < menu_count; menu_number++)
    {
        printf("%d. %s\n", menu_number+1, menu[menu_number]);
    }
}

int main() {
    print_welcome_banner();

    char menu[][50] = {
        "nasi",
        "bakmi",
        "es krim",
        "exit, ga jadi"
    };
    print_menu(menu, 4);

    // list feedback buat dikasih ke user
    char feedback[][50] = {
        "oh lu mau pesen nasi oke",
        "oh lu mau pesen bakmi oke",
        "oh lu mau es krim aja oke",
        "oh ga jadi yaudah gpp",
    };
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
            printf("option 1: %s\n", feedback[0]);
        }
        else if (user_input == 2)
        {
            printf("option 2: %s\n", feedback[1]);
        }
        else if (user_input == 3)
        {
            printf("option 3: %s\n", feedback[2]);
        }
        else if (user_input == 4)
        {
            printf("option 4: %s\n", feedback[3]);
            break;
        }
        else
        {
            printf("%s\n", feedback_invalid_input);
        }
    }

    printf("terima kasih udah dateng ke my warteg\n");
}

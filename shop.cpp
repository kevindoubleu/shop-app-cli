#include <stdio.h>

void print_welcome_banner();
void print_menu(char menu[][50], int menu_count);
int ask_user_input(char feedback[][50], char feedback_invalid_input[]);

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
    int user_choice = ask_user_input(feedback, feedback_invalid_input);
    
    printf("terima kasih udah dateng ke my warteg\n");
}

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

int ask_user_input(char feedback[][50], char feedback_invalid_input[]) {
    int user_input = 0;

    printf("hmm gw mau nomor > ");
    scanf("%d", &user_input);

    // user input is invalid number
    if (user_input < 1 || user_input > 4)
    {
        printf("%s\n", feedback_invalid_input);
        return 0;
    }
    
    printf("lu pilih nomor %d: %s\n", user_input, feedback[user_input-1]);
    return user_input;
}

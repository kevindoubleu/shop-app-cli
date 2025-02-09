#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "banner.cpp"

void menu_prompt(Menu menus[], int menu_count);
int prompt_user_for_input(const char* prompt);

int total = 0;
char cart[10] = "";

int main() {
    Menu menu_list[100];
    int menu_count = populate_menu(menu_list);
    menu_prompt(menu_list, menu_count);
    
    print_exit_banner(total);
    print_cart(cart, true);
}

void menu_prompt(Menu menus[], int menu_count) {
    while (true)
    {
        print_welcome_banner();
        print_menu(menus, menu_count, total);
        print_cart(cart, false);

        int choice = prompt_user_for_input("I'd like to order number > ");

        // if user is done
        if (choice == 0) break;
        
        Menu ordered = menus[choice-1];
        total += ordered.price;
        strcat(cart, ordered.emoji);
        strcat(cart, " ");
        animate_order_process(ordered);
    }
}

int prompt_user_for_input(const char* prompt) {
    int choice = 0;

    while (true)
    {
        printf("%s", prompt);
        int successful_reads = scanf("%d", &choice);
        if (successful_reads != 1 || choice < 0 || choice > 4)
        {
            int c = getchar();
            while (c != '\n') c = getchar();
            continue;
        }
        break;
    }

    return choice;
}

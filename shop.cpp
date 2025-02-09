#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "banner.cpp"

void ask_user_input(Menu menus[], int menu_count);
void build_menu_detail(Menu menu, char* result);
int prompt_user(const char* prompt);

int total = 0;

int main() {
    Menu menu_list[100];
    int menu_count = populate_menu(menu_list);
    ask_user_input(menu_list, menu_count);
    
    printf("terima kasih udah dateng ke my warteg 🖐 😁\n");
}

void ask_user_input(Menu menus[], int menu_count) {
    while (true)
    {
        print_welcome_banner();
        print_menu(menus, menu_count);
        print_subtotal(total);

        int choice = prompt_user("I'd like to order number > ");

        // if user is done
        if (choice == 0)
        {
            break;
        }

        // if user input is invalid number
        if (choice < 1 || choice > menu_count)
        {
            printf("pilih yg bener bro, adanya cuman 1-%d\n", menu_count);
            continue;
        }
        
        char menu_detail[100] = "";
        total += menus[choice-1].price;
        animate_order_process();
    }
}

int prompt_user(const char* prompt) {
    int choice = 0;

    while (true)
    {
        printf("%s", prompt);
        int successful_reads = scanf("%d", &choice);
        if (successful_reads != 1)
        {
            int c = getchar();
            while (c != '\n')
            {
                c = getchar();
            }
            continue;
        }
        break;
    }

    return choice;
}

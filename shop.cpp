#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu_list.cpp"
#include "banner.cpp"

void ask_user_input(Menu menus[], int menu_count);
void print_menu(Menu menus[], int menu_count);
void build_menu_detail(Menu menu, char* result);

int total = 0;

int main() {
    print_welcome_banner();

    Menu menu_list[100];
    int menu_count = populate_menu(menu_list);
    ask_user_input(menu_list, menu_count);
    
    printf("terima kasih udah dateng ke my warteg 🖐 😁\n");
}

void print_menu(Menu menus[], int menu_count) {
    if (total > 0) print_what_else_banner();

    for (int i = 0; i < menu_count; i++)
    {
        printf("%d. %s\n", i+1, menus[i].name);
    }

    if (total == 0)
    {
        printf("0. ga jadi\n");
    }
    else
    {
        printf("0. udah itu aja\n");
        printf("#############################\n");
        printf("Total: Rp%d.000,-\n", total);
    }

    printf("#############################\n");
}

void ask_user_input(Menu menus[], int menu_count) {
    int choice = 0;

    while (true)
    {
        print_menu(menus, menu_count);

        printf("hmm gw mau nomor > ");
        scanf("%d", &choice);
        fflush(stdin);

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
        build_menu_detail(menus[choice-1], menu_detail);
        printf("oke gw bikinin nomor %d\n%s\n", choice, menu_detail);
        total += menus[choice-1].price;
    }
}

void build_menu_detail(Menu menu, char* result) {
    snprintf(result, 100, "Menu %s\n%s\nHarga: Rp%d.000,-\n", menu.name, menu.description, menu.price);
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Menu
{
    const char* name;
    const char* description;
    int price;
};

void print_welcome_banner();
void ask_user_input(Menu menus[], int menu_count);
void print_menu(Menu menus[], int menu_count);
void print_what_else_banner();
void build_menu_detail(Menu menu, char* result);

int total = 0;

int main() {
    print_welcome_banner();

    Menu nasi = {
        .name = "nasi",
        .description = "nasi putih",
        .price = 5
    };
    Menu bakmi = {
        .name = "bakmi",
        .description = "bakmi ayam",
        .price = 20
    };
    Menu eskrim = {
        .name = "es krim",
        .description = "es krim vanilla 1 scoop",
        .price = 8
    };
    Menu menus[] = {
        nasi,
        bakmi,
        eskrim
    };
    
    ask_user_input(menus, 3);
    
    printf("terima kasih udah dateng ke my warteg 🖐 😁\n");
}

void print_welcome_banner() {
    printf("#############################\n");
    printf("#   Welcome to my warteg    #\n");
    printf("#############################\n");
    printf("mau pesen apa dek\n");
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

void print_what_else_banner() {
    printf("#############################\n");
    printf("#    Mau pesen apa lagi?    #\n");
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

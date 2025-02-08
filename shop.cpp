#include <stdio.h>

struct Menu
{
    const char* name;
    const char* description;
    int price;
};

void print_welcome_banner();
void print_menu(Menu menus[], int menu_count);
int ask_user_input(Menu menus[], int menu_count);
void build_menu_detail(Menu menu, char* result);

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
    
    print_menu(menus, 3);

    ask_user_input(menus, 3);
    
    printf("terima kasih udah dateng ke my warteg\n");
}

void print_welcome_banner() {
    printf("#############################\n");
    printf("#   Welcome to my warteg    #\n");
    printf("#############################\n");
    printf("mau pesen apa dek\n");
}

void print_menu(Menu menus[], int menu_count) {
    for (int i = 0; i < menu_count; i++)
    {
        printf("%d. %s\n", i+1, menus[i].name);
    }
}

int ask_user_input(Menu menus[], int menu_count) {
    int user_input = 0;

    printf("hmm gw mau nomor > ");
    scanf("%d", &user_input);

    // user input is invalid number
    if (user_input < 1 || user_input > menu_count)
    {
        printf("pilih yg bener bro, adanya cuman 1-%d\n", menu_count);
        return 0;
    }
    
    char menu_detail[100] = "";
    build_menu_detail(menus[user_input-1], menu_detail);
    printf("oke gw bikinin nomor %d\n%s\n", user_input, menu_detail);
    return user_input;
}

void build_menu_detail(Menu menu, char* result) {
    snprintf(result, 100, "Menu %s\n%s\nHarga: Rp%d.000,-\n", menu.name, menu.description, menu.price);
}

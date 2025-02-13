#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "menu.cpp"

const char* RESET = "\033[0m";

const char* BOLD = "\033[1m";
    
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* CYAN = "\033[36m";
const char* BLACK = "\033[30m";

const char* GREEN_BG = "\033[42m";
const char* WHITE_BG = "\033[47m";

/**
 *********************************************************
 * default terminal width is assumed to be 40 chars wide *
 *********************************************************
 */

/**
 * Prints banner when the user first enters
 */
void print_welcome_banner() {
    printf("\n\n");
    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", YELLOW);
    printf("┃ %s 🍜 🍉 🍪 🍤 🥗 🍓 🍩 🍣 🍇 🍕 🍔 🍎%s%s ┃\n", GREEN_BG, RESET, YELLOW);
    printf("┃                                      ┃\n");
    printf("┃             %sWELCOME TO               %s┃\n", RESET, YELLOW);
    printf("┃          🥝 %s%sKIWI  SHOP 🥝            %s%s┃\n", GREEN, BOLD, RESET, YELLOW);
    printf("┃                                      ┃\n");
    printf("┃ %s🍎 🍔 🍕 🍇 🍣 🍩 🍓 🥗 🍤 🍪 🍉 🍜 %s%s ┃\n", GREEN_BG, RESET, YELLOW);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("%s\n", RESET);
}

void print_menu(Menu list[], int count, int total) {
    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", CYAN);
    printf("┃                                      ┃\n");
    printf("┃  %sWhat would you like to order?%s 🍽️     ┃\n", YELLOW, CYAN);
    printf("┃                                      ┃\n");

    for (int i = 0; i < count; i++)
    {
        char formatted_price[50];
        snprintf(formatted_price, 50, "Rp%d.000,-", list[i].price);
        printf("┃%s %2d ) %-15s%15s  %s┃\n", RESET, i+1, list[i].name, formatted_price, CYAN);
    }

    printf("┃ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ┃\n");

    if (total > 0)
    {
        char formatted_total[50];
        snprintf(formatted_total, 50, "Rp%d.000,-", total);
        printf("┃ %s%s %-17s%17s %s%s ┃\n", 
            WHITE_BG, BLACK,
            "0 ) Checkout cart", formatted_total,
            RESET, CYAN);
    }
    else
    {
        printf("┃%s  0 ) Exit                            %s┃\n", RESET, CYAN);
    }
    
    printf("┃                                      ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("%s\n", RESET);
}

void print_cart(char* cart, bool checkout) {
    if (strlen(cart) == 0) return;

    const char* prompt = "In cart";
    if (checkout) prompt = "Cooking up";

    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", GREEN);
    printf("┃ %s%s: %s\n", RESET, prompt, cart);
    printf("%s┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n", GREEN);
    printf("%s\n", RESET);
}

void animate_order_process(Menu item) {
    printf("%s\n", RESET);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃          Adding %s to cart           ┃\n", item.emoji);
    printf("┃                                      ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\033[2A");
    printf("\033[2C");
    for (int i = 0; i < 36; i++)
    {
        printf(".");
        usleep(20000);
        fflush(stdout);
    }
    printf("\033[2B\n");
}

void animate_checkout(char* cart) {
    if (strlen(cart) == 0) return;

    printf("%s\n", RESET);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃ Checking out %s\n", cart);
    printf("┃                                      ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\033[2A");
    printf("\033[2C");
    for (int i = 0; i < 36; i++)
    {
        printf(".");
        usleep(20000);
        fflush(stdout);
    }
    printf("\033[2B\n");
}

void print_exit_banner(int total) {
    if (total > 0)
    {
        printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", YELLOW);
        printf("┃          🥝 %s%sKIWI  SHOP 🥝            %s%s┃\n", GREEN, BOLD, RESET, YELLOW);
        printf("┃                                      ┃\n");
        printf("┃   %s%s Your total is Rp%d.000,- 📃 %s      %s┃\n", GREEN_BG, BLACK, total, RESET, YELLOW);
        printf("┃                                      ┃\n");
        printf("┃    %sPlease have a seat while we       %s┃\n", RESET, YELLOW);
        printf("┃       %scook up your order 🍳😋        %s┃\n", RESET, YELLOW);
        printf("┃                                      ┃\n");
        printf("┃           %sThank you 🖐 😁             %s┃\n", RESET, YELLOW);
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("%s\n", RESET);        
    }
    else
    {
        printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", YELLOW);
        printf("┃          🥝 %s%sKIWI  SHOP 🥝            %s%s┃\n", GREEN, BOLD, RESET, YELLOW);
        printf("┃                                      ┃\n");
        printf("┃   %sWe hope you enjoyed your visit 🥰  %s┃\n", RESET, YELLOW);
        printf("┃                                      ┃\n");
        printf("┃           %sThank you 🖐 😁             %s┃\n", RESET, YELLOW);
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("%s\n", RESET);
    }
}

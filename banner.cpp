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

void print_menu(Menu list[], int count) {
    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", CYAN);
    printf("┃                                      ┃\n");
    printf("┃  %sWhat would you like to order?%s 🧑‍🍳    ┃\n", YELLOW, CYAN);
    printf("┃                                      ┃\n");

    for (int i = 0; i < count; i++)
    {
        char formatted_price[50];
        snprintf(formatted_price, 50, "Rp%d.000,-", list[i].price);
        printf("┃%s %2d ) %-15s%15s  %s┃\n", RESET, i+1, list[i].name, formatted_price, CYAN);
    }

    printf("┃                                      ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("%s\n", RESET);
}

void print_subtotal(int subtotal) {
    if (subtotal == 0) return;

    char formatted_total[50];
    snprintf(formatted_total, 50, "Rp%d.000,-", subtotal);
    
    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n", GREEN);
    printf("┃ %s%s%s%-18s%18s%s%s ┃\n", RESET, WHITE_BG, BLACK, "Current total:", formatted_total, RESET, GREEN);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("%s\n", RESET);
}

void animate_order_process() {
    printf("%s\n", RESET);
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃              Processing              ┃\n");
    printf("┃                                      ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\033[2A");
    printf("\033[2C");
    for (int i = 0; i < 36; i++)
    {
        printf(".");
        usleep(10000);
        fflush(stdout);
    }
    printf("\033[2B\n");
}

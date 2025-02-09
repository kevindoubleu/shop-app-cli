// A single menu item the shop sells
struct Menu
{
    const char* name;
    const char* emoji;
    int price;
};

/**
 * Populates the `Menu list[]` with predefined items
 *
 * Returns the number of menu items populated into `list[]`
 */
int populate_menu(Menu list[]) {
    Menu nasi = {
        .name = "nasi",
        .emoji = "🍚",
        .price = 5
    };
    Menu bakmi = {
        .name = "bakmi",
        .emoji = "🍜",
        .price = 20
    };
    Menu eskrim = {
        .name = "es krim",
        .emoji = "🍦",
        .price = 8
    };

    list[0] = nasi;
    list[1] = bakmi;
    list[2] = eskrim;
    return 3;
}
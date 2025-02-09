// A single menu item the shop sells
struct Menu
{
    const char* name;
    const char* description;
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
        .price = 5
    };
    Menu bakmi = {
        .name = "bakmi",
        .price = 20
    };
    Menu eskrim = {
        .name = "es krim",
        .price = 8
    };

    list[0] = nasi;
    list[1] = bakmi;
    list[2] = eskrim;
    return 3;
}
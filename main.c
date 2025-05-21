#include <stdio.h>
#include <stdint.h>

typedef struct {

    char item_name[50];
    uint16_t item_code;
    uint16_t quantity;
    float price;

}Item_t;

Item_t items[50];
uint32_t item_count;

void displayMessages();
void addItem();
void deleteItem();
void updateItemQuantity();
void displayTotalInventoryValue();


int main(void) {

}

void displayMessages() {

    printf("Add new item press  (1)\n");
    printf("Delete item press   (2)\n");
    printf("Update item quantity    (3)\n");
    printf("Display total inventory value press (4)\n");
}
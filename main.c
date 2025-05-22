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
void addItem(Item_t *items,uint32_t *item_count);
void deleteItem();
void updateItemQuantity();
void displayTotalInventoryValue();


int main(void) {

    while (1) {
        uint32_t user_choise = 0;
        displayMessages();
        printf("Enter your choise: ");
        scanf("%d",&user_choise);

        switch (user_choise) {

            case 1:
                addItem(items,&item_count);
            break;
            case 2:
                deleteItem(items,&item_count);
            break;
            case 3:
                updateItemQuantity(items,&item_count);
            break;
            case 4:
                displayTotalInventoryValue(items,&item_count);
            break;
            default:
                printf("Invalid choose!!\n");
        }
    }

}

void displayMessages() {

    printf("Add new item press                  (1)\n");
    printf("Delete item press                   (2)\n");
    printf("Update item quantity                (3)\n");
    printf("Display total inventory value press (4)\n");
}

void addItem(Item_t *items, uint32_t *item_count) {

    uint32_t item_code = 0;
    printf("Enter new item code: ");
    scanf("%d",&item_code);

    for (uint32_t i = 0; i < *item_count; i++) {

        if(items[i].item_code==item_code) {
            printf("You can't use this code\n");
            return;
        }
    }

    items[*item_count].item_code = item_code;
    getchar();
    printf("Enter item name: ");
    scanf("%50[^\n]",&items[*item_count].item_name);
    printf("Enter quantity: ");
    scanf("%d",&items[*item_count].quantity);
    printf("Enter item price Rs: ");
    scanf("%f",&items[*item_count].price);
    (*item_count)++;
    printf("You have successfully added new item\n");
    printf("\n");
}

void updateItemQuantity(Item_t *items, uint32_t *item_count) {

    uint32_t item_code = 0;
    printf("Enter item code: ");
    scanf("%d",&item_code);

    for (uint32_t i = 0; i<*item_count; i++ ) {

        if(items[i].item_code == item_code) {

            printf("Update item quantity: ");
            scanf("%d",&items[i].quantity);
            printf("Update successfully\n");
            return;
        }
    }

}

void deleteItem(Item_t *items, uint32_t *item_count) {

    uint32_t item_code = 0;
    printf("Enter item code: ");
    scanf("%d",&item_code);

    for (uint32_t i = 0; i<*item_count; i++) {

        if (items[i].item_code == item_code) {

            for( uint32_t j = i; j < *item_count-1; j++) {
                items[j] = items[j+1];
            }

            (*item_count)--;
            return;
        }
    }
}

void displayTotalInventoryValue(Item_t *items,uint32_t *item_count) {

    float total_value = 0;
    for (uint32_t i = 0; i < *item_count; i++) {

        total_value += items[i].price * items[i].quantity;
    }

    printf("Total value is Rs.%0.2f\n2",total_value);
}
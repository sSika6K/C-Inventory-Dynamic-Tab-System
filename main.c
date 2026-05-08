#include <stdio.h>
#include <stdlib.h>

#include "inventory-system.h"
#include "display-system.h"

void chooseAction(int action, struct Inventory *inventory) {
    switch (displayMenu()) {
        case 1:
            initiateInventory(inventory);
            break;
        case 2:
            addObject(inventory);
        //case 3:
            //displayInventory;
    }
    if (action == 1) {
        initiateInventory(inventory);
    } else {
        displayMenu();
    }
}

int main(void) {

    struct Inventory inventory;
    chooseAction(displayMenu(), &inventory);
    return 0;
}

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
            //displayInventory(inventory);
        //case 4:
            //modifyObjectWeight(inventory);
        //case 5:
            //deleteLastObject(inventory);
        //case 6:
            //inventoryWeight(inventory);
        //case 7:
            //getHeaviestObject(inventory);
        //case 8:
            // quit();
        default:
            displayMenu();
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

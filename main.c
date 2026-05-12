#include "display-system.h"
#include "main.h"

void chooseAction(struct Inventory *inventory) {
    clear();
    switch (displayMenu()) {
        case 1:
            initiateInventory(inventory);
            chooseAction(inventory);
            break;
        case 2:
            checkInventory(inventory);
            addObject(inventory);
            chooseAction(inventory);
            break;
        case 3:
            checkInventory(inventory);
            displayInventory(inventory);
            chooseAction(inventory);
            break;
        case 4:
            checkInventory(inventory);
            modifyObjectWeight(inventory);
            chooseAction(inventory);
        case 5:
            checkInventory(inventory);
            deleteLastObject(inventory);
            chooseAction(inventory);
        case 6:
            checkInventory(inventory);
            inventoryWeight(inventory);
            chooseAction(inventory);
        case 7:
            checkInventory(inventory);
            getHeaviestObject(inventory);
            chooseAction(inventory);
        case 8:
            exitSystem(inventory);
        default:
            chooseAction(inventory);
    }
}

int main(void) {
    struct Inventory inventory;
    chooseAction(&inventory);
    return 0;
}

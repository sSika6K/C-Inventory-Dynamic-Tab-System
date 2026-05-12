#ifndef C_INVENTORY_DYNAMIC_TAB_SYSTEM_INVENTORY_SYSTEM_H
#define C_INVENTORY_DYNAMIC_TAB_SYSTEM_INVENTORY_SYSTEM_H

struct Inventory {
    int initialized;
    struct Object *objects;
    int size;
};

struct Object {
    int index;
    float weight;
};

void checkInventory(struct Inventory *inventory);
void getHeaviestObject(struct Inventory *inventory);
void exitSystem(struct Inventory *inventory);
void inventoryWeight(struct Inventory *inventory);
void deleteLastObject(struct Inventory *inventory);
void modifyObjectWeight(struct  Inventory *inventory);
void askObjectsSize(struct Inventory *inventory);
void initiateInventory(struct Inventory *inventory);
void addObject(struct Inventory *inventory);
void displayInventory(struct Inventory *inventory);

#endif //C_INVENTORY_DYNAMIC_TAB_SYSTEM_INVENTORY_SYSTEM_H

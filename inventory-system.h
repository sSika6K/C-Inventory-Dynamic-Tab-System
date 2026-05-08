//
// Created by arman on 07/05/2026.
//

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

int isInventory(struct Inventory *inventory);
void askObjectsSize(struct Inventory *inventory);
void initiateInventory(struct Inventory *inventory);
void addObject(struct Inventory *inventory);

#endif //C_INVENTORY_DYNAMIC_TAB_SYSTEM_INVENTORY_SYSTEM_H

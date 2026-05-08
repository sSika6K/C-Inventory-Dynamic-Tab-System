#include "inventory-system.h"

#include "display-system.h"

#include <stdio.h>
#include <stdlib.h>

int isInventory(struct Inventory *inventory) {
    if (!inventory->initialized) {
        clear();
        printf("Inventory value is not detected or NULL.");
        return 0;
    } else {
        return 1;
    }
}

void askObjectsSize(struct Inventory *inventory) {
    isInventory(inventory);
    for (int i = 0; i < inventory->size; i++) {
        if (inventory->objects[i].index != 1) {
            inventory->objects[i].index = i;
            clear();
            printf("Indiquer le poids de l'objet %d : ", i + 1);
            if (scanf("%f", &inventory->objects[i].weight) != 1) {
                askObjectsSize(inventory);
            }
        }
    }
}

void initiateInventory(struct Inventory *inventory) {

    inventory->initialized = 1;
    isInventory(inventory);

    clear();
    printf("Combien d'objets souhaitez-vous enregistrer ? \n\n");

    if (scanf("%i", &inventory->size) != 1) {
        inventory->size = 0;
        inventory->objects = NULL;
        return;
    }

    inventory->objects = malloc(inventory->size * sizeof(struct Object));

    askObjectsSize(inventory);
}

void addObject(struct Inventory *inventory) {
    if (inventory) {
        inventory->size++;
        inventory->objects = realloc(inventory->objects, inventory->size * sizeof(struct Object));
    } else {
        return;
    }
}

void displayInventory(struct Inventory *inventory) {

}

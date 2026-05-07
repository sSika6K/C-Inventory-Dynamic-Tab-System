#include "inventory-system.h"
#include <stdio.h>
#include <stdlib.h>

struct Object {
    int index;
    float weight;
};

struct Inventory {
    struct Object *objects;
    int size;
};

void initiateInventory() {

    struct Inventory inventory;

    printf("Combien d'objets souhaitez-vous enregistrer ? \n\n"), scanf("%i", &inventory.size);
    inventory.objects = malloc(inventory.size * sizeof(struct Object));
    printf("Taille de l'inventaire: %d \n\n", inventory.size);

    for (int i = 0; i < inventory.size; i++) {
        printf("Indiquer le poids de l'objet %d (en Kg) : ", i + 1);
        scanf("%f", &inventory.objects[i].weight);
    }
}


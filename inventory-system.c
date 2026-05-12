#include "inventory-system.h"

#include "display-system.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void averageInventoryWeight(struct Inventory *inventory) {
    clear();
    float total;
    int size;
    float result;
    for (size = 0; size < inventory->size; size++) {
        total += inventory->objects[size].weight;
    }
    result = total / size;
    printf("Le poids moyen de l'inventaire est de %f Kg.", result);
    Sleep(2000);
}

void resetInventory(struct Inventory *inventory) {
    clear();
    realloc(inventory->objects, sizeof(inventory->objects) * 0);
    inventory->size = 0;
    inventory->initialized = 0;
    printf("Inventaire reitinialisee.");
    Sleep(2000);
    initiateInventory(inventory);
}

void exitSystem(struct Inventory *inventory) {
    clear();
    printf("Au revoir !");
    Sleep(2000);
    clear();
    free(inventory);
    exit(EXIT_SUCCESS);
}

void checkInventory(struct Inventory *inventory) {
    if (inventory->size <= 0 || inventory->initialized != 1) {
        printf("Votre inventaire est vide ou non initialisee !");
        Sleep(2000);
        chooseAction(inventory);
    } else {
        return;
    }
}

void isInventory(struct Inventory *inventory) {
    if (inventory->initialized != 1) {
        printf("Votre inventaire n'est pas initialisee !");
        Sleep(2000);
        chooseAction(inventory);
    } else {
        return;
    }
}

void emptyInventory(struct Inventory *inventory) {
    clear();
    printf("Votre inventaire est vide !");
    Sleep(2000);
}

void askObjectsSize(struct Inventory *inventory) {
    if (inventory->initialized != 0) {
        int index = inventory->size - 1;
        clear();

        inventory->objects[index].index = index;

        printf("Indiquer le poids de l'objet %d : ", index + 1);

        playerChoiceFloat(&inventory->objects[index].weight);
    } else {
        for (int i = 0; i < inventory->size; i++) {
            clear();

            inventory->objects[i].index = i;

            printf("Indiquer le poids de l'objet %d : ", i + 1);

            playerChoiceFloat(&inventory->objects[i].weight);
        }
    }
}


void initiateInventory(struct Inventory *inventory) {
    if (inventory->initialized != 1) {
    inventory->initialized = 0;
    clear();
    printf("Combien d'objets souhaitez-vous enregistrer ? \n\n");
    playerChoiceInt(&inventory->size);

    inventory->objects = malloc(inventory->size * sizeof(struct Object));

    askObjectsSize(inventory);
    inventory->initialized = 1;

    clear();
    printf("Inventaire initialisee !");
    Sleep(2000);
    } else {
        clear();
        printf("Votre inventaire est deja initialisee !");
        Sleep(2000);
    }
}

void addObject(struct Inventory *inventory) {

    inventory->size++;
    inventory->objects = realloc(inventory->objects, inventory->size * sizeof(struct Object));

    askObjectsSize(inventory);

    clear();
    printf("Objet %i ajoutee.", inventory->size);
    Sleep(2000);
}

void displayInventory(struct Inventory *inventory) {
    clear();
    int player_choice;
    printf("===== INVENTAIRE =====\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("Objet %i : %f kg\n", inventory->objects[i].index + 1, inventory->objects[i].weight);
    }
    printf("\n \n Retour au menu ? \n 1. Oui \n 2. Non \n Votre choix: ");

    switch(playerChoiceInt(&player_choice)) {
        case 1:
            chooseAction(inventory);
        case 2:
            displayInventory(inventory);
        default:
            wrongInput();
            displayInventory(inventory);
    }
}

void modifyObjectWeight(struct Inventory *inventory) {
    clear();
    int player_choice;

    printf("Quel objet modifier ? \n \n" );

    playerChoiceInt(&player_choice);

    if (player_choice < 0 || player_choice > inventory->size) {
        wrongInput();
        modifyObjectWeight(inventory);
    } else {
        int *index = &player_choice;
        printf("%d", player_choice);
        clear();
        printf("Indiquer le poids de l'objet : ");
        playerChoiceFloat(&inventory->objects[*index - 1].weight);
        clear();
        printf("Objet %i modifiee.", player_choice);
        Sleep(2000);
    }
}

void deleteLastObject(struct Inventory *inventory) {
    clear();

    struct Inventory temp_inventory;

    inventory->size -= 1;

    temp_inventory.objects = malloc((inventory->size) * sizeof(struct Object));

    for (int i = 0; i < inventory->size; i++) {
        temp_inventory.objects[i].index = inventory->objects[i].index;
        temp_inventory.objects[i].weight = inventory->objects[i].weight;
    }

    inventory->objects = temp_inventory.objects;

    printf("Objet %i supprimee.", inventory->size + 1);
    Sleep(2000);
}

void inventoryWeight(struct Inventory *inventory) {
    clear();

    float total_weight;

    for (int i = 0; i < inventory->size; i++) {
        total_weight += inventory->objects[i].weight;
    }

    printf("Votre inventaire fait %f Kg.", total_weight);
    Sleep(2000);
}

void getHeaviestObject(struct Inventory *inventory) {
    clear();

    float heaviest_object_weight = -1;
    int heaviest_object_index = 0;

    for (int i = 0; i < inventory->size; i++) {
        if (inventory->objects[i].weight > heaviest_object_weight) {
            heaviest_object_weight = inventory->objects[i].weight;
            heaviest_object_index = i + 1;
        }
    }

    printf("L'object %i est le plus lourd, avec un poid de %f.", heaviest_object_index, heaviest_object_weight);
    Sleep(2000);
}

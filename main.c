#include <stdio.h>
#include "inventory-system.h"

int displayMenu() {
    int player_choice;
    printf("===== INVENTAIRE DE L'AVENTURIER ===== \n 1. Initialiser l'inventaire \n 2. Ajouter un objet \n"
           " 3. Afficher l'inventaire \n 4. Modifier le poids d'un objet \n 5. Supprimer le dernier objet \n"
           "6. Afficher le poids total \n 7. Afficher l'objet le plus lourd \n 8. Quitter \n \n Votre choix : ");
    if (scanf("%i", &player_choice) != 1) {
        displayMenu();
    } else {
        return player_choice;
    }
}

int main(void) {

    struct Inventory inventory;

    displayMenu();
    initiateInventory(&inventory);
    return 0;
}

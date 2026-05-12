#include "display-system.h"
#include <stdio.h>
#include <windows.h>

int playerChoiceInt(int *player_choice) {
    scanf("%i", player_choice);
    return *player_choice;
}

float playerChoiceFloat(float *player_choice) {
    scanf("%f", player_choice);
    return *player_choice;
}

void clear() {
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }
}

void wrongInput() {
    clear();
    printf("Veuillez entrer une valeur valide !");
    Sleep(2000);
}

int displayMenu() {
    int player_choice;
    clear();
    printf("===== INVENTAIRE DE L'AVENTURIER ===== \n 1. Initialiser l'inventaire \n 2. Ajouter un objet \n"
           " 3. Afficher l'inventaire \n 4. Modifier le poids d'un objet \n 5. Supprimer le dernier objet \n"
           " 6. Afficher le poids total \n 7. Afficher l'objet le plus lourd \n 8. Quitter \n \n Votre choix : ");
    playerChoiceInt(&player_choice);
    if (player_choice < 1 || player_choice > 8) {
        clear();
        wrongInput();
        displayMenu();
    } else {
        clear();
        return player_choice;
    }
}
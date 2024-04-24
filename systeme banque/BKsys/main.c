#include "bk.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int choix;
    bool authenticated = false; // indique si l'utilisateur est authentifi�

    // allocation dynamique de la m�moire
    info_p *perso = malloc(sizeof(info_p));
    info_s *sensible = malloc(sizeof(info_s));

    if (!perso || !sensible) {
        fprintf(stderr, "Erreur d'allocation m�moire\n");
        exit(1);
    }

    // boucle principale
    do {
        printf("\n======= MENU BANQUE =======\n\n");
        printf("%d - AUTHENTIFICATION\n", AUTHENTIFICATION);
        printf("%d - CREATION DE COMPTE\n", CREATION_DE_COMPTE);
        printf("%d - QUITTER\n", QUITTER);
        printf("\nSaisie du choix : ");
        scanf("%d", &choix);
        while (getchar() != '\n'); // Nettoyage du buffer

        switch (choix) {
        case AUTHENTIFICATION:
            authenticated = authentification(sensible);
            if (authenticated) {
                do {
                    choix = menu_compte_user(choix);
                    switch (choix) {
                    case RETRAIT:
                        break;
                    case DEPOT:
                        break;
                    case CONSULTATION_DU_SOLDE:
                        break;
                    case QUITTER:
                        break;
                    default:
                        printf("SAISIE INCORRECTE\n");
                        break;
                    }
                } while (choix != QUITTER);
            }
            break;
        case CREATION_DE_COMPTE:
            saisieInfoPerso(perso);
            saisieInfoSensible(sensible);
            sauvegarde_donnees(perso, sensible);
            break;
        case QUITTER:
            break;
        }
    } while (choix != QUITTER);

    // lib�ration de la m�moire allou�e
    free(perso);
    free(sensible);

    return 0;
}

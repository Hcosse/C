#include "bk.h"
#include <string.h>
#include <stdio.h>

int main()
{
    int choix;
    info_p perso;  // Utilisation de variables plutôt que de pointeurs
    info_s sensible;  // Utilisation de variables plutôt que de pointeurs

    do
    {
        printf("\n======= MENU BANQUE =======\n\n");
        printf("%d - AUTHENTIFICATION\n", AUTHENTIFICATION);
        printf("%d - CREATION DE COMPTE\n", CREATION_DE_COMPTE);
        printf("%d - QUITTER\n", QUITTER);
        printf("\nSaisie du choix : ");
        scanf(" %d", &choix);
        while (getchar() != '\n');

        switch(choix)
        {
        case AUTHENTIFICATION:
            choix = menu_compte_user(choix);
            break;
        case CREATION_DE_COMPTE:

            saisieInfoPerso(&perso);
            saisieInfoSensible(&sensible);
            sauvegarde_donnees(&perso, &sensible);

            break;
        case QUITTER:
            break;
        }
    }
    while (choix != QUITTER);

    return 0;
}

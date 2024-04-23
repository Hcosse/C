#include "bk.h"
#include <string.h>
#include <stdio.h>

int main()
{
    int choix;

    do
    {
        printf("\n");
        printf("======= MENU BANQUE =======\n");
        printf("\n");
        printf("  %d - AUTHENTIFICATION\n", AUTHENTIFICATION);
        printf("  %d - CREATION DE COMPTE\n", CREATION_DE_COMPTE);
        printf("  %d - QUITTER\n", QUITTER);
        printf("\n");
        printf(" Saisie du choix : ");
        scanf(" %d", &choix);

        switch(choix)
        {
        case AUTHENTIFICATION:
            choix = menu_compte_user(choix);
            break;
        case CREATION_DE_COMPTE:
            break;
        case QUITTER:
            break;
        }
    }
    while (choix != QUITTER);

    return 0;
}

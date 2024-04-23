#include "bk.h"
#include <stdlib.h>
#include<stdio.h>

int menu_compte_user(int choix_user)
{
    printf("\n");
    printf("===== MENU USER BANQUE =====\n");
    printf("\n");
    printf("%d - RETRAIT\n", RETRAIT);
    printf("%d - DEPOT\n", DEPOT);
    printf("%d - CONSULTATION SOLDE COMPTE\n", CONSULTATION_DU_SOLDE);
    printf("%d - QUITTER\n", QUITTER);
    printf("\n");
    printf(" Saisie du choix : ");
    scanf("%d", &choix_user);

    return choix_user;
}

void creation_compte(cr_user *user_data)
{

    FILE *fichier_banque_confidentiel = fopen("BANK","w");

    if( fichier_banque_confidentiel == NULL)
    {
        exit(1);
    }

}




void saisieInfoPerso(info_p *perso) {
    printf("\n");

    printf("NOM : ");
    fgets(perso->nom, sizeof(perso->nom), stdin);
    perso->nom[strcspn(perso->nom, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne

    printf("PRENOM : ");
    fgets(perso->prenom, sizeof(perso->prenom), stdin);
    perso->prenom[strcspn(perso->prenom, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne

    printf("AGE : ");
    scanf(" %d", &perso->age);
    while (getchar() != '\n'); // Nettoie le buffer d'entrée

    printf("\n");
}

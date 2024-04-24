#include "bk.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
/** FONCTION DE VALIDATION DES ENTREES **/

int entree_valide(const char *name)
{
    while (*name)
    {
        if (!isalpha((unsigned char)*name) && !isspace((unsigned char)*name) && *name != '-')
        {
            return 0; // Retourne 0 si un caractère non valide est trouvé
        }
        name++;
    }
    return 1; // Tous les caractères sont valides
}

/** FONCTION DE CREATION DU COMPTE **/

void sauvegarde_donnees(info_p *perso, info_s *sensible)
{

    FILE *fichier_banque_confidentiel = fopen("BANK","a");

    if( fichier_banque_confidentiel == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier ! \n");
        exit(1);
    }

    fprintf(fichier_banque_confidentiel,"Nom: %s , Prenom: %s , Age : %d , Identification :%s, MDP : %s , Solde : %lf \n",perso->nom,perso->prenom,perso->age,sensible->id,sensible->mdp,sensible->solde);

            fclose(fichier_banque_confidentiel);
}


/** FONCTION DE SAISIE DES INFOS PERSO **/

void saisieInfoPerso(info_p *perso)
{
    printf("=== SAISIE INFORMATION SENSIBLE ===\n");
    do
    {
        printf("NOM : ");
        fgets(perso->nom, sizeof(perso->nom), stdin);
        perso->nom[strcspn(perso->nom, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
    }
    while (!entree_valide(perso->nom));   // Continue tant que le nom n'est pas valide

    do
    {
        printf("PRENOM : ");
        fgets(perso->prenom, sizeof(perso->prenom), stdin);
        perso->prenom[strcspn(perso->prenom, "\n")] = '\0';
    }
    while (!entree_valide(perso->prenom));

    do
    {
        printf("AGE : ");
        scanf("%d", &perso->age);
        while (getchar() != '\n'); // Nettoie le buffer pour supprimer le reste de la ligne
    }
    while (perso->age < 0 || perso->age > 100);   // Valide que l'âge est dans une plage raisonnable
}

/** FONCTION DE SAISIE DE INFOS SENSIBLE **/

void saisieInfoSensible(info_s *sensible)
{
    printf("!!!!!!!!!!! WARNING !!!!!!!!!!!");
    printf("\n");
    printf("\n");
    printf("=== SAISIE INFORMATION SENSIBLE ===\n");
    printf("\n");
    do
    {
        printf("IDENTIFIANT : ");
        fgets(sensible->id,sizeof(sensible->id),stdin);
        sensible->id[strcspn(sensible->id, "\n")] = '\0';
    }
    while(!entree_valide(sensible->id));


    do
    {
        printf("MOT DE PASSE : ");
        fgets(sensible->mdp,sizeof(sensible->mdp),stdin);
        sensible->mdp[strcspn(sensible->mdp, "\n")] = '\0';
    }
    while(!entree_valide(sensible->mdp));

    do
    {
        printf("DEPOT(MINIMUM DE DEPOT 100 $) : ");
        printf("\n");
        scanf("%lf",&sensible->solde);
        while (getchar() != '\n');

        if(sensible->solde < 100 )
        {
            printf("!!!! ATTENTION LE MONTANT DE DEPOT DOIT ETRE SUPERIEUR A 100 $ !!!!\n");
        }



    }
    while(sensible->solde <100);




}


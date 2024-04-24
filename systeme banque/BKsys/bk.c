#include "bk.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Affiche le menu du compte utilisateur et retourne le choix
int menu_compte_user(int choix)
{
    printf("\n");
    printf("===== MENU UTILISATEUR BANQUE =====\n");
    printf("\n");
    printf("%d - RETRAIT\n", RETRAIT);
    printf("%d - DEPOT\n", DEPOT);
    printf("%d - CONSULTATION SOLDE COMPTE\n", CONSULTATION_DU_SOLDE);
    printf("%d - QUITTER\n", QUITTER);
    printf("\n");
    printf(" Saisissez votre choix : ");
    scanf("%d", &choix);
    return choix;
}

// Valide les entrées des utilisateurs pour s'assurer qu'elles contiennent uniquement des lettres, des espaces ou des tirets
int entree_valide(const char *name)
{
    while (*name)
    {
        if (!isalpha((unsigned char)*name) && !isspace((unsigned char)*name) && *name != '-')
        {
            return 0; // caractère non valide trouvé
        }
        name++;
    }
    return 1; //  caractères valides
}

// Sauvegarde les données du compte dans un fichier en clair
void sauvegarde_donnees(info_p *perso, info_s *sensible)
{
    FILE *fichier_banque_confidentiel = fopen("BANK", "a");
    if (fichier_banque_confidentiel == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier !\n");
        exit(1);
    }
    fprintf(fichier_banque_confidentiel, "Nom: %s , Prénom: %s , Âge : %d , Identification :%s, MDP : %s , Solde : %lf\n",
            perso->nom, perso->prenom, perso->age, sensible->id, sensible->mdp, sensible->solde);
    fclose(fichier_banque_confidentiel);
}

// Saisie des informations personnelles de l'utilisateur
void saisieInfoPerso(info_p *perso)
{
    printf("=== SAISIE DES INFORMATIONS PERSONNELLES ===\n");
    do
    {
        printf("NOM : ");
        fgets(perso->nom, sizeof(perso->nom), stdin);
        perso->nom[strcspn(perso->nom, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
    }
    while (!entree_valide(perso->nom));

    do
    {
        printf("PRÉNOM : ");
        fgets(perso->prenom, sizeof(perso->prenom), stdin);
        perso->prenom[strcspn(perso->prenom, "\n")] = '\0';
    }
    while (!entree_valide(perso->prenom));

    do
    {
        printf("ÂGE : ");
        scanf("%d", &perso->age);
        while (getchar() != '\n'); // nettoie le buffer
    }
    while (perso->age < 18 || perso->age > 100);   // vérifie  l'âge
}

// saisie les informations sensibles de l'utilisateur
void saisieInfoSensible(info_s *sensible)
{
    printf("!!!!!!!!!!! ATTENTION !!!!!!!!!!!\n");
    printf("\n");
    printf("=== SAISIE DES INFORMATIONS SENSIBLES ===\n");
    printf("\n");
    do
    {
        printf("IDENTIFIANT : ");
        fgets(sensible->id, sizeof(sensible->id), stdin);
        sensible->id[strcspn(sensible->id, "\n")] = '\0';
    }
    while(!entree_valide(sensible->id));

    do
    {
        printf("MOT DE PASSE : ");
        fgets(sensible->mdp, sizeof(sensible->mdp), stdin);
        sensible->mdp[strcspn(sensible->mdp, "\n")] = '\0';
    }
    while(!entree_valide(sensible->mdp));

    do
    {
        printf("DÉPÔT (MINIMUM DE DÉPÔT 100 $) : ");
        printf("\n");
        scanf("%lf", &sensible->solde);
        while (getchar() != '\n');

        if (sensible->solde < 100)
        {
            printf("!!!! ATTENTION LE MONTANT DU DÉPÔT DOIT ÊTRE SUPÉRIEUR À 100 $ !!!!\n");
        }
    }
    while (sensible->solde < 100);
}

// authentification de l'utilisateur
bool authentification(info_s *sensible)
{
    char mdp_authentification[MAXCHARS];
    char id_authentification[MAXCHARS];
    char line[256];

    FILE *fichier_banque_confidentiel = fopen("BANK", "r");
    if (fichier_banque_confidentiel == NULL)
    {
        printf("!! Erreur lors de l'ouverture du fichier !!\n");
        return false;
    }

    printf("Identification : ");
    fgets(id_authentification, sizeof(id_authentification), stdin);
    id_authentification[strcspn(id_authentification, "\n")] = '\0';

    printf("Mot de passe : ");
    fgets(mdp_authentification, sizeof(mdp_authentification), stdin);
    mdp_authentification[strcspn(mdp_authentification, "\n")] = '\0';

    const char *format = "Nom: %*s , Prénom: %*s , Âge : %*d , Identification :%[^,], MDP : %[^,] , Solde : %*lf ";
    while (fgets(line, sizeof(line), fichier_banque_confidentiel) != NULL)
    {
        if (sscanf(line, format, sensible->id, sensible->mdp) == 2)
        {
            sensible->id[strcspn(sensible->id, " ")] = '\0';
            sensible->mdp[strcspn(sensible->mdp, " ")] = '\0';

            if (strcmp(id_authentification, sensible->id) == 0 && strcmp(mdp_authentification, sensible->mdp) == 0)
            {
                fclose(fichier_banque_confidentiel);
                return true;
            }
        }
    }

    fclose(fichier_banque_confidentiel);
    return false;
}

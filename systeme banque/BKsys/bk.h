#ifndef BK_H_INCLUDED
#define BK_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

// declaration des constantes pour les options de menu
#define QUITTER 0
#define AUTHENTIFICATION 1
#define CREATION_DE_COMPTE 2
#define RETRAIT 3
#define DEPOT 4
#define CONSULTATION_DU_SOLDE 5
#define MAXCHARS 100
#define MAXTAB 100

// structure pour les informations personnelles
typedef struct
{
    char nom[MAXCHARS];
    char prenom[MAXCHARS];
    int age;
} info_p;

// structure pour les informations sensibles
typedef struct
{
    char id[MAXCHARS];
    char mdp[MAXCHARS];
    double solde;
} info_s;

// prototypes de fonctions pour la gestion du compte bancaire
int menu_compte_user(int choix);
int entree_valide(const char *name);
void saisieInfoPerso(info_p *perso);
void saisieInfoSensible(info_s *sensible);
void sauvegarde_donnees(info_p *perso, info_s *sensible);
bool authentification(info_s *sensible);
void depot_compte(info_s *sensible);
void retrait_compte(info_s *sensible);
void consultation(info_s *sensible);

#endif

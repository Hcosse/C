#ifndef BK_H_INCLUDED
#define BK_H_INCLUDED

#include <string.h>
#include <stdio.h>

#define QUITTER 0
#define AUTHENTIFICATION 1
#define CREATION_DE_COMPTE 2
#define RETRAIT 3
#define DEPOT 4
#define CONSULTATION_DU_SOLDE 5
#define MAXCHARS 100
#define MAXTAB 100

/** STRUCTURE POUR INFORMATIONS PERSONNELLES **/
typedef struct info_perso
{
    char nom[MAXCHARS];
    char prenom[MAXCHARS];
    int age;
} info_p;

/** STRUCTURE POUR LA DATE **/
typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;

/** STRUCTURE POUR INFORMATIONS SENSIBLES **/
typedef struct info_sensible
{
    char id[MAXCHARS];
    char mdp[MAXCHARS];
    double solde;
} info_s;

/** STRUCTURE POUR CREATION COMPTE **/
typedef struct creation_compte_user
{
    info_p *perso;    // Pointeur vers les informations personnelles
    info_s *sensible; // Pointeur vers les informations sensibles
    date *dte;        // Pointeur vers les informations de date
} cr_user;

/** FONCTIONS POUR LA GESTION DU COMPTE BANCAIRE **/
int menu_compte_user(int choix_user);
void creation_compte(cr_user *user_data);
void saisieInfoPerso(info_p *perso);
void saisieInfoSensible(info_s *sensible);
void date_creation_compte(date *dte);

/** FONCTIONS POUR LA PARTIE IDENTIFICATION **/
int authentification(info_s *sensible);
void depot_compte(info_s *sensible);
void retrait_compte(info_s *sensible);
void consultation(info_s *sensible);

#endif // BK_H_INCLUDED

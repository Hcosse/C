#include <stdio.h>
#include <math.h>

int main() {
    float a, b;
    char reponse;
    int choix;

    do {
        printf("==== Menu Calculatrice ====\n");
        printf("1- Addition\n");
        printf("2- Soustraction\n");
        printf("3- Division\n");
        printf("4- Multiplication\n");
        scanf("%d", &choix);

        printf("Saisir le nombre A : ");
        scanf("%f", &a);
        printf("Saisir le nombre B : ");
        scanf("%f", &b);

        switch (choix) {
            case 1:
                printf("Le resultat de l'addition est : %.2f\n", a + b);
                break;
            case 2:
                printf("Le resultat de la soustraction est : %.2f\n", a - b);
                break;
            case 3:
                if (b != 0) {
                    printf("Le resultat de la division est : %.2f\n", a / b);
                } else {
                    printf("Erreur : Division par zero\n");
                }
                break;
            case 4:
                printf("Le resultat de la multiplication est : %.2f\n", a * b);
                break;
            default:
                printf("!! Saisie Incorrect !!\n");
                break;
        }

        printf("Effectuer un autre calcul (O/N) ? : ");
        scanf(" %c", &reponse);

    } while (reponse != 'N');

    return 0;
}

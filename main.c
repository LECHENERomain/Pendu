//
// Created by leche on 31/10/2024.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[]) {
    char lettre = 0;
    char motSecret[] = "ROUGE";
    int coupsRestants = 10;
    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouvee = NULL;
    lettreTrouvee = malloc(nombreLettres * sizeof(int));

    while(coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres)) {
        printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for (int i = 0; i < nombreLettres; i++) {
            if (lettreTrouvee[i]) printf("%c", motSecret[i]);
            else printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee)) coupsRestants--;
    }
    if (gagne(lettreTrouvee, nombreLettres))
        printf("\n\n Gagne ! Le mot secret etait bien : %s", motSecret);
    else
        printf("\n\n Perdu ! Le mot secret etait : %s", motSecret);
    free(lettreTrouvee);
    return 0;
}

int tailleMot(char motSecret[]) {
    int nombreLettres = 0;
    for(int i = 0; motSecret[i] != '\0'; i++) {
        nombreLettres++;
    }
    return nombreLettres;
}

void initTableau(int *lettreTrouvee, int taille) {
    for(int i = 0; i < taille; i++) {
        lettreTrouvee[i] = 0;
    }
}

int gagne(int *lettreTrouvee, int nombreLettres) {
    int i = 0;
    int joueurGagne = 1;

    for(i = 0; i < nombreLettres; i++) {
        if(lettreTrouvee[i] == 0) joueurGagne = 0;
    }
    return joueurGagne;
}

char lireCaractere() {
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n');
    return caractere;
}

int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee) {
    int i = 0, bonneLettre = 0;
    for (i = 0; motSecret[i] != '\0'; i++) {
        if (lettre == motSecret[i]) {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}
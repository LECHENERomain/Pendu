//
// Created by leche on 01/11/2024.
//

#ifndef QUIZ_H
#define QUIZ_H

int tailleMot(char motSecret[]);
void initTableau(int *lettreTrouvee, int taille);
int gagne(int *lettreTrouvee, int nombreLettres);
char lireCaractere();
int rechercheLettre(char lettre, char motSecret[], int *lettreTrouvee);
#endif //QUIZ_H

/**
 * @file main.c
 * @author Joris Tazamoucht and Maxence Vaisse
 * @brief
 * @version 1.0
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"
#include <time.h>
#include <conio.h>
#include <windows.h>

int main()
{

  char mot_Hide[100] = "";
  char cached[1] = "-";
  int compteur_Tableau = 0;
  int i = 0;
  int u = 0;
  int replay_Game = 1;
  int bonne_Lettre;
  int fin_De_Partie = 0;
  char relancer_Partie[1] = "1";



  while (relancer_Partie[0] != '0')
  {
  replay_Game = 0;
  relancer_Partie[0] = '0';
  int coups_Restant = 8;
  int comparaison = 0;
  fin_De_Partie = 0;



  // Ouverture du fichier "words.txt" en mode "lecture"
  int nombre_Ligne = 0;
  char mot_Secret[100] = "";
  FILE * fichier = NULL;
  fichier = fopen("words", "r");



 // Ouverture du fichier et comptage de lignes (de mots)
  if (fichier != NULL)
  {
    char c[100] = "";
      while (fgets(c, 100, fichier) != NULL)
      {
        nombre_Ligne++;
      }
      rewind(fichier);
      fclose(fichier);
    }
    else
    {
      printf("Le fichier n'a pas charge correctement. Erreur /!\\n");
    }

}

    // On tire au hasard entre 1 et le nombre maximum de lignes du fichier
    int MIN = 1;
    int MAX = nombre_Ligne ;
    int i = 0;
    int ligne_A_Tirer = 0;
    srand(time(NULL));
    ligne_A_Tirer = (rand() % (MAX - MIN + 1)) + MIN;



    //On recupere le mot tiré au hasard.
    fichier = fopen("words", "r");
    if (fichier != NULL)
    {
      for (i = 0; i < ligne_A_Tirer; i++)
      {
        (fgets(mot_Secret, 1000, fichier));
      }

      // Si il y a un \n a la fin de la ligne on le remplace par \0.
      char * p;
      if ((p = strchr(mot_Secret, '\n')) != NULL)
        *
        p = '\0';
      fclose(fichier);
    }
    else
    {
      printf("Le fichier n'a pas chargé correctement. Erreur n°2 /!\\n");
    }



    // On mesure la longueur du mot à deviner.
    int longueur = strlen(mot_Secret);



    // On fait le mot etoilé.
    for (i = 0; i < longueur; i++)
    {
      mot_Hide[i] = * cached;
    }


    // On commence la boucle pour jouer.
    char nom_Du_Joueur[100];
    system("title Tu_Le_C");
    Color(14,0);
    printf("\t\t\tBonjour et bienvenue sur le jeu du Pendu.\n");
    Color(12,0);
    printf("\t\t\t\t\t  _______      _      ______    _____ \n");
    printf("\t\t\t\t\t |__   __|    | |    |  ____|  / ____|\n");
    printf("\t\t\t\t\t    | |_   _  | |    | |__    | |     \n");
    printf("\t\t\t\t\t    | | | | | | |    |  __|   | |     \n");
    printf("\t\t\t\t\t    | | |_| | | |____| |____  | |____ \n");
    printf("\t\t\t\t\t    |_|\\__,_| |______|______|  \\_____|\n\n");
    sleep(2);
    Color(15,0);
    printf("\t\t\t\t\tQuel est votre pseudo ? ");
    sleep(1);
    scanf("%s" ,&nom_Du_Joueur);
    sleep(1);
    printf("\t\t\t\t\tAttention %s le jeu va bientot commencer !\n", nom_Du_Joueur);
    sleep(1);
    printf("\t\t\t\t\tEtes vous pret ? ", nom_Du_Joueur);
    char Etes_Vous_Pret = lireCaractere();

while (fin_De_Partie == 0)
  {
    printf("\n Il vous reste %d coups a jouer !\n Quel est le mot secret ? : %s \n Proposez une lettre : ", coups_Restant, mot_Hide);
    char ma_Lettre = lireCaractere();
    {
    bonne_Lettre = 0;
    for (i = 0; i < longueur; i++)
    {
      if (mot_Secret[i] == ma_Lettre)
      {
        mot_Hide[i] = ma_Lettre;
        bonne_Lettre = 1;
      }
    }

    // Tableau stockant les lettres déjà tapées
    char tabLettre[26];
    int essaye = 0;
    for (int b = 0; b < compteur_Tableau; b++)
    {
      if (ma_Lettre == tabLettre[b])
      {
        essaye = 1;
        break;
        }
    }
      if (essaye == 1)
    {
      printf("\nVous avez deja tente cette lettre. Veuillez en choisir une autre");
    }
      else
    {
      // On met les nouvelles lettres dans le tableau.
      tabLettre[compteur_Tableau] = ma_Lettre;
      compteur_Tableau++;

    if (bonne_Lettre == 0)
    {
      coups_Restant --;
      switch (coups_Restant)
      {

        // Etapes du Pendu qui vont s'afficher au fur et a mesure que l'on se trompe de lettre.
        case 7:
        system("color a");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 6:
        system("color b");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 5:
        system("color c");
        printf("    ____ \n");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 4:
        system("color d");
        printf("    ____ \n");
        printf("   |    |    \n");
        printf("   |         \n");
        printf("   |         \n");
        printf("   |         \n");
        printf("   |         \n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 3:
        system("color e");
        printf("    ____ \n");
        printf("   |    |    \n");
        printf("   |    o    \n");
        printf("   |         \n");
        printf("   |         \n");
        printf("   |         \n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 2:
        system("color 1");
        printf("    ____ \n");
        printf("   |    |    \n");
        printf("   |    o    \n");
        printf("   |   /|\\   \n");
        printf("   |         \n");
        printf("   |         \n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 1:
        system("color 4");
        printf("    ____ \n");
        printf("   |    |    \n");
        printf("   |    o    \n");
        printf("   |   /|\\   \n");
        printf("   |    |    \n");
        printf("   |         \n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;

        case 0:
        system("color f");
        printf("    ____ \n");
        printf("   |    |    \n");
        printf("   |    o     \n");
        printf("   |   /|\\      \n");
        printf("   |    | \n");
        printf("   |   / \\ \n");
        printf("  _|_ \n");
        printf(" |   |______ \n");
        printf(" |          | \n");
        printf(" |__________|\n");
        break;
        default:
      }
    }
  }
}



        // Si le mot est découvert, alors c'est gagné.
        int comparaison = strcmp(mot_Secret, mot_Hide);
        if (comparaison == 0)
        {
          printf("\n\n VICTOIRE ! le mot etait bien : %s\nVoulez vous rejouer ?\n OUI = 1     |       NON = 0 ", mot_Secret);



        // Relancer une partie ?
        char vide[1] = "";
        for (i = 0; i < longueur; i++)
        {
          mot_Hide[i] = * vide;
        }
          relancer_Partie[0] = lireCaractere();
          if ( * relancer_Partie == '0')
        {
          printf("Au Revoir !\n");
        }
          fin_De_Partie = 1;
        }



        // S'il ne reste plus de coup à jouer, alors c'est perdu.
        if (coups_Restant <= 0)
        {
          printf("\n\nDesole vous avez perdu\nLe Mot cache ete : %s\nVoulez vous rejouer une partie ? \nOUI = 1     |     NON = 0 ", mot_Secret);



        // Relancer une partie 
        char vide[1] = "";
        for (i = 0; i < longueur; i++)
        {
          mot_Hide[i] = * vide;
        }
          relancer_Partie[0] = lireCaractere();
          if ( * relancer_Partie == '0')
          {
            printf("Au revoir !\n");
          }
          fin_De_Partie = 1;
        }
      }
    }
  return 0;
}
  char lireCaractere()
{
  char caractere = 0;
  caractere = getchar(); // On lit le premier caractère.
  caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà.



  // Ici on lit les autres caractères mémorisés un à un jusqu'au \n pour les effacer.
  while (getchar() != '\n');
  return caractere; // Ici on retourne le premier caractère qu'on a lu
}
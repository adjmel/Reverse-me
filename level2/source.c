#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void no(void)
{
  puts("Nope.");
  exit(1);
}

void ok(void)
{
  puts("Good job.");
  return;
}


int main()
{
  int uVar1;
  size_t sVar2;
  int iVar3;
  bool bVar4;
  char local_3d;
  char local_3c;
  char local_3b;
  int local_3a;
  char local_39[24]; //la clef sera stocke dans un tableau de 24 caracters
  char local_21[9]; //chaine de 9 caracters utilisee plus tard dans le code
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  printf("Please enter key: ");
  local_10 = scanf("%23s",local_39); //recupere avec scanf puis stock dans local_39
  if (local_10 != 1) { // Si l'utilisateur n'a pas fourni une entrée valide, appelle la fonction `no()
    no();
  }
  //verifie les 2 premiers caracteres
  if (local_39[1] != '0') {
    no();
  }
  if (local_39[0] != '0') {
    no();
  }
  fflush(stdin); //__stdin donc vide l'input
  memset(local_21,0,9); //initialise/remplit la chaine local_21 de 0
  local_21[0] = 'd'; // Le premier caractère de local_21 est 'd'
  // Initialise d'autres variables : 
  local_3a = 0; //initialise a 0 mais plus utilise apres
  local_18 = 2; //initialise a 2, pour commencer à lire à partir du 3ème caractère de `local_39`
  // car local_39 commence deja par 00
  local_14 = 1; //1, pour commencer à écrire dans `local_21` à partir de l'indice 1 car
  // local_39 commence par 'd'
  // Boucle pour traiter la chaîne `local_39` et remplir `local_21`
  while(true) 
  {
    // debug : printf("local21 : %s\n", local_21);
    sVar2 = strlen(local_21);// Calcul de la longueur actuelle de `local_21` pour voir si pendant
    // la boucle local_21 a atteint sa taille max de 8 caracteres (le dernier '\0' ne compte pas)
    uVar1 = local_18; //2
    bVar4 = false; //boolean declare plus haut, ici a false
    if (sVar2 < 8) 
    { // La boucle continue tant que local_21 n'a pas 8 caractères et 
    // qu'il reste encore des caractères à lire dans local_39
      sVar2 = strlen(local_39); // Calcul de la longueur de `local_39`
      bVar4 = uVar1 < sVar2; // Si l'index actuel `local_18` est inférieur à la longueur de `local_39`, on continue
    }
    if (!bVar4)
        break; // Si les conditions ne sont plus remplies, on quitte la boucle
    //lecture des caracters
    local_3d = local_39[local_18];
    local_3c = local_39[local_18 + 1];
    local_3b = local_39[local_18 + 2];

    //convertion en string -> modification car le code d'avant : iVar3 = atoi(&local_3b);
    // ne convertissait que le premier caracter et ne donner que 'd'
    // Concaténation des caractères en une chaîne pour conversion
    char group[4]; // Un tableau pour stocker 3 caractères + '\0'
    group[0] = local_3d;
    group[1] = local_3c;
    group[2] = local_3b;
    group[3] = '\0'; // Terminaison de chaîne

    // Conversion en entier
    iVar3 = atoi(group); // Convertit le groupe en entier

    // Stockage dans `local_21`
    local_21[local_14] = (char)iVar3;

    //avance de 3 caracters pour le prochain groupe d'entier
    // LIT 3 CARACTERES A LA FOIS
    local_18 = local_18 + 3;
    local_14 = local_14 + 1;
  }
  local_21[local_14] = '\0';
  iVar3 = strcmp(local_21,"delabere");
  if (iVar3 == 0) 
    ok();
  else
    no();
  return 0;
}
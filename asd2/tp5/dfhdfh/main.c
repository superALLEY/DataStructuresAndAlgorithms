#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <conio.h>

#define taille 100

typedef struct Element
{
  char message[taille];
} Element;

typedef struct File
{
  Element info;
  int priorite;
  struct File *suiv;
  struct File *tete;
  struct File *queque;

} File;


typedef struct Pile
{
  char phrase[taille];
  struct Pile *suiv;
} Pile;

File *createFile()
{
  File *temp = (File *)malloc(sizeof(File));
  return temp;
}


bool FileEstVide(File *f)
{
  return (f == NULL);
}

File *defiler(File *f1)
{

  f1->tete = f1->suiv;

  return f1->suiv;
}

File *Emfiler(File *F, char message[], int priorite)
{
  File *f = createFile();
  f->priorite = priorite;
  strcpy(f->info.message, message);
  f->suiv = NULL;
  if (FileEstVide(F))
  {
    F = f;
    F->queque = f;
    F->tete = f;
    return F;
  }
  else
  {
    F->queque->suiv = f;
    F->queque = f;
    return F;
  }
}



bool pileVide(Pile *p)
{
  return p == NULL;
}

Pile *emptylist()
{
  Pile *temp = (Pile *)malloc(sizeof(Pile));
  return temp;
}
void afficherPile(Pile *p)
{
  Pile *temp = p;
  while (temp != NULL)
  {
    printf("%s ", temp->phrase);
    temp = temp->suiv;
  }
}

bool estVide(Pile *p)
{
  return (p == NULL);
}
void afficherFile(File *F)
{
  if (FileEstVide(F))
  {
    printf("La file est vide\n");
  }
  else
  {
    File *temp = F;
    while (temp != NULL)
    {
      printf("%s |", temp->info.message);
      temp = temp->suiv;
    }
  }
}

Pile *empiler(Pile *p, char *e)
{
  Pile *temp = emptylist();

  strcpy(temp->phrase, e);
  if (pileVide(p))
  {
    temp->suiv = NULL;
    p = temp;
  }
  else
  {
    temp->suiv = p;
    p = temp;
  }

  return p;
}

Pile *depiler(Pile *p)
{
  Pile *temp = emptylist();
  temp = p;
  p = p->suiv;
  free(temp);
  return p;
}

char *sommet(Pile *p)
{
  return p->phrase;
}

Pile *inverserPile(Pile *p)
{
  Pile *p1 = (Pile *)malloc(sizeof(Pile));
  p1 = NULL;
  Pile *temp = p;
  while (temp != NULL)
  {
    p1 = empiler(p1, temp->phrase);
    temp = temp->suiv;
    /* code */
  }
  return p1;
}

char *inverserWord(char word[])
{
  int size = strlen(word);
  int j = size - 1;
  for (int i = 0; i < size / 2; i++)
  {
    char c = word[i];
    word[i] = word[j];
    word[j] = c;
    j--;
  }
  return word;
}

char *suppchar(char word[])
{
  int length = strlen(word);
  char *p = strchr(word, '\n');
  if (p != NULL)
  {
    memmove(p, p + 1, length - (p - word));
    strncpy(p + (length - (p - word) - 1), "\0", 1);
  }

  return word;
}

void inversermot(char *phrase)
{

  Pile *p = emptylist();
  p = NULL;
  char *word = strtok(phrase, " ");
  while (word != NULL)
  {
    p = empiler(p, word);
    word = strtok(NULL, " ");
  }
  strcpy(sommet(p), suppchar(sommet(p)));

  afficherPile(p);
}

void reverse_char_words(char *phrase, int i)
{

  Pile *p = emptylist();
  p = NULL;
  char *word = strtok(phrase, " ");
  while (word != NULL)
  {
    word = inverserWord(word);

    p = empiler(p, word);
    word = strtok(NULL, " ");
  }
  strcpy(sommet(p), suppchar(sommet(p)));
  if (i == 1)
  {
    p = inverserPile(p);
  }

  afficherPile(p);
}

void inverserchar(char *phrase)
{
  reverse_char_words(phrase, 1);
}


bool palindrome(char phrase[])
{

  Pile *p = emptylist();
  p = NULL;

  Pile *p1 = emptylist();
  p1 = NULL;

  char *word = strtok(phrase, " ");
  while (word != NULL)
  {

    p = empiler(p, word);

    word = strtok(NULL, " ");
  }
  p1 = inverserPile(p);
  char *word2 = sommet(p);
  char *word3 = sommet(p1);
  strcpy(sommet(p), suppchar(sommet(p)));

  afficherPile(p);
  printf("\n");
  afficherPile(p1);
  while (p != NULL)
  {
    if (strcmp(word2, word3) != 0)
    {
      return false;
    }
    p = depiler(p);
    p1 = depiler(p1);
  }

  return true;
}

File *concatene(File *F, File *temp)
{
  if (FileEstVide(F))
  {
    return temp;
  }
  else
  {
    File *tempo = F;
    while (tempo->suiv != NULL)
    {
      tempo = tempo->suiv;
    }
    tempo->suiv = temp;
    return F;
  }
}

void changermot(char phrase[], char *oldWord, char *newWord)
{
  bool trouve = false;

  Pile *p = emptylist();
  p = NULL;

  char *word = strtok(phrase, " ");
  while (word != NULL)
  {

    p = empiler(p, word);

    word = strtok(NULL, " ");
  }
  p = inverserPile(p);
  afficherPile(p);
  Pile *temp = p;
  while (temp != NULL)
  {
    if (strcmp(temp->phrase, oldWord) == 0)
    {
      strcpy(temp->phrase, newWord);
      trouve = true;
    }
    temp = temp->suiv;
  }
  if (!trouve)
  {
    printf("Ce mot nexiste pas\n");
  }
  else
  {
    Pile *tempor = p;
    while (tempor != NULL)
    {
      printf("%s ", tempor->phrase);

      tempor = tempor->suiv;
    }
  }
}

void Piles()
{
  int choix1;
  printf("1 : Inverser Les mots d'une phrase\n");
  printf("2 : Inverser Les characteres dune phrase donnee\n");
  printf("3 : Inverser  characters/mots d'une phrase\n");
  printf("4 : Verifier si Une Phrase est Palindrome\n");
  printf("5 : Remplacer Un mot par Autre mot donnee \n");
  printf("veuillez saisir un nombre  : ");
  scanf("%d", &choix1);

  char phra[taille];char phr[taille];char ph[taille];char p[taille];
  switch (choix1)
  {

  case 1:

    printf("votre phrase  : ");
    char phras[taille];
    fgets(phras, 100, stdin);
    fgets(phras, 100, stdin);

    inversermot(phras);

    break;

  case 2:


    printf("votre phrase  : ");
    fgets(phra, 100, stdin);
    fgets(phra, 100, stdin);

    inverserchar(phra);

    break;
  case 3:


    printf("votre phrase  : ");
    fgets(phr, 100, stdin);
    fgets(phr, 100, stdin);

    reverse_char_words(phr, 0);
    break;
  case 4:


    printf("votre phrase  : ");
    fgets(ph, 100, stdin);
    fgets(ph, 100, stdin);

    bool Palindrome = palindrome(ph);
    if (Palindrome)
    {
      printf("Cette phrase est palindrome");
    }
    else
    {
      printf("Cette phrase n'est pas palindrome");
    }
    break;
  case 5:


    printf("votre phrase  : ");
    fgets(p, 100, stdin);
    fgets(p, 100, stdin);

    char *oldWord = "chat";
    char *newWord = "chien";

    changermot(p, oldWord, newWord);
    break;

  default:
    while (choix1 < 1 || choix1 > 5)
    {
      printf("ressayer \n");
      scanf("%d", &choix1);
    }
  }


}


File *supprimerPos(File *p, File *elem, int priorite)
{
  if (p == elem)
  {
    return NULL;
  }
  else
  {
    return Emfiler(supprimerPos(defiler(p), elem, priorite), p->info.message, priorite);
  }
}

File *SuppPrio(File *F, int prio)
{
  File *temp = F;
  while (temp != NULL)
  {
    if (temp->priorite == prio)
    {
      File *tempo = temp->suiv;
      F = supprimerPos(F, temp, temp->priorite);
      F = concatene(F, tempo);
    }
    temp = temp->suiv;
  }

  return F;
}

void suppper(File *F, int choice)
{
  int pri, size;
  char msg[taille];
  printf("La capacite de la file : ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    printf("MESSAGE DE LA FILE : ");
    scanf("%s", msg);
    printf("priorite : ");
    scanf("%d", &pri);
    F = Emfiler(F, msg, pri);
  }
  afficherFile(F);
  printf("\n");
  printf("La file apres la supression des elements de la Haute priorite : \n");

  F = SuppPrio(F, 0);
  afficherFile(F);
  printf("\n");
  if (choice == 3)
  {
    printf("La file apres la supression des elements de la moyenne priorite : \n");
    F = SuppPrio(F, 1);
    afficherFile(F);
    printf("\n");
    printf("La file apres la supression des elements de la basse priorite : \n");
    F = SuppPrio(F, 2);
    afficherFile(F);
    printf("\n");
  }
}
void Files()
{
  File *F = createFile();
  F = NULL;

  printf("\nHaute priorite 0\n");
  printf("\nMoyenne priorite 1\n");
  printf("\nBasse priorite 2\n\n");
  printf("1: Pour Emfiler un Element\n");
  printf("2: pour Defiler en dependant de La priorite\n");
  printf("3: pour Vider La file\n");
  printf("Veuillez saisir Le nombre correspondant : ");
  int choice;
  scanf("%d", &choice);int num, priori;char mot[taille];
  switch (choice)
  {
  case 1:



    printf("Le nombre des elements de La file : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {

      printf("Le message : ");
      scanf("%s", mot);
      printf("La priorite : ");
      scanf("%d", &priori);
      F = Emfiler(F, mot, priori);
    }
    afficherFile(F);
    printf("\n");
    F = defiler(F);
    afficherFile(F);
    printf("\n");

    break;
  case 2:
    suppper(F, choice);
    break;
  case 3:
    suppper(F, choice);
    break;
  default:
    while (choice < 1 || choice > 3)
    {
      printf("ressayer d entrer votre nombre\n");
      scanf("%d", &choice);
    }
    break;
  }

  system("cls");
}

int main()
{
  while (true)
  {
    int choix;
    printf("1: pour Les piles\n");
    printf("2: pour files\n ");
    printf("saisir un nombre : ");
    scanf("%d", &choix);
    switch (choix)
    {

    case 1:
      Piles();

      break;
    case 2:
      Files();
      break;

    default:
      while (choix < 1 || choix > 2)
      {
        printf("ERREUR ressayer\n");
        scanf("%d", &choix);
      }
    }
    int redem;
    printf("cliquer sur 1 pour ressayer\n");
    scanf("%d", &redem);
    if (redem != 1)
    {
      exit(-1);
    }
  }

  return 0;}

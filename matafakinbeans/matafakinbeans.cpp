#include <stdio.h>
#include <stdlib.h>

typedef struct prvek {
    int cislo;                  // uložená hodnota
    struct prvek* dalsi;        // pointer na další prvek seznamu
} Prvek;

void VypisSeznam(Prvek* S)
{
    while (S != NULL)
    {
        printf("%d", S->cislo);     // výpis aktuálního prvku
        S = S->dalsi;               // posun na další prvek
    }
}

Prvek* start = NULL;

void PridejNaKonecPrvekLOL(Prvek* S, int x)
{
    if (S == NULL) {                //yaložení prvního prvku 
        start = (Prvek*)malloc(sizeof(Prvek));
        S = start;
        S->cislo = x;
        S->dalsi = NULL;
    } else {                         //založení všech dalších prvků
    while (S != NULL) S = S->dalsi;  //doleyu na konec
        S->dalsi = (Prvek*)malloc(sizeof(Prvek));
        S->dalsi->cislo = x;
        S->dalsi->dalsi = NULL;
    }
}


int main()
{
    PridejNaKonecPrvekLOL(start, 3);
    PridejNaKonecPrvekLOL(start, 7);

    /*start = (Prvek*)malloc(sizeof(Prvek));
    start->cislo = 3;               //prvek nese informaci
    start->dalsi = NULL;            // další prvek už není 

    start->dalsi = (Prvek*)malloc(sizeof(Prvek));
    start->dalsi->cislo = 7;
    start->dalsi->dalsi = NULL; */
    VypisSeznam(start);
}
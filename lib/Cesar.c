#include "Cesar.h"
#include "Vigenere.c"
#include <stddef.h>

char* chiffre_Cesar(char* clair,char const cle)
{
    char cle2[1];
    cle2[0]=cle;
    clair=chiffre_Vigenere(clair, cle2);
    return clair;
}

char* dechiffre_Cesar(char* chiffre, char const cle)
{
    char cle2;
    cle2=97+(26-(cle-97));
    chiffre=chiffre_Cesar(chiffre, cle2);
    return chiffre;
}

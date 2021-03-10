#include "ROT13.h"
#include "Cesar.c"
#include <stddef.h>

char* chiffre_ROT13(
    char* clair)    // Texte en clair qui sera modifié.
{
    char cle=110;
    clair=chiffre_Cesar(clair, cle);
    return clair;
}

char* dechiffre_ROT13(
    char* chiffre)  // Texte chiffré qui sera modifié.
{
    chiffre=chiffre_ROT13(chiffre);
    return chiffre;
}


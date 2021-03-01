#include "Cesar.h"

#include <stddef.h>

char* chiffre_Cesar(char* clair,char const cle)
{
    int i=0;
    int depassement=0;
    int cle2=cle-97;
    if(clair==NULL)
        return NULL;
    else
    {
        while(clair[i]!='\0')
        {
            if(clair[i]>=65 && clair[i]<=90)
            {
                if(clair[i]+cle2>90)
                {
                    depassement=(clair[i]+cle2-1)-90;
                    clair[i]=65+depassement;
                }    
                else
                {
                    clair[i]=clair[i]+cle2;
                }
            }
            else if(clair[i]>=97 && clair[i]<=122)
            {
                if(clair[i]+cle2>122)
                {
                    depassement=(clair[i]+cle2-1)-122;
                    clair[i]=97+depassement;
                }    
                else
                {
                    clair[i]=clair[i]+cle2;
                }
            }
            else if(clair[i]==124||clair[i]==44||clair[i]==46)
                {
                    clair[i]=clair[i];
                }
            i=i+1;     
        }
    }
    return clair;
}

char* dechiffre_Cesar(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const cle)
{
    int i=0;
    int depassement=0;
    int cle2=cle-97;
    if(chiffre==NULL)
        return NULL;
    else
    {
        while(chiffre[i]!='\0')
        {
            if(chiffre[i]>=65 && chiffre[i]<=90)
            {
                if(chiffre[i]-cle2<65)
                {
                    depassement=(chiffre[i]-(cle2-1))-65;
                    chiffre[i]=90+depassement;
                }    
                else
                {
                    chiffre[i]=chiffre[i]-cle2;
                }
            }
            else if(chiffre[i]>=97 && chiffre[i]<=122)
            {
                if(chiffre[i]-cle2<97)
                {
                    depassement=(chiffre[i]-(cle2-1))-97;
                    chiffre[i]=122+depassement;
                }    
                else
                {
                    chiffre[i]=chiffre[i]-cle2;
                }
            }
            else if(chiffre[i]==124||chiffre[i]==44||chiffre[i]==46)
                {
                    chiffre[i]=chiffre[i];
                }
            i=i+1;
            
        }
    }
    return chiffre;
}

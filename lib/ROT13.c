#include "ROT13.h"

#include <stddef.h>

char* chiffre_ROT13(
    char* clair)    // Texte en clair qui sera modifié.
{
    int i=0;
    int depassement=0;
    if(clair==NULL)
        return NULL;
    else
    {
        while(clair[i]!='\0')
        {
            if(clair[i]>=65 && clair[i]<=90)
            {
                
                if(clair[i]+13>90)
                {
                    depassement=(clair[i]+12)-90;
                    clair[i]=65+depassement;
                }    
                else
                {
                    clair[i]=clair[i]+13;
                }
            }
            else if(clair[i]>=97 && clair[i]<=122)
            {
                if(clair[i]+13>122)
                {
                    depassement=(clair[i]+12)-122;
                    clair[i]=97+depassement;
                }    
                else
                {
                    clair[i]=clair[i]+13;
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

char* dechiffre_ROT13(
    char* chiffre)  // Texte chiffré qui sera modifié.
{
    int i=0;
    int depassement=0;
    if(chiffre==NULL)
        return NULL;
    else
    {
        while(chiffre[i]!='\0')
        {
            if(chiffre[i]>=65 && chiffre[i]<=90)
            {
                
                if(chiffre[i]-13<65)
                {
                    depassement=(chiffre[i]-12)-65;
                    chiffre[i]=90+depassement;
                }    
                else
                {
                    chiffre[i]=chiffre[i]-13;
                }
            }
            else if(chiffre[i]>=97 && chiffre[i]<=122)
            {
                if(chiffre[i]-13<97)
                {
                    depassement=(chiffre[i]-12)-97;
                    chiffre[i]=122+depassement;
                }    
                else
                {
                    chiffre[i]=chiffre[i]-13;
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

#include "Vigenere.h"

#include <stddef.h>
#include <stdio.h>

char* chiffre_Vigenere(
    char* clair,        // Texte en clair qui sera modifié.
    char const* cle)
{
    int i=0;
    int j=0;
    int depassement=0;
    int cle2;
    if(clair==NULL)
        return NULL;
    else
    {
        while(clair[i]!='\0')
        {   
            
            if(cle[j]=='\0')
            {
                j=0;
            }
            cle2=cle[j];
            cle2=cle2-97;
            if(clair[i]>=65 && clair[i]<=90)
            {
                if(clair[i]+cle2>90)
                {
                    depassement=(clair[i]+cle2-1)-90;
                    clair[i]=65+depassement;
                    j=j+1;
                }    
                else
                {
                    clair[i]=clair[i]+cle2;
                    j=j+1;
                }
            }
            else if(clair[i]>=97 && clair[i]<=122)
            {
                if(clair[i]+cle2>122)
                {
                    depassement=(clair[i]+cle2-1)-122;
                    clair[i]=97+depassement;
                    j=j+1;
                }    
                else
                {
                    clair[i]=clair[i]+cle2;
                    j=j+1;  
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

char* dechiffre_Vigenere(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const* cle)
{    
    int i=0;
    int j=0;
    int depassement=0;
    int cle2;
    if(chiffre==NULL)
        return NULL;
    else
    {
        while(chiffre[i]!='\0')
        {
            if(cle[j]=='\0')
            {
                j=0;
            }
            cle2=cle[j];
            cle2=cle2-97;
            if(chiffre[i]>=65 && chiffre[i]<=90)
            {
                if(chiffre[i]-cle2<65)
                {
                    depassement=(chiffre[i]-(cle2-1))-65;
                    chiffre[i]=90+depassement;
                    j=j+1;
                }    
                else
                {
                    chiffre[i]=chiffre[i]-cle2;
                    j=j+1;
                }
            }
            else if(chiffre[i]>=97 && chiffre[i]<=122)
            {
                if(chiffre[i]-cle2<97)
                {
                    depassement=(chiffre[i]-(cle2-1))-97;
                    chiffre[i]=122+depassement;
                    j=j+1;
                }    
                else
                {
                    chiffre[i]=chiffre[i]-cle2;
                    j=j+1;
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

void chiffre_Vigenere_flux_texte(
    FILE* chiffre,      // Flux de sortie.
    FILE* clair,        // Flux d'entrée.
    char const* cle)
{
    clair=fopen("test/clair.txt", "r");
    chiffre=fopen("build/resultat.txt", "w");
    int i=0;
    int j=0;
    int depassement=0;
    int cle2;
    if(clair==NULL)
        return NULL;
    else
    {
        while(clair[i]!='\0')
        {   
            
            if(cle[j]=='\0')
            {
                j=0;
            }
            cle2=cle[j];
            cle2=cle2-97;
            if(clair[i]>=65 && clair[i]<=90)
            {
                if(clair[i]+cle2>90)
                {
                    depassement=(clair[i]+cle2-1)-90;
                    chiffre[i]=65+depassement;
                    j=j+1;
                }    
                else
                {
                    chiffre[i]=clair[i]+cle2;
                    j=j+1;
                }
            }
            else if(clair[i]>=97 && clair[i]<=122)
            {
                if(clair[i]+cle2>122)
                {
                    depassement=(clair[i]+cle2-1)-122;
                    chiffre[i]=97+depassement;
                    j=j+1;
                }    
                else
                {
                    chiffre[i]=clair[i]+cle2;
                    j=j+1;  
                }
            }
            else if(clair[i]==124||clair[i]==44||clair[i]==46)
            {
                chiffre[i]=clair[i];
            }        
            i=i+1;
        }
    }
    return void;
}

void dechiffre_Vigenere_flux_texte(
    FILE* clair,        // Flux de sortie.
    FILE* chiffre,      // Flux d'entrée.
    char const* cle)
{
    return;
}

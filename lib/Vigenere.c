#include "Vigenere.h"

#include <stddef.h>
#include <stdio.h>

char* chiffre_Vigenere(
    char* clair,        // Texte en clair qui sera modifié.
    char const* cle)
{
    int i=0;
    int j=0;
    int depassement=0;//On créé une variable qui contiendra de combien depasse les ajouts de clé aux caracteres
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
            if(clair[i]>=65 && clair[i]<=90) //On regarde si le caractere est parmi les majuscules
            {
                if(clair[i]+cle2>90)//on verifie si l'addition ne depasse pas des majuscules
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
            else if(clair[i]>=97 && clair[i]<=122)//On regarde si le caractère est une minuscule
            {
                if(clair[i]+cle2>122)//on verifie si l'addition ne depasse pas des minuscules
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
            else
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
    int t=sizeof(cle); //On reccupere la taille de la cle
    int i=0;
    char cle2[t];
    while(cle[i]!='\0')
    {
        cle2[i]=97+(26-(cle[i]-97));
        i=i+1;
    } 
    chiffre=chiffre_Vigenere(chiffre, cle2);
    return chiffre;
}

void chiffre_Vigenere_flux_texte(
    FILE* chiffre,      // Flux de sortie.
    FILE* clair,        // Flux d'entrée.
    char const* cle)
{
    int i=0;
    int n;
    fseek(clair, 0, SEEK_END);//On reccupere la taille max du fichier 
    n = ftell(clair);
    fseek(clair, 0, SEEK_SET);

    char chaine[n-1];
    char chaine2[n-1];
    char caractere;

    while (caractere!=EOF)//On reccupere le caractere tant qu'on a pas atteint la fin du fichier
    {  
        caractere=fgetc(clair);
        chaine[i]=caractere;
        printf("%c",chaine[i]);
        i=i+1; 
    }
    for(i=0;i<=n-1;i++)
    {
        chaine2[i]=chaine[i];
    }
    fputs(chiffre_Vigenere(chaine2,cle),chiffre);//On ecrit dans chiffre les caracteres chiffrés avec vigenere
    
    return;    
}



void dechiffre_Vigenere_flux_texte(
    FILE* clair,        // Flux de sortie.
    FILE* chiffre,      // Flux d'entrée.
    char const* cle)
{
    int i=0;
    int t=sizeof(cle);//On reccupere la taille de la  clé
    char cle2[t];
    while (cle[i]!='\0')
    {  
        cle2[i]=97+(26-(cle[i]-97)); 
        i=i+1; 
    }
    cle2[i]='\0';
    chiffre_Vigenere_flux_texte(clair,chiffre, cle2);//On dechiffre le fichier avec vigenere
    
    return;  
}
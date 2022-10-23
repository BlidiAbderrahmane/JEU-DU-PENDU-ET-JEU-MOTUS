#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
char pp[50][50],pm[50][50];
int sp[100],sm[100],np=0,nm=0,i;
char dict[100][50] = {
    "FAMILLE","TARTE","PAYER","POULE"
    };

int trouve(char c,char ch[50],int n) {
    int b=0, i=0;
    while ((i<n)&&(b==0)) {
        if (ch[i]==toupper(c)) {
            b=1;
        }
        i++;
    }
    return b;
}

int pos (char M[50][50],int n,char ch[50])
{
    int i=0;int b=-1;
    while ((i<n)&&(b==-1)) {
        if (strcmp(toupper(ch),toupper(M[i]))==0) {
            b=i;
        }
        i++;
    }
    return b;
}

void classement (int x)
{
    int i;
    system("cls");
    if (x==1)
    {
    	printf("--------------------CLASSEMENT PENDU--------------------\n");
   		printf("******************* Pseudo     Score *******************\n");
        int b=1,aux;
    	char auxch[50];
   		while (b==1) {
        	b=0;
        	for (i=0;i<np-1;i++) {
            	if (sp[i]<sp[i+1]) {
                	aux=sp[i];
                	sp[i]=sp[i+1];
                	sp[i+1]=aux;
                	strcpy(auxch,pp[i]);
                	strcpy(pp[i],pp[i+1]);
                	strcpy(pp[i+1],auxch);
                	b=1;
            	}
        	}
    	}
        for (i=0;i<np;i++)
        {
            printf("******************* %s \t %d ******************* \n",toupper(pp[i]),sp[i]);
        }
    }
    else {
    	printf("--------------------CLASSEMENT MOTUS--------------------\n");
   		printf("******************* Pseudo     Score *******************\n");
    	int b=1,aux;
    	char auxch[50];
   		while (b==1) {
        	b=0;
        	for (i=0;i<nm-1;i++) {
            	if (sm[i]<sm[i+1]) {
                	aux=sm[i];
                	sm[i]=sm[i+1];
                	sm[i+1]=aux;
                	strcpy(auxch,pm[i]);
                	strcpy(pm[i],pm[i+1]);
                	strcpy(pm[i+1],auxch);
                	b=1;
            	}
        	}
    	}
        for (i=0;i<nm;i++)
        {
            printf(" ******************** %s \t %d ******************* \n",toupper(pm[i]),sm[i]);
        }
    }
   
}

void finjeu(int x, int pts){
    char c;
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("||            1- REJOUER                        ||\n");
    printf("||            2- VERIFIER SCORE                 ||\n");
    printf("||            3- CLASSEMENT                     ||\n");
    printf("||            4- RETOUR AU MENU PRINCIPALE      ||\n");
    printf("||            5- QUITTER L'APPLICATION          ||\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    do {
        scanf("%c",&c);
    } while ((c<'1')||(c>'5'));
    switch (c) {
        case '1': if (x==1) {
            pendu();
        }
        else {
            motus();
        }
        break;
        case '2' : system("cls");printf("VOTRE SCORE : %i\n",pts); finjeu(x,pts);break;
        case '3' : classement(x); finjeu(x,pts); break;
        case '4' : main();break;
        case '5' : ext();break;
    }
}

void pendu(){
    struct timeval tv;
    int i,k=0,rnd,o;
    char pseudo[50],ltr,ch[50];
    system("cls");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("||             BIENVENUE AU JEU PENDU           ||\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    do {
       fflush(stdin);
      printf("Donner votre pseudo :\t");
      fgets(pseudo,50,stdin);
    } while (strlen(pseudo)==1);
    srand(time(NULL));
    rnd = rand()%100;
    strcpy(ch,dict[rnd]);
    char alph[26];
   for (i='A';i<='Z';i++) {
        alph[k]=i;
        k++;
   }
   char ch2[50]="";
   for (i=0;i<strlen(ch);i++) {
        strcat(ch2,"*");
   }
  gettimeofday (&tv, NULL);
  int tf = (int)tv.tv_sec+70;
  int coups=7,pts,aide=0,b;
  char c;
  while ((coups>0)&&((tf-(int)tv.tv_sec>0))&&(strcmp(ch,ch2)!=0))
    {
    	system("cls");
        printf("\n");
        printf("Il vous reste %d coups a jouer et %d secondes \n",coups,tf-(int)tv.tv_sec);
        printf("Quel est le mot secret ? %s \n ",ch2);
        printf("\n");
        switch (coups) {
        	case 7 : printf("      _____\n     |         \n     |        \n     |      \n     |      \n___________\n\n");break;
        	case 6 : printf("      _____\n     |     |\n     |        \n     |      \n     |      \n___________\n\n");break;
        	case 5 : printf("      _____\n     |     |\n     |     O\n     |      \n     |      \n___________\n\n");break;
        	case 4 : printf("      _____\n     |     |\n     |     O\n     |     |\n     |      \n___________\n\n");break;
        	case 3 : printf("      _____\n     |     |\n     |     O\n     |    /|\n     |      \n___________\n\n");break;
        	case 2 : printf("      _____\n     |     |\n     |     O\n     |    /|\\\n     |      \n___________\n\n");break;
			case 1 : printf("      _____\n     |     |\n     |     O\n     |    /|\\\n     |    /\n___________\n\n");break;
		}
        k=1;
        for (i=0;i<26;i++) {
            printf("%c\t",alph[i]);
            if (k==10) {
                printf("\n");
                k=0;
            }
            k++;
        }
        printf("\nTapez '?' pour help\n");
        printf("Proposez une lettre : ");
        printf("\n");
        do {
            c=getchar();
        } while (((toupper(c)<'A')||(toupper(c)>'Z'))&&(c!='?'));
        printf("\n");
        if ((c=='?')&&(aide==0)) {
            aide=1;
            do {
              srand(time(NULL));
              rnd = rand()%strlen(ch);
            }
            while (ch2[rnd]!='*');
            ltr=ch[rnd];
            for (i=0;i<strlen(ch);i++) {
                if (ch[i]==toupper(ltr)) {
                    ch2[i]=toupper(ltr);
                }
            }
            i=0;b=0;
            while ((i<26)&&(b==0)) {
                    if (alph[i]==ltr) {
                        alph[i]='-';
                        b=1;
                    }
                    else i++;
                }
        }
        else if (c!='?') {
            if (trouve(c,ch,strlen(ch))) {
                for (i=0;i<strlen(ch);i++) {
                    if (ch[i]==toupper(c)) {
                        ch2[i]=toupper(c);
                    }
                }
                i=0; b=0;
                while ((i<26)&&(b==0)) {
                    if (alph[i]==toupper(c)) {
                        alph[i]='-';
                        b=1;
                    }
                    else i++;
                }
            }
            else coups--;
        }
        gettimeofday (&tv, NULL);
    }
    switch (coups) {
        case 7:case 6 : pts=4; break;
        case 5:case 4 : pts=3; break;
        case 3:case 2 : pts=2; break;
        case 1 : pts=1; break;
        case 0 : pts=0; break;
    }
    if(pts>=1)
     pts=pts-aide;
    if ((strcmp(ch,ch2)==0)&&((tf-(int)tv.tv_sec>0))) {
        printf("Gagne UwU Le mot secret etait bien : %s\nVotre score est : %i\n",ch,pts);
    }
    else {
    	if (((tf-(int)tv.tv_sec<=0))&&(coups>0)) {
    		printf("Temps epuise >:( Le mot secret etait : %s\n",ch);
    		pts=0;
		}
		else {
			system("cls");
			printf("\n\n\n      _____\n     |     |\n     |     O\n     |    /|\\\n     |    / \\\n___________\n\n");
        	printf("Perdu >:( Le mot secret etait : %s\n",ch);
		}
    }
    
   pseudo[strlen(pseudo)-1]='\0';
   if (pos(pp,np,pseudo)==-1) {
       strcpy(pp[np],pseudo);
       sp[np]=pts;
       np++;
    }  
    else {
       o=pos(pp,np,pseudo);
       sp[o]=sp[o]+pts;
    }   
    
    sleep(6);
    system("cls");
    finjeu(1,pts);
}
int occ(char c, char ch[50]) {
    int o=0,i;
    for (i=0;i<strlen(ch);i++) {
        if (toupper(ch[i])==toupper(c)) 
		  o++;
    }
    return o;
}

void motus() {
    int rnd,pts,i,j,n,trouve;
    struct timeval tv;
    char pseudo[50],ch[50],chrand[50],chtest[50]="",chmp[50]="";
    system("cls");
    printf("********************************************************************************************************\n");
    printf("*********************************************  M O T U S  **********************************************\n");
    printf("********************************************************************************************************\n\n\n\n");
    do {
       fflush(stdin);
       printf("   Donner votre pseudo :\t");
       fgets(pseudo,50,stdin);
    } while (strlen(pseudo)==1);
    printf("\n\n\n");
    srand(time(NULL));
    rnd = rand()%100;
    strcpy(chrand,dict[rnd]);
    gettimeofday (&tv, NULL);
  int tf = (int)tv.tv_sec+70;
  int coups=7,aide=0;
  chtest[0]=chrand[0];
  for (i=1;i<strlen(chrand);i++) {
        chtest[i]='-';
  }
  while ((coups>0)&&((tf-(int)tv.tv_sec>0))&&(strcmp(chrand,chtest)!=0))
    {
       
        printf("\n\n   Il vous reste %i tentatives et %i secondes\n\n\n",coups,tf-(int)tv.tv_sec);
        do {
            fflush(stdin);
            printf("   %s [%s]  Donner votre proposition composee de %i caracteres     ",chtest,chmp,strlen(chrand));
            fgets(ch,50,stdin);
            ch[strlen(ch)-1]='\0';
        } while ((strlen(ch)!=strlen(chrand))&&(strcmp(ch,"?")!=0));
        if (strcmp(ch,"?")==0) {
        	if (aide==0) {
			   aide=1;
        	   do {
        		srand(time(NULL));
        	 	rnd=rand()%strlen(chrand);
			   } while (chtest[rnd]!='-');
			   chtest[rnd]=chrand[rnd];
			   i=0; trouve=0;
		       while ((i<strlen(chmp))&&(trouve==0)) {
				if (chmp[i]==chtest[rnd]) {
					for (j=i;j<strlen(chmp)-1;j++) {
						chmp[j]=chmp[j+1];
					}
					chmp[strlen(chmp)-1]='\0';
					trouve=1;
				}
				i++;
			   }	
			}
		}
		else {
		  strcpy(chmp,"");
          for (i=0;i<strlen(chrand);i++) {
             chtest[i]='-';
           }
          for (i=0;i<strlen(chrand);i++) {
             if (toupper(ch[i])==chrand[i]) {
                chtest[i]=chrand[i];
              }
            } 
		   for (i=0;i<strlen(chrand);i++) {
              j=0; trouve=0;
              while ((j<strlen(chrand))&&(trouve==0)) {
                if (chrand[i]==toupper(ch[i])) {
                    trouve=1;
                }
                else if (chrand[j]==toupper(ch[i])) {
                    if (((occ(ch[i],chtest)+occ(ch[i],chmp)))<(occ(ch[i],chrand))) {
                        strncat(chmp,&chrand[j],1);
                        trouve=1;
                    }
                }
                 j++;
               }  
           }
		   if (strcmp(chtest,chrand)!=0) coups--;	
		}
        gettimeofday (&tv, NULL);
   }
    switch (coups) {
        case 7:case 6 : pts=4; break;
        case 5:case 4 : pts=3; break;
        case 3:case 2 : pts=2; break;
        case 1 : pts=1; break;
        case 0 : pts=0; break;
    }
    if (pts>=1)
     pts=pts-aide;
    if ((strcmp(chtest,chrand)==0)&&((tf-(int)tv.tv_sec>0))) {
        printf("\nGagne UwU Le mot secret etait bien : %s\nVotre score est : %i\n",chrand,pts);
    }
    else {
    	if (((tf-(int)tv.tv_sec<=0))&&(coups>0)) {
    		printf("\nTemps epuise >:( Le mot secret etait : %s\n",chrand);
    		pts=0;
		}
		else {
        	printf("\nPerdu >:( Le mot secret etait : %s\n",chrand);
		}
    }
    pseudo[strlen(pseudo)-1]='\0';
    if (pos(pm,nm,pseudo)==-1) {
        strcpy(pm[nm],pseudo);
        sm[nm]=pts;
        nm++;
    }
    else {
       int o=pos(pm,nm,pseudo);
       sm[o]=sm[o]+pts;
    }   
    
    sleep(6);
	system("cls");
    finjeu(2,pts);
}

void ext () {
    system("cls");
    printf("||----------------------------------------------||\n");
    printf("||                   AU REVOIR!                 ||\n");
    printf("||----------------------------------------------||\n");
}

int main()
{
    system("cls");
    char c;
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("||               BIENVENUE AU JEU               ||\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("\n\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("||            Veuillez choisir un jeu           ||\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("||                  1- Le pendu                 ||\n");
    printf("||                  2- Motus                    ||\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    printf("||                  3- Quitter                  ||\n");
    printf("||----------------------------------------------||\n||----------------------------------------------||\n");
    do {
        scanf("%c",&c);
    } while ((c<'1')||(c>'3'));
    switch (c) {
    case '1':pendu(); break;
    case '2':motus(); break;
    case '3':ext(); break;
    }
    return 0;
}

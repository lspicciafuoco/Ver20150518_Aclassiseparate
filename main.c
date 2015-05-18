#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione delle costanti
#define MAX_STRLEN 25
#define MAX_CLSLEN 5
#define M 2
#define F 2

// Definizione del tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char sesso[MAX_STRLEN+1];
    char classe[MAX_CLSLEN+1];
};
// Definisci studente come struct s_studente
struct s_studente v[M];
struct s_studente l[F];

void funzioneOrdinamentoMaschi (struct s_studente v[]);
void funzioneOrdinamentoFemmine (struct s_studente l[]);

int main(int argc, char** argv) {
    // Dichiarazione delle variabili locali
    int i,j;
    FILE *puntaFile;
    FILE *PuntaFile2;
     
    // Codice per l'inserimento dei dati in un array
    
printf("Inserisci i dati degli alunni maschi\n");
    for(i = 0; i < M; i++) {
        printf("Nome elemento %d : ", i);
        scanf("%s", v[i].nome);
        printf("Cognome elemento %d : ", i);
        scanf("%s", v[i].cognome);
        printf("Eta' elemento %d : ", i);
        scanf("%d", &(v[i].eta));
        printf("Sesso %d : ", i);
        scanf("%s", (v[i].sesso));
        printf("Classe elemento %d : ", i);
        scanf("%s", v[i].classe);
    }
    
    funzioneOrdinamentoMaschi(v);
   
    // Codice per la scrittura dell'elenco su file
    puntaFile = fopen("maschi.csv", "wb");
    if(puntaFile != NULL) {
        fwrite(&v, sizeof(v), M, puntaFile);
        fclose(puntaFile);
    }
    else
        printf("Il file non puo' essere aperto\n");
    
printf("Inserire i dati delle alunne femmine\n");
    
    for(j=0;j<F;j++){
        printf("Nome %d : ", i);
        scanf("%s", l[j].nome);
        printf("Cognome %d : ", i);
        scanf("%s", l[j].cognome);
        printf("Eta' %d : ", i);
        scanf("%d", &(l[j].eta));
        printf("Sesso %d : ", i);
        scanf("%s", (l[j].sesso));
        printf("Classe %d : ", i);
        scanf("%s", l[j].classe);
    }
     
    funzioneOrdinamentoFemmine;
    
    PuntaFile2 = fopen("femmine.csv", "wb");
    if(PuntaFile2 != NULL) {
        fwrite(&l, sizeof(l), F, PuntaFile2);
        fclose(PuntaFile2);
    }
    
    return (EXIT_SUCCESS);
}

//Funzione Ordinamento Maschi
void funzioneOrdinamentoMaschi (struct s_studente v[]) {
    int i, j, iMin;
    struct s_studente temp;
 //Corpo della funzione   
    for(i = 0; i < M-1; i++) {
        iMin = i;
        for(j = i + 1; j < M; j++) {
            if(strcmp(v[j].cognome, v[iMin].cognome ) < 0) {
                iMin = j;
            }
        }
        if(i != iMin) {
            temp = v[i];
            v[i] = v[iMin];
            v[iMin] = temp;
        }
    }
}

//Funzione Ordinamento Femmine

void funzioneOrdinamentoFemmine (struct s_studente l[]) {
    int i, j, iMin;
    struct s_studente temporanea;
  //Corpo della funzione    
    for(i = 0; i < F-1; i++) {
        iMin = i;
        for(j = i + 1; j < F; j++) {
            if(strcmp(l[j].cognome, l[iMin].cognome ) < 0) {
                iMin = j;
            }
        }
        if(i != iMin) {
            temporanea = v[i];
            l[i] = l[iMin];
            l[iMin] = temporanea;
        }
    }
}

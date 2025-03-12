

# include <stdio.h>
# include <stdlib.h>

#define MAX_DADES 400

typedef struct Dada{
    int niu;
    float notes[5];
} Alu;

float mitjana(float *dades, int dades_size){
    float m = 0.;
    for(int i = 0; i < dades_size;i++)
    {
        m += dades[i];
    }
    return m/dades_size;
}

// Ex 213 fet al principi per comprovar errors
// imprimirtaula()
void alu_print_alumnes(Alu *alumnes, int alumnes_size) {
    for(int i = 0; i < alumnes_size; i++){
        printf("%d | ", alumnes[i].niu);
        for(int j = 0; j < 4; j++){
            printf("%5.1f",alumnes[i].notes[j]);
        }
        printf(" |%6.2f",alumnes[i].notes[4]);
        printf("\n");
    }
}

void alu_afegir_alumne(int *qt_alumnes, Alu **llista_alumnes, Alu *nou_alumne) {
    Alu *temp = realloc(*llista_alumnes, (sizeof(Alu)) * (*qt_alumnes + 1));
    if (temp == NULL) {
        fprintf(stderr, "No s'ha pogut reservar memoria\n");
        exit(-1);
    }
    *llista_alumnes = temp;
    (*llista_alumnes)[*qt_alumnes] = *nou_alumne;
    (*qt_alumnes)++;
    return;
}

void alu_swap(Alu *a, Alu *b) {
    if (a == b) return;
    Alu t = *a;
    *a = *b;
    *b = t;
}

// ordenataula()
void alu_ordenaralumnes(Alu *alumnes, Alu *alumnes_ordenats, int lrg) { // Ordena alumnes amb Bubble Sort
    for (int i = 0; i < lrg; i++) {alumnes_ordenats[i] = alumnes[i];}

    for (int i = 0; i < lrg - 1; i++) {  
        int intercanvi = 0;
        for (int j = 0; j < lrg - i - 1; j++) {
            if (alumnes_ordenats[j].niu > alumnes_ordenats[j+1].niu) {
                alu_swap(&alumnes_ordenats[j], &alumnes_ordenats[j+1]);
                intercanvi = 1;
            }
        }
        if (intercanvi == 0) break; 
    }
}

int main(){
    FILE *dades;
    int n, i, lrg = 0;
    
    Alu *alumnes;
    
    dades=fopen("Llista.txt","r");
    if(dades==NULL){
        printf("\nNo s'ha accedit al fitxer de dades\n");
        return 1;
    }
    
    // Contador de línies (posicions de alumnes a reservar)
    unsigned int contador_alumnes = 0;
    char current;
    while ((current = fgetc(dades)) != EOF) {
        if (current == '\n') contador_alumnes++;
    }

    rewind(dades); // Torna al principi del fitxer

    // Reservem memòria pel nombre de línies que hem llegit
    alumnes = malloc((sizeof *alumnes) * contador_alumnes);
    if (alumnes == NULL) {
        fprintf(stderr, "No s'ha pogut reservar %i alumnes", contador_alumnes);
        return -1;
    }

    // Llegim el fitxer sencer formatejant les dades
    while(!(fscanf(dades,"%i;",&n)==EOF)){
        alumnes[lrg].niu=n;
        for(i=0;i<4;i++){
            fscanf(dades,"%f",&alumnes[lrg].notes[i]);
            fgetc(dades);//llegeix i descarta els ; i el \n
        }
        alumnes[lrg].notes[4]=mitjana(alumnes[lrg].notes,4);
        lrg++;
    }
    fclose(dades);
    
    printf("\nS'ha llegit informacio de %d linies.\n\n",lrg);

    Alu alumne_exemple = {1234567, {5.6, 6.2, 4.3, 8.6, 0.0}};
    alumne_exemple.notes[4] = mitjana(alumne_exemple.notes, 4);

    alu_afegir_alumne(&lrg, &alumnes, &alumne_exemple);

    Alu *alumnes_ordenats = malloc((sizeof *alumnes_ordenats) * lrg);
    alu_ordenaralumnes(alumnes, alumnes_ordenats, lrg);

    printf("\n\n------ Alumnes ordenats per NIU -----\n");
    alu_print_alumnes(alumnes_ordenats, lrg);
    
    free(alumnes_ordenats);
    free(alumnes);
    return 0;
}
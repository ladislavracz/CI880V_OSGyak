#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char ch;
    
    // Fájl létrehozása és írása
    fptr = fopen("neptunkod.txt", "w");
    if (fptr == NULL) {
        printf("Hiba a fájl létrehozásakor!\n");
        return 1;
    }
    
    fprintf(fptr, "Név: Rácz László\n");
    fprintf(fptr, "Szak: Programtervező informatikus\n");
    fprintf(fptr, "Neptunkód: CI880V\n");
    fclose(fptr);
    
    
    fptr = fopen("neptunkod.txt", "r");
    if (fptr == NULL) {
        printf("Hiba a fájl megnyitásakor!\n");
        return 1;
    }
    
    printf("Fájl tartalma:\n");
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(fptr);
    return 0;
}
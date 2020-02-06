#include <stdio.h>
#include <stdlib.h>

int main(){
    char ap = 34;
    char imiona[20][20] = {"Adam","Karol","Jakub","Michal","Jan","Bartek","Radek","Pawel","Oliwier","Janusz","Ania","Karolina","Asia","Basia","Kasia","Ola","Gosia","Agnieszka","Laura","Justyna"}; 
    char nazwiska[15][20] = {"Nowak","Gruszka","Kowal","Krol","Jablko","Ananas","Masztalerz","Owoc","Zmywak","Kreda","Tablica","Krata","Wcislo","Wypchlo","Wiechta"};
    char kraje[5][15] = {"Polska", "Hiszpania", "Wlochy", "USA", "Islandia"};
    char zainteresowania[11][30] = {"siatkowka","koszykowka","hokej","bilard","tenis","tenis stolowy","boks","skok o tyczce","rzut mlotem","plywanie", "nurkowanie"};
    char zwierzeta[4][10] = {"kot", "pies", "chomik", "krolik"};
    char zwierz_im[5][15] = {"Morty", "Bojack", "Rick", "Peanutbutter", "PC"};
    char *kal = "Kalifornia";
    char *nj = "Nowy Jork";
    char *flo = "Floryda";
    printf("db.osoby.insertMany([ ");
    for(int i=0;i<50;i++){
        printf("{imie: %c%s%c, ", ap, imiona[random()%20], ap);
        printf("nazwisko: %c%s%c, ", ap, nazwiska[random()%15], ap);
        printf("wiek: %ld, wzrost: %ld, ", random()%90+18 ,random()%70+140);
        printf("zainteresowania: [%c%s%c, %c%s%c], ",ap, zainteresowania[random()%11], ap, ap, zainteresowania[random()%11], ap);
        printf("obywatelstwo: [ ");
        int c = 0;
        do {
            int n = random()%5;
            char *au = "-";
            if (n==3){
                int m = random()%3;
                if(m==0) au = kal;
                else if (m==1) au = nj;
                else au = flo;
            }
            if (c>0) printf(",");
            printf("{ kraj:  %c%s%c, jednostka_autonomiczna:  %c%s%c}", ap, kraje[n], ap, ap, au, ap);
            c++;
        } while (random()%2 == 0);
        printf("], zwierzeta: [");
        c=0;
        while (random()%2 == 0) {
            if (c>0) printf(",");
            printf("{ imie:  %c%s%c, gatunek:  %c%s%c}", ap, zwierz_im[random()%5], ap, ap, zwierzeta[random()%4], ap);
            c++;
        } 
        printf("]}");
        if (i<49) printf(",\n");
    }
    printf("])");
}
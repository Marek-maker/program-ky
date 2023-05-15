#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//riešenie problému "Use of undeclared identifier 'bool'" z internetu
#ifndef bool
    #define bool int
    #define false ((bool)0)
    #define true  ((bool)1)
#endif

int main(){

    printf("Tvorca hesiel\n");

    FILE *subor_s_heslom;

 
    if(fopen("HESLO.txt", "r") != NULL){
        char odpoved;
        do{
            printf("Chyba! Subor HESLO.txt uz je. Chcete ho prepisat? (a/n): ");
            odpoved = getchar();
            if(odpoved == 'a'){
                printf("Subor HESLO.txt bude prepisany.\n");
                subor_s_heslom = fopen("HESLO.txt", "w");
                fprintf(subor_s_heslom, "%s", "heslo: ");
                fclose(subor_s_heslom);
                subor_s_heslom = fopen("HESLO.txt", "a");
            }else if(odpoved == 'n'){
                printf("Nemozem vlozit heslo do suboru HESLO.txt, lebo uz je a nechces ho prepisat.\n");
                return 1;
            }else if(odpoved != 'a' && odpoved != 'n'){
                printf("Neznama odpoved. Pouzi iba a alebo n!\n");
            }
        }while(odpoved != 'a' && odpoved != 'n');

        
    }else{
        subor_s_heslom = fopen("HESLO.txt", "w");
        fprintf(subor_s_heslom, "%s", "heslo: ");
        fclose(subor_s_heslom);
        printf("Vytvaram subor HESLO.txt do ktoreho bude zapisane tvoje heslo.\n");
        subor_s_heslom = fopen("HESLO.txt", "a");
    }

    int dlzka = 0;

    printf("Zadaj prosim ake dlhe ma byt tvoje heslo (1 až 1000): ");
    do{
        scanf("%d", &dlzka); // zadaním iných znakov ako čísel sa vytvorý nekonečná sľučka :-{
        if(dlzka < 1 || dlzka > 1000){
            printf("Zadaj platnu dlzku hesla od 1 do 1000!: \n");
        }
    }while(dlzka < 1 || dlzka > 1000);
    
    char znak;
    bool cisla, male_pismena, velke_pismena, znaky;
    

    do{//popita sa z čoho chce aby bolo heslo zložené (cisla, velke/male pismena, znaky)
        char odpoved;
        printf("Prosim vyber (najmenej jednu) moznost z ktorej chces vytvorit heslo.\n");

        do{//opýta sa ci che aby boli v hesle cisla
            printf("Chces do hesla zahrnut cisla (0, 1...9)? (a/n): ");
            odpoved = getchar();
            if(odpoved == 'a'){
                printf("Cisla budu zahrnute do hesla.\n");
                cisla = 1;
            }else if (odpoved == 'n') {
                printf("Cisla nebudu zahrnute do hesla.\n");
                cisla = 0;
            }else{
                printf("Nezadal si platnu odpoved (a/n)!\n");
            }
        }while(odpoved != 'a' && odpoved != 'n');


        do{//opyta sa či chce aby boli v hesle malé písmená
            printf("Chces do hesla zahrnut male pismena (a, b...z)? (a/n): ");
            odpoved = getchar();
            if(odpoved == 'a'){
                printf("Male pismena budu zahrnute do hesla.\n");
                male_pismena = 1;
            }else if (odpoved == 'n') {
                printf("Male pismena nebudu zahrnute do hesla.\n");
                male_pismena = 0;
            }else{
                printf("Nezadal si platnu odpoved (a/n)!\n");
            }
        }while(odpoved != 'a' && odpoved != 'n');

        do{//opýta sa či chce aby boli v hesle veľké písmená
            printf("Chces do hesla zahrnut velke pismena (A, B...Z)? (a/n): ");
            odpoved = getchar();
            if(odpoved == 'a'){
                printf("Velke pismena budu zahrnute do hesla.\n");
                velke_pismena = 1;
            }else if (odpoved == 'n') {
                printf("Velke pismena nebudu zahrnute do hesla.\n");
                velke_pismena = 0;
            }else{
                printf("Nezadal si platnu odpoved (a/n)!\n");
            }
        }while(odpoved != 'a' && odpoved != 'n');

        do{//opýta sa či chce aby boli v hesle znaky
            printf("Chces do hesla zahrnut znaky (#, &, @...)? (a/n): ");
            odpoved = getchar();
            if(odpoved == 'a'){
                printf("Znaky budu zahrnute do hesla.\n");
                znaky = 1;
            }else if (odpoved == 'n') {
                printf("Znaky nebudu zahrnute do hesla.\n");
                znaky = 0;
            }else{
                printf("Nezadal si platnu odpoved (a/n)!\n");
            }
        }while(odpoved != 'a' && odpoved != 'n');
        
        
    }while(cisla != 1 || male_pismena != 1 || velke_pismena != 1 || znaky != 1);//pýta sa dokým sa nevyberie aspoň niečo z čoho sa dá heslo vygenerovať

    srand(time(NULL));
    for(int i = 0; i < dlzka; i++){
        znak = rand()%(57-47) + 47+1;//+1 lebo to cele bolo posunuté dole - / , 0, 1 ...8 namiesto 0, 1, 2.....9
        printf("novy znak: %c\n", znak);
        fprintf(subor_s_heslom, "%c", znak);
    }


    fclose(subor_s_heslom);

    return 0;
}
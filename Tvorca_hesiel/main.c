#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
            }else if(odpoved == 'n'){
                printf("Nemozem vlozit heslo do suboru HESLO.txt, lebo uz je a nechces ho prepisat.\n");
                return 1;
            }else{
                printf("Neznama odpoved. Pouzi iba a alebo n!\n");
            }
        }while(odpoved != 'a' || odpoved != 'n');

        
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
        scanf("%d", &dlzka);
        if(dlzka < 1 || dlzka > 1000){
            printf("Zadaj platnu dlzku hesla od 1 do 1000!: \n");
        }
    }while(dlzka < 1 || dlzka > 1000);
    
    char znak;
    srand(time(NULL));
    for(int i = 0; i < dlzka; i++){
        znak = (rand()%(57-47)) + 47;
        printf("novy znak: %c\n", znak);
        fprintf(subor_s_heslom, "%c", znak);
    }


    fclose(subor_s_heslom);

    return 0;
}
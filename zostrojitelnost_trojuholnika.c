#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Toto je program na zistenie zostrojiteľnosti trojuholníka


*/
//abc nastavujem ako -1 aby to spustilo aspon raz loop vo fn vycitaj_abc
float a, b, c = -1;



/*nepustí dalej dokial nezadáš klad avšak zadaním písmen vytvoríš nekončiacu sľučku*/
void vycitaj_abc()
{
    while(a<=0)
    {
        printf("Zadaj hodnotu pre a:\n");
        scanf("%f", &a);
        if(a<=0)
        {
            printf("a musí byť kladné!\n");
        }
    }


    while(b<=0)
    {
        printf("Zadaj hodnotu pre b:\n");
        scanf("%f", &b);
        if(b<=0)
        {
            printf("b musí byť kladné!\n");
        }
    }


    while(c<=0)
    {
        printf("Zadaj hodnotu pre c:\n");
        scanf("%f", &c);
        if(c<=0)
        {
            printf("c musí byť kladné!\n");
        }
    }

}

bool skuska_zostrojitelnosti_trojuholnika()
{
    if(a + b <= c)
    {
        return 0;
    }
    if(a + c <= b)
    {
        return 0;
    }
    if(b + c <= a)
    {
        return 0;
    }

    return 1;
}


int main()
{
    printf("Hello world!\n");
    vycitaj_abc();

    printf("a je %f. b je %f. c je %f\n", a, b, c);

    if(skuska_zostrojitelnosti_trojuholnika())
    {
        printf("Trojuholnik je zostrojitelny.\n");
    }else{
        printf("Trojuholnik nieje zostrojitelny.\n");
    }

    return 0;
}

/*
    Questo programma chiede in input quale formula fisica si vuole eseguire e restituisce il calcolo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define GRAV 0.000000000667

int selector;
float speed(), f_centrifuga(), f_gravitazione(), e_cinetica(), m_inerzia();

char *list[5] = {"1 - Velocita'", "2 - Forza centrifuga", "3 - Forza gravitazionale", "4 - Energia cinetica", "5 - Momento d'inerzia"};

int main(){
    printf("Formule di fisica\n");
    printf("Scrivi un numero da 1 a 5 per scegliere quale formula eseguire, se non sai quali formule sono disponibili scrivi 0: ");
    scanf("%d", &selector);

    switch (selector)
    {
    case 1:
        printf("Hai selezionato VELOCITA'");
        speed();
        break;
    case 2:
        printf("Hai selezionato FORZA CENTRIFUGA");
        f_centrifuga();
        break;
    case 3:
        printf("Hai selezionato FORZA GRAVITAZIONALE");
        f_gravitazione();
        break;
    case 4:
        printf("Hai selezionato ENERGIA CINETICA");
        e_cinetica();
        break;
    case 5:
        printf("Hai selezionato MOMENTO D'INERZIA");
        m_inerzia();
        break;
    default:
        printf("Le formule disponibili sono: \n");
        for (size_t i = 0; i < 5; i++)
        {
            printf("%s\n", list[i]);
        }
        main();
        break;
    }

    printf("\nEsecuzione terminata.\nPremi qualsiasi tasto per uscire dal programma.");
    getch();
}

float speed(){
    float spazio, tempo, risultato;

    printf("Scrivi il valore dello spazio (m): ");
    scanf("%f", &spazio);
    printf("Scrivi il valore del tempo (sec): ");
    scanf("%f", &tempo);

    risultato = spazio / tempo;
    printf("Il valore della velocita' e' %.2f m/s", risultato);
}

float f_centrifuga(){
    float massa, velocita, raggio, risultato;

    printf("Scrivi la massa del corpo (Kg): ");
    scanf("%f", &massa);
    printf("Scrivi la velocita' del corpo (m/s): ");
    scanf("%f", &velocita);
    printf("Scrivi il raggio della curva (m): ");
    scanf("%f", &raggio);

    risultato = massa * pow(velocita, 2) / raggio;
    printf("Il valore della forza centrifuga e' %.2f N", risultato);
}

float f_gravitazione(){
    float massa1, massa2, distanza, risultato;

    printf("Scrivi il valore della prima massa (Kg): ");
    scanf("%f", &massa1);
    printf("Scrivi il valore della seconda massa (Kg): ");
    scanf("%f", &massa2);
    printf("Scrivi il valore della distanza tra i corpi (m): ");
    scanf("%f", &distanza);

    risultato = (GRAV * massa1 * massa2) / pow(distanza, 2);
    printf("Il valore della forza gravitazionale e' %f N", risultato);
}

float e_cinetica(){
    float massa, velocita, risultato;

    printf("Scrivi il valore della massa (Kg): ");
    scanf("%f", &massa);
    printf("Scrivi il valore della velocita' (m/s): ");
    scanf("%f", &velocita);

    risultato = (massa / 2) * pow(velocita, 2);
    printf("Il valore dell'energia cinetica e' %.2f j", risultato);
}

float m_inerzia(){
    int tipo;
    float massa, raggio, risultato;

    printf("Di che corpo vuoi calcolare il momento d'inerzia?\n (1 - sfera) (2 - cilindro/disco) (0 - default)\n");
    scanf("%d", &tipo);

    printf("Scrivi il valore della massa (Kg): ");
    scanf("%f", &massa);
    printf("Scrivi il valore del raggio (m): ");
    scanf("%f", &raggio);

    switch (tipo)
    {
    case 1:
        risultato = 2 * (massa * pow(raggio, 2)) / 5;
        break;
    case 2:
        risultato = (massa * pow(raggio, 2)) / 2;
        break;
    default:
        risultato = massa * pow(raggio, 2);
        break;
    }

    printf("Il valore del momento d'inerzia e' %.2f Kg*m2", risultato);
}
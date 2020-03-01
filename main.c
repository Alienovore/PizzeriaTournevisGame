#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void step1(int a);
void step2(int a);
void step3(int a);
void step4(int a);
void step5(int a);
int checkAnswer(int a, int b);
void endOfGame(int a);
int pizza;

int main()
{
    printf("Bienvenue dans l'adaptation en game-novel inspiré de l'histoire de la \"pizzeria\" tournevis située à Nantes\nOn y va ? \n1 - Oui\n2 - Non\n");
    step1(checkAnswer(1, 2));
}

void step1(int a)
{
    switch (a)
    {
    case 1:
        printf("Vous êtes devant une pizzeria dans la rue du Saint Kebab\nVous pouvez :\n1 - Entrer dans la pizzeria\n2 - Continuer votre chemin vers un Tacos\n");
        step2(checkAnswer(1, 2));
        break;

    case 2:
        exit(0);
        break;
    }
}

void step2(int a)
{
    switch (a)
    {
    case 1:
        printf("Vous entrez dans la pizzeria\nVous pouvez :\n1 - Demander une table\n2 - Commander à emporter\n");
        step3(checkAnswer(1, 2));
        break;

    case 2:
        printf("Bravo vous avez évité tous les problèmes qui auraient pu se présenter en allant à la pizzeria ! \nVous pouvez :\n1 - Recommencer\n2 - Quitter\n");
        endOfGame(checkAnswer(1, 2));
        break;
    }
}

void step3(int a)
{
    switch (a)
    {
    case 1:
        printf("Vous demandez une table\nVous pouvez commander:\n1 - Une pizza royale\n2 - Une pizza chèvre miel\n3 - Une pizza à l'ananas\n");
        step4(checkAnswer(1, 3));
        break;

    case 2:
        printf("Vous commandez à emporter\nVous pouvez choisir:\n1 - Une pizza royale\n2 - Une pizza chèvre miel\n");
        step4(checkAnswer(1, 2));
        break;
    }
}

void step4(int a)
{
    switch (a)
    {
    case 1:
        pizza = 1;
        printf("Vous commandez une pizza royale\nVous pouvez:\n1 - Attendre 45 minutes\n");
        step5(checkAnswer(1, 1));
        break;

    case 2:
        pizza = 2;
        printf("Vous commandez une pizza chèvre miel\nVous pouvez:\n1 - Attendre 45 minutes\n");
        step5(checkAnswer(1, 1));
        break;

    case 3:
        pizza = 3;
        printf("Vous choisissez une pizza à l'ananas.\nLe patron de la pizzaria arrive et commence a vous insulter\n(mais entre nous vous l'avez bien mérité, une pizza a l'ananas c'est pas terrible)\n");
        printf("Vous pouvez :\n1 - Vous plaindre\n2 - Partir\n");
        step5(checkAnswer(1, 2));
        break;
    }
}

void step5(int a)
{
}

int checkAnswer(int a, int b) // Implementer la vérification du type pour éviter les crash
{
    int choice = 0;
    scanf("%d", &choice);
    while (choice < a || choice > b)
    {
        printf("Veuillez entrer une valeur correcte\n");
        scanf("%d", &choice);
    }
    return choice;
}

void endOfGame(int a)
{
    switch (a)
    {
    case 1:
        step1(1);
        break;

    case 0:
        exit(0);
        break;
    }
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void step1(int a);
void step2(int a);
void step3(int a);
void step4(int a);
void step5(int a);
void step6(int a);
void step7(int a);
void step8(int a);
void step9(int a);
int cleanStdin();
int checkAnswer(int a, int b);
int checkAnswerShift(int a, int b, int shift);
void endOfGame(int a);
int pizza;
int rand_num;

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
        printf("Tu es devant une pizzeria dans la rue du Saint Kebab\nTu peux :\n1 - Entrer dans la pizzeria\n2 - Continuer ton chemin vers un Tacos\n");
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
        printf("Tu entres dans la pizzeria\nTu peux :\n1 - Demander une table\n2 - Commander à emporter\n");
        step3(checkAnswer(1, 2));
        break;

    case 2:
        printf("Bravo tu as évité tous les problèmes qui auraient pu se présenter en allant à la pizzeria ! \nTu peux :\n1 - Recommencer\n2 - Quitter\n");
        endOfGame(checkAnswer(1, 2));
        break;
    }
}

void step3(int a)
{
    switch (a)
    {
    case 1:
        printf("Tu demandes une table\nTu peux commander:\n1 - Une pizza royale\n2 - Une pizza chèvre miel\n3 - Une pizza à l'ananas\n");
        step4(checkAnswer(1, 3));
        break;

    case 2:
        printf("Tu commandes à emporter\nTu peux choisir:\n1 - Une pizza royale\n2 - Une pizza chèvre miel\n");
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
        printf("Tu commandes une pizza royale\nTu peux:\n1 - Attendre\n");
        step5(checkAnswer(1, 1));
        break;

    case 2:
        pizza = 2;
        printf("Tu commandes une pizza chèvre miel\nTu peux:\n1 - Attendre\n");
        step5(checkAnswer(1, 1));
        break;

    case 3:
        pizza = 3;
        printf("Tu choisis une pizza à l'ananas.\nLe serveur de la pizzaria arrive et commence a t'insulter\n(mais entre nous tu l'a bien mérité, une pizza a l'ananas c'est pas terrible)\n");
        printf("Tu peux :\n1 - Te plaindre\n2 - Partir\n");
        step6(checkAnswerShift(1, 2, 1));
        break;
    }
}

void step5(int a)
{
    printf("Ca fait 45 minutes que tu attends\nTu peux:\n1 - Continuer d'attendre\n2 - Te plaindre\n");
    step6(checkAnswer(1, 2));
}

void step6(int a)
{
    switch (a)
    {
    case 1: //Continuer d'attendre
        printf("Tu attends patiemment\n");
        sleep(2);
        printf("Tu entends des cris dans la cuisine\n");
        sleep(2);
        if (pizza == 1)
        {
            printf("On te sert finalement la bonne pizza ! Tu peux :\n1 - Recommencer\n2 - Partir\n");
            endOfGame(checkAnswer(1, 2));
        }

        printf("On te sert finalement la mauvaise pizza !\n");
        a++;

    case 2: //Se plaindre
        pizza = 2;
        printf("Tu te plains du restaurant au chef\n");
        sleep(2);
        printf("Le patron commence à s'énerver\n");
        sleep(2);
        printf("Tu peux à présent voir voir des tournevis et des champignons voler dans la cuisine\net le patron se met a hurler comme Etchbest\n1 - Tu tentes de parler avec lui\n2 - Tu te dirige vers la sortie\n");
        checkAnswer(1, 2);
        printf("Le patron commence à te menacer avec un tournevis\n1 - Sortir de la pizzeria et courir\n2 - Se laisser attaquer avec le tournevis\n");
        step7(checkAnswer(1, 2));
        break;

    case 3: //Quitter
        pizza = 3;
        printf("Tu décide de partir");
        printf("Tu peux :\n1 - Recommencer\n2 - Quitter\n");
        endOfGame(checkAnswer(1, 2));
        break;
    }
}

void step7(int a)
{
    switch (a)
    {
    case 1: //Début course poursuite
        srand(time(NULL));
        rand_num = (rand() % (4 - 1 - 1)) + 1;
        if (rand_num == 1)
        {
            printf("Le patron commence à te courir après\n");
            sleep(2);
            printf("Tu te rappelle que tu fais du carcours et tu escalade les murets et les grillages pour s'enfuir\n");
            sleep(2);
            step9(1);
        }
        else
        {
            printf("Le patron monte sur son scooter qui semble débridé\nTu peux :\n1 - Tenter de te cacher dans une poubelle\n2 - Continuer à courir");
            step8(checkAnswer(1, 2));
        }
        break;

    case 2: //mort et eog
        printf("Le patron t'attrape et te transperce de son tournevis\n");
        sleep(2);
        printf("Tu meurs sur le coup\n1 - Recommencer\n2 - Quitter\n");
        endOfGame(checkAnswer(1, 2));
        break;
    }
}

void step8(int a)
{
    switch (a)
    {
    case 1:
        step9(1);
        break;
    case 2:
        printf("Tu prends les escalier en espèrant qu'il ne te suive pas\n");
        srand(time(NULL));
        rand_num = (rand() % (4 - 1 - 1)) + 1;
        if (rand_num == 1)
        {
            printf("Il te suit dans les escaliers avec son scooter\nTu peux :\n1 - Continuer à te cacher et tenter de t'enfuir en faisant du parkour\n2 - Abandonner désepérément\n");
            step9(checkAnswerShift(1, 2, 1));
        }
        else
        {
            step9(1);
        }
        break;
    }
}

void step9(int a)
{
    switch (a)
    {
    case 1:
        printf("Tu arrives finalement à t'enfuir\n Tu l'entends au loin ronchonner puis repartir en faisant des burns sur la route\n");
        printf("Tu as fini, tu peux :\n1 - Rejouer\n2 - Quitter\n");
        endOfGame(checkAnswer(1, 2));
        break;
    case 2:
        step9(1);
        break;
    case 3:
        printf("Tu te fais finalement écraser par son scooter en Y, triste vie\nTu peux :\n1 - Recommencer\n2 - Quitter\n");
        endOfGame(checkAnswer(1, 2));
        break;
    }
}

int checkAnswer(int a, int b) // Implementer la vérification du type pour éviter les crash
{
    int choice = 0;
    scanf("%d", &choice);
    while (choice < a || choice > b)
    {
        printf("Entre une valeur correcte ^^'\n");
        cleanStdin();
        scanf("%d", &choice);
    }
    return choice;
}

int checkAnswerShift(int a, int b, int shift) // Implementer la vérification du type pour éviter les crash
{
    int choice = 0;
    scanf("%d", &choice);
    while (choice < a || choice > b)
    {
        printf("Entre une valeur correcte ^^'\n");
        cleanStdin();
        scanf("%d", &choice);
    }
    choice += shift;
    return choice;
}

void endOfGame(int a)
{
    switch (a)
    {
    case 1:
        step1(1);
        break;

    case 2:
        exit(0);
        break;
    }
}

int cleanStdin()
{
    int c;
    while (((c = getchar()) != '\n') && c != EOF)
        ;
    return 0;
}
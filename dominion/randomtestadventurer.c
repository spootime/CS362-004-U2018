#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>       /* time */



int main()
{
    srand(time(NULL));
    struct gameState G;
    int i, temp=0, testResult=0, result, random=0;
    random = rand() % 30;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    result = initializeGame(2, k, random, &G);
    assert(result == 0);
    printf("Card Test 1: testing adventurer\n");


    

    for (i=4; i < 7; i++)
    {
        G.supplyCount[i] = 0;
    }

    int card, choice1, choice2, choice3, handPos, bonus;
    card=7;
    choice1=0;
    choice2=0;
    choice3=0;
    handPos=0;
    bonus=0;

    int randvar, failtracker=0;
    randvar = rand() % 4;

    for (i=0; i < randvar; i++)
    {
        testResult = cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
    }

    if (testResult != 0)
    {
        failtracker++;
    }

    for (i=4; i < 7; i++)
    {
        temp = supplyCount(i, &G);
        testResult = testResult + temp;
    }

    //printf("randvar is: %d", randvar);
    //printf("testresult is: %d", testResult);


    if (testResult == (2*randvar))
    {
        printf(" All tests passed\n");
    }
    else
    {
        printf("    -test 2 failed %d times\n", failtracker);
    }

}
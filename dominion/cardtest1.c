#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
    struct gameState G;
    int i, temp=0, testResult, result, random=0;
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

    

    testResult = cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);

    if (testResult == 0)
    {
        printf("    -test 1 passed\n");
    }
    else
    {
        printf("    -test 1 failed\n");
        //assert(testResult == 0);
        return 0;
    }

    testResult=0;
    for (i=4; i < 7; i++)
    {
        temp = supplyCount(i, &G);
        testResult = testResult + temp;
    }

    if (testResult == 2)
    {
        printf("    -test 2 passed\n");
    }
    else
    {
        printf("    -test 2 failed\n");
        printf("    -testResult is: %d\n", testResult);
        //assert(testResult == 2);
        return 0;
    }



    printf("All tests passed.\n");
}
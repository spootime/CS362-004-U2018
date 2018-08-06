#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>       /* time */
#include <assert.h>


int main()
{
    srand(time(NULL));
    struct gameState G;
    int testResult, result, random=0;
    random = rand() % 30;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    result = initializeGame(2, k, random, &G);
    assert(result == 0);
    printf("Card Test 4: testing village card\n");

    int card, choice1, choice2, choice3, handPos, bonus;
    card=10;
    choice1=0;
    choice2=0;
    choice3=0;
    handPos=1;
    bonus=0;

    int testNum, i;
    int trackfails=0;
    testNum = rand() % 15;

    for (i=0; i < testNum; i++)
    {
        testResult = cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
        if (testResult != -1)
        {
            trackfails++;
        }
    }
    

    
    if (trackfails < 1)
    {
        printf("Garden passed %d tests\n", testNum);
    }
    else
    {
        printf("Garden failed %d tests\n", trackfails);
        //assert (testResult == -1);
        return 0;
    }
    
}
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
    int result, random=0;
    random = rand() % 30;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    result = initializeGame(2, k, random, &G);
    assert(result == 0);
    int testResult=0, temp, i;
    printf("Unit Test 4: Testing getcost function\n");
    

    for (i=0; i<10; i++)
    {
        temp=getCost(i);
        testResult = (testResult + temp);
    }

    //should be equal
    
    
    if (testResult == 39){ // sum of first 10 cards
        printf("    -test 1 passed\n");
    }
    else{
        printf("    -test 1 failed\n");
        assert(testResult == 39);
        return 0;
    }
    
    testResult = getCost(4234);
    if (testResult == -1){ // not a card
        printf("    -test 2 passed\n");
    }
    else{
        printf("    -test 2 failed\n");
        assert(testResult == -1);
        return 0;
    }

    testResult=0;
    for (i=0; i<27; i++)
    {
        temp=getCost(i);
        testResult = (testResult + temp);
    }

    if (testResult == 105){ // sum of all
        printf("    -test 3 passed\n");
    }
    else{
        printf("    -test 3 failed\n");
        assert(testResult == 105);
        return 0;
    }
    
    printf("All tests passed\n");
}
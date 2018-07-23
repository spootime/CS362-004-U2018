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
    int testResult;
    printf("Unit Test 2: testing isGameOver\n");
    
    for(int i = 25; i >= 0; i--){
		G.supplyCount[i] = 10;
	}

    //game should not be over
    
    testResult = isGameOver(&G);
    if (testResult == 0){
        printf("    -test 1 passed\n");
    }
    else{
        printf("    -test 1 failed\n");
        assert(testResult == 0);
    }
    
    //test province game ender
    G.supplyCount[3] = 0;
    testResult = isGameOver(&G);
    if (testResult == 1){
        printf("    -test 2 passed\n");
    }
    else{
        printf("    -test 2 failed\n");
        assert(testResult == 1);
        return 0;
    }

    // test 3 supply pile at zero
    G.supplyCount[3] = 10;
    G.supplyCount[9] = 0;
    G.supplyCount[10] = 0;
    G.supplyCount[11] = 0;

    testResult = isGameOver(&G);
    if (testResult == 1){
        printf("    -test 3 passed\n");
    }
    else{
        printf("    -test 3 failed\n");
        assert(testResult == 1);
        return 0;
    }
    printf("All tests passed\n");
}
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
    printf("Unit Test 1: testing supplyCount\n");
    G.supplyCount[9] = 25;
    G.supplyCount[10] = -5;
    G.supplyCount[11] = 0;
    if (supplyCount(9, &G) == 25)
    {
        printf("    -test 1 passed\n");
    }
    else
    {
        printf("    -test 1 failed\n");
        assert(supplyCount(9, &G) == 25);
        return 0;
    }

    if (supplyCount(10, &G) == -5)
    {
        printf("    -test 2 passed\n");
    }
    else
    {
        printf("    -test 2 failed\n");
        assert(supplyCount(10, &G) == -5);
        return 0;
    }

    if (supplyCount(11, &G) == 0)
    {
        printf("    -test 3 passed\n");
    }
    else
    {
        printf("    -test 3 failed\n");
        assert(supplyCount(11, &G) == 0);
        return 0;
    }
    printf("All tests passed.\n");
}
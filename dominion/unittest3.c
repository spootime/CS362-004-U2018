#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//had to bring in because this isnt declared in dominion.h. BUG I believe
int compare2(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  if (*(int*)a < *(int*)b)
    return -1;
  return 0;
}


int main()
{
    struct gameState G;
    int result, random=0;
    random = rand() % 30;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    result = initializeGame(2, k, random, &G);
    assert(result == 0);
    int testResult, a, b;
    printf("Unit Test 3: Testing compare function\n");
    



    //should be equal
    a=0;
    b=0;
    testResult = compare2(&a, &b);
    if (testResult == 0){
        printf("    -test 1 passed\n");
    }
    else{
        printf("    -test 1 failed\n");
        assert(testResult == 0);
    }
    
    //A should be higher
    a=500000;
    b=-500000;
    testResult = compare2(&a, &b);
    if (testResult == 1){
        printf("    -test 2 passed\n");
    }
    else{
        printf("    -test 2 failed\n");
        assert(testResult == 1);
        return 0;
    }

    //B should be higher
    a=-500000;
    b=500000;
    testResult = compare2(&a, &b);
    if (testResult == -1){
        printf("    -test 3 passed\n");
    }
    else{
        printf("    -test 3 failed\n");
        assert(testResult == -1);
        return 0;
    }
    
    //B should be higher testing 0/-1
    a=-1;
    b=0;
    testResult = compare2(&a, &b);
    if (testResult == -1){
        printf("    -test 4 passed\n");
    }
    else{
        printf("    -test 4 failed\n");
        assert(testResult == -1);
        return 0;
    }

    //A should be higher testing -5/-1
    a=-1;
    b=-5;
    testResult = compare2(&a, &b);
    if (testResult == 1){
        printf("    -test 5 passed\n");
    }
    else{
        printf("    -test 5 failed\n");
        assert(testResult == 1);
        return 0;
    }
    
    printf("All tests passed\n");
}
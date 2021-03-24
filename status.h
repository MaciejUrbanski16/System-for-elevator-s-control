#pragma once

#include "elevator.h"
#include <stdio.h>


typedef struct Status{
    char *statusID;//[3*MAX_AMOUNT_OF_ELEVATORS];
    char elevatorsInBuild[MAX_FLOOR][3 * MAX_AMOUNT_OF_ELEVATORS];
}Status;

void showStatus(Elevator *e);

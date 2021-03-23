#pragma once
#include <stdint.h>

#define MAX_AMOUNT_OF_ELEVATORS  16
#define CAPACITY_OF_ELEVATOR 5

#define MAX_FLOOR  20

//description of elevator's direction
enum{
    UP   = 2,
    DOWN = 1,
    NONE = 0
};

//data which represent person who wants to use an elevator potentially
typedef struct Person{
    uint8_t isWaiting;
    uint8_t activePlace;
    uint32_t floor;
    uint32_t objectiveFloor;
}Person;

//data which represent a particular elevator
typedef struct Elevator{
    uint32_t ID;
    uint32_t currFloor;
    uint32_t objectiveFloor;
    uint8_t empty;
    uint8_t filledUp;
    Person people[CAPACITY_OF_ELEVATOR];
    uint8_t currDir;
    int8_t nextDir;
    int8_t latestDir;
}Elevator;
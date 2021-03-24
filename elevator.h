#pragma once
#include <stdint.h>
#include <stdlib.h>

#define MAX_AMOUNT_OF_ELEVATORS     16
#define CAPACITY_OF_ELEVATOR        5

#define MAX_FLOOR                   20

//description of elevator's directions
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
    Person people[CAPACITY_OF_ELEVATOR];
    uint8_t currDir;
    int8_t nextDir;
    int8_t latestDir;
}Elevator;

void init(Elevator *elevators);

void setLatestDirOfElevator(Elevator *e, int dir);

void setDirOfElevator(Elevator *e);

uint16_t getFirstFreeElevator(Elevator *pElevator, int floor);

uint32_t getTheClosestObjectiveFloor(Elevator elevator);

Elevator pickUp(int floor, int dir, Elevator *elevators);

Elevator useNewElevator(Elevator *elevators, int floor, int dir);

void setNewElevator(Elevator *tempElevator, int floor, int dir);

void update(Elevator e, Elevator *elevators);

int checkIfElevatorEmpty(Elevator e);

void step(Elevator *elevators);
#include "status.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <conio.h>


void showStatus(Elevator *e){

    Status statusOfElevators;
    statusOfElevators.statusID = "1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16\n";

    //preparing table with chars (clearing them)
    for(int i=0; i < MAX_FLOOR; i++){
        for(int j = 0; j< 3*MAX_AMOUNT_OF_ELEVATORS; j++){
            statusOfElevators.elevatorsInBuild[i][j] = ' ';
            if(j == 3*MAX_AMOUNT_OF_ELEVATORS-1){
                statusOfElevators.elevatorsInBuild[i][j] = '\n';
            }
        }

    }

    //assign proper chars to show at the console
    for(int i=0; i < MAX_FLOOR; i++){
        for(int j=0; j< MAX_AMOUNT_OF_ELEVATORS; j++){

            if(e[j].currFloor == MAX_FLOOR - i - 1){
                statusOfElevators.elevatorsInBuild[i][3*j] = 'E';
            }
            for(int k = 0; k < CAPACITY_OF_ELEVATOR; k++){
                if(e[j].people[k].isWaiting == 1 && e[j].people[k].floor == MAX_FLOOR - i - 1){
                    statusOfElevators.elevatorsInBuild[i][3*j + 1] = 'C';
                }
                if(e[j].currFloor == MAX_FLOOR - i - 1 && e[j].people[k].activePlace == 1 && e[j].currFloor == e[j].people[k].objectiveFloor){
                    statusOfElevators.elevatorsInBuild[i][3*j + 1] = 'C';
                }
            }
        }
    }


    system("cls");

    //printf current status of the elevators
    printf("%s\n",statusOfElevators.statusID);
    printf("%s", statusOfElevators.elevatorsInBuild);
    printf("---------------------------------------------\n");

}


void setLatestDirOfElevator(Elevator *e, int dir) {

    if(dir > 0){
        e->latestDir = UP;
    }
    else if(dir < 0){
        e->latestDir = DOWN;
    }
}

void setDirOfElevator(Elevator *e){

    if(e->currFloor < e->objectiveFloor){
        e->currDir = UP;
    }
    else if(e->currFloor > e->objectiveFloor){
        e->currDir = DOWN;
    }
}

uint16_t getFirstFreeElevator(Elevator *pElevator, int floor) {

    int firstFreeElevator = -1;
    int theLeastDistance = MAX_FLOOR;

    for(int i = 0; i< MAX_AMOUNT_OF_ELEVATORS; i++){
        if(pElevator[i].empty == 1){

            if(theLeastDistance > abs(floor - pElevator[i].currFloor)){
                theLeastDistance = abs(floor - pElevator[i].currFloor);
                firstFreeElevator = i;
            }
        }
    }
    return firstFreeElevator + 1;
}

uint32_t getTheClosestObjectiveFloor(Elevator elevator) {

    int distanceUp = MAX_FLOOR + 1,distanceDown = -MAX_FLOOR - 1, tempDistance;
    for(int i =0; i< 5; i++){
        if(elevator.currDir == UP) {
            if (elevator.people[i].isWaiting == 1) {
                tempDistance = elevator.people[i].floor - elevator.currFloor;
                if (tempDistance < distanceUp && distanceUp != 0) {
                    distanceUp = tempDistance;
                }
            }
            else if (elevator.people[i].activePlace == 1) {
                tempDistance = elevator.people[i].objectiveFloor - elevator.currFloor;
                if (tempDistance < distanceUp && distanceUp != 0) {
                    distanceUp = tempDistance;
                }
            }
        }


        else if(elevator.currDir == DOWN){

            if (elevator.people[i].isWaiting == 1) {
                tempDistance = elevator.people[i].floor - elevator.currFloor ;
                if (tempDistance > distanceDown && distanceDown != 0) {
                    distanceDown = tempDistance;
                }
            }
            else if (elevator.people[i].activePlace == 1) {
                tempDistance = elevator.people[i].objectiveFloor - elevator.currFloor;
                if (tempDistance > distanceDown && distanceUp != 0) {
                    distanceDown = tempDistance;
                }
            }
        }

        else if(elevator.currDir == NONE){
            distanceDown = 0;
        }
    }

    return elevator.currDir == UP ? elevator.currFloor + distanceUp : elevator.currFloor + distanceDown;
}

Elevator pickUp(int floor, int dir, Elevator *elevators){

 Elevator tempElevator;
 uint8_t clientGotInWithOther = 0;

     for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS; i++) {

         //first we have to service a first client, but if another client has common route, we can also service him

         //when he wants to use the elevator (before getting in)

         if (elevators[i].empty == 0) {

             if (elevators[i].currDir == UP && floor > elevators[i].currFloor && dir > 0 ){
                 //when elevator's dir is up:

                 //if the routes of different clients are covered  --> clients get in the same elevator

                 for (int j = 0; j < 5; j++) {
                     if (elevators[i].people[j].activePlace == 0 && elevators[i].people[j].isWaiting == 0) {

                         elevators[i].people[j].isWaiting = 1;
                         elevators[i].people[j].objectiveFloor = floor + dir;
                         elevators[i].people[j].floor = floor;

                         elevators[i].latestDir = UP;

                         tempElevator = elevators[i];
                         clientGotInWithOther = 1;
                         break;
                     }
                 }
                 //the closest floor to the current floor is objective floor
                 tempElevator.objectiveFloor = getTheClosestObjectiveFloor(tempElevator);

                 if(clientGotInWithOther == 1){
                     break;
                 }
             }

             else if(elevators[i].currDir == DOWN && floor < elevators[i].currFloor && dir < 0 ){
                 //when elevator's dir is down:

                 for (int j = 0; j < 5; j++) {
                     if (elevators[i].people[j].activePlace == 0 && elevators[i].people[j].isWaiting == 0) {
                         //free place in the elevator

                         elevators[i].people[j].isWaiting = 1;
                         elevators[i].people[j].objectiveFloor = floor + dir;
                         elevators[i].people[j].floor = floor;

                         elevators[i].latestDir = DOWN;

                         tempElevator = elevators[i];
                         clientGotInWithOther = 1;
                         break;
                     }

                 }

                 //the closest floor to the current floor is objective floor
                 tempElevator.objectiveFloor = getTheClosestObjectiveFloor(tempElevator);

                 if(clientGotInWithOther == 1){
                     break;
                 }
             }
         }
     }
    if(clientGotInWithOther == 0) {
        //if client did not get in with other clients
        //new elevator has to be used

        tempElevator.ID = getFirstFreeElevator(elevators, floor);



        if(tempElevator.currFloor == floor){
            tempElevator.currFloor = floor;
            tempElevator.objectiveFloor = floor + dir;
        }
        else {
            tempElevator.currFloor = elevators[tempElevator.ID - 1].currFloor;
            tempElevator.objectiveFloor = floor;

            if(tempElevator.currFloor == tempElevator.objectiveFloor){
                tempElevator.objectiveFloor = floor + dir;
            }

        }

        tempElevator.empty = 0;
        setDirOfElevator(&tempElevator);


        for(int i = 0; i< 5; i++){
            if(i == 0){
                tempElevator.people[i].activePlace = 0;
                tempElevator.people[i].isWaiting = 1;
                tempElevator.people[i].floor = floor;
                tempElevator.people[i].objectiveFloor = floor + dir;
            }
            else{
                tempElevator.people[i].activePlace = 0;
                tempElevator.people[i].isWaiting = 0;
            }
        }
        //the closest floor to the current floor is objective floor
        tempElevator.objectiveFloor = getTheClosestObjectiveFloor(tempElevator);
    }

    setDirOfElevator(&tempElevator);
    setLatestDirOfElevator(&tempElevator, dir);

    return tempElevator;
}




void update(Elevator e, Elevator *elevators){

    for(int i=0; i<MAX_AMOUNT_OF_ELEVATORS; i++){
        if(elevators[i].ID == e.ID){
            elevators[i] = e;
            break;
        }
    }
}

int checkIfElevatorEmpty(Elevator e){
    int howManyFree = 0;
    for(int i = 0 ; i< 5; i++){
        if(e.people[i].activePlace == 0 && e.people[i].isWaiting == 0){
            howManyFree++;
        }
    }
    if(howManyFree == 5) return 1;
    else return 0;

}

void step(Elevator *elevators){
    int i = 0;

    //executing one step of simulation
    for(i = 0 ; i < MAX_AMOUNT_OF_ELEVATORS; i++) {
        if (elevators[i].empty == 0) {

            if (elevators[i].currFloor == elevators[i].objectiveFloor) {


                for (int j = 0; j < 5; j++) {

                    if (elevators[i].people[j].floor == elevators[i].currFloor && elevators[i].people[j].activePlace == 0 && elevators[i].people[j].isWaiting == 1) {

                        //getting on the elevator
                        //person gets on the elevator
                        elevators[i].people[j].activePlace = 1;
                        elevators[i].people[j].isWaiting = 0;

                        //assignment objective floor of the elevator after a person got in the elevator
                        elevators[i].objectiveFloor = getTheClosestObjectiveFloor(elevators[i]);

                        setDirOfElevator(&elevators[i]);
                    }

                    //getting off the elevator
                    else if (elevators[i].people[j].objectiveFloor == elevators[i].currFloor && elevators[i].people[j].activePlace == 1 && elevators[i].people[j].isWaiting == 0) {

                        elevators[i].people[j].activePlace = 0;
                        elevators[i].people[j].isWaiting = 0;

                        //assignment objective floor of the elevator after a person got off the elevator
                        elevators[i].objectiveFloor = getTheClosestObjectiveFloor(elevators[i]);

                        setDirOfElevator(&elevators[i]);

                        if(checkIfElevatorEmpty(elevators[i]) == 1){
                            elevators[i].currDir = NONE;
                            elevators[i].empty = 1;
                        }
                        elevators[i].objectiveFloor = getTheClosestObjectiveFloor(elevators[i]);

                    }


                }

            } else if (elevators[i].currFloor > elevators[i].objectiveFloor) {
                //move of elevator
                elevators[i].currFloor--;
            } else if (elevators[i].currFloor < elevators[i].objectiveFloor) {
                //move of elevator
                elevators[i].currFloor++;
            }
        }
    }
}

Elevator* status(){
    //TODO how to return statusID
}

void init(Elevator *elevators){
    for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS; i++){

        elevators[i].currFloor = 0;
        elevators[i].empty = 1;
        elevators[i].ID = i+1;
        elevators[i].currDir = NONE;
        elevators[i].latestDir = NONE;
        elevators[i].filledUp = 0;

        for(int j=0; j<5;j++){
            elevators[i].people[j].activePlace = 0;
            elevators[i].people[j].isWaiting = 0;
        }
    }
}


int main() {

    Elevator elevators[MAX_AMOUNT_OF_ELEVATORS];

    init(elevators);

    while(1){
        char control;
        uint8_t exit = 0;
        control = getch();
        while(control && exit==0) {

            if (control == 't') {
                step(elevators);
                showStatus(elevators);
            } else if (control == 'p') {

                showStatus(elevators);
                printf("\nEnter floor and direction: ");
                int floor, dir;

                scanf("%d %d", &floor, &dir);
                if(floor < 0 || floor >= MAX_FLOOR || floor + dir < 0 || floor + dir >= MAX_FLOOR){
                    printf("\nInvalid input!");
                }
                else {
                    Elevator e6 = pickUp(floor, dir, elevators);
                    update(e6, elevators);
                }
            }
            else if(control == 'q'){
                exit = 1;
            }

            control = getch();
        }
        if(exit){
            break;
        }

    }

    return 0;
}

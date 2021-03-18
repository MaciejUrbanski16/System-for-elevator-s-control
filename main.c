#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_AMOUNT_OF_ELEVATORS  16

const uint32_t max_floor = 15;

int currAmountOfElevators = 0;




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
    uint32_t curr_floor;
    uint32_t objective_floor;
    int8_t empty;
    Person people[5];
    int8_t currDirUp; //{0 - down, 1 - up
    uint8_t actualAmountOfPeople;
}Elevator;

int getFirstFreeElevator(Elevator *pElevator) {

    int firstFreeElevator = -1;
    for(int i = 0; i< MAX_AMOUNT_OF_ELEVATORS; i++){
        if(pElevator[i].empty == 1){
           firstFreeElevator = i;
           break;
        }
    }
    return firstFreeElevator + 1;
}
uint32_t getTheClosestObjectiveFloor(Elevator elevator) {

    int minDifferenceBetweenFloors = max_floor;
    for(int i = 0 ; i < 5; i++){
        if(elevator.people[i].activePlace == 1){
            if(minDifferenceBetweenFloors > (elevator.curr_floor - elevator.people[i].objectiveFloor)){
                minDifferenceBetweenFloors = elevator.curr_floor - elevator.people[i].objectiveFloor;
            }
        }
    }
    return abs(minDifferenceBetweenFloors);
}

uint32_t getFirstObjecyiveFloor(Elevator elevator) {

    int distance = max_floor, tempDistance;
    for(int i =0; i< 5; i++){
        if(elevator.currDirUp == 1){
            if(elevator.people[i].isWaiting == 1){
                tempDistance = elevator.people[i].floor - elevator.curr_floor;
                if(tempDistance < distance && distance != 0){
                    distance = tempDistance;
                }
            }
            else if(elevator.people[i].activePlace == 1){
                tempDistance = elevator.people[i].objectiveFloor - elevator.curr_floor;
                if(tempDistance < distance && distance != 0){
                    distance = tempDistance;
                }
            }
        }


        else if(elevator.currDirUp == 0){

        }
    }
    return elevator.curr_floor + distance;
}

Elevator pickUp(int floor, int dir, Elevator *elevators, int *currAm){

 Elevator tempElevator;
 uint8_t clientGotInWithOther = 0;

     for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS; i++) {

         //first we have to service a first client, but if another client has common route, we can also service him

         if (elevators[i].empty == 0) {

             if (elevators[i].currDirUp == 1 && dir > 0 && floor > elevators[i].curr_floor){  //when elevator's dir is up:

                 //if the routes of different clients are covered  --> clients get in the same elevator

                 for (int j = 0; j < 5; j++) {
                     if (elevators[i].people[j].activePlace == 0 && elevators[i].people[j].isWaiting == 0) {

                         //the closest floor to current floor is objective floor

                         elevators[i].people[j].isWaiting = 1;
                         elevators[i].people[j].objectiveFloor = floor + dir;
                         elevators[i].people[j].floor = floor;
                         //elevators[i].objective_floor = getTheClosestObjectiveFloor(elevators[i]);

                         tempElevator = elevators[i];
                         clientGotInWithOther = 1;
                         break;
                     }

                 }
                 if(clientGotInWithOther == 1){
                     break;
                 }
             }
             else if(elevators[i].currDirUp == 0 && dir < 0 && floor < elevators[i].curr_floor){//when elevator's dir is down:

             }
         }
     }
    if(clientGotInWithOther == 0) {
        //if client did not get in with other clients
        //new elevator has to be used

        tempElevator.ID = getFirstFreeElevator(elevators) ;

        if(dir > 0){
            tempElevator.currDirUp = 1;
        }
        else if(dir < 0){
            tempElevator.currDirUp = 0;
        }


        tempElevator.objective_floor = floor;
        tempElevator.curr_floor = elevators[tempElevator.ID - 1].curr_floor;
        tempElevator.empty = 0;


        for(int i = 0; i< 5; i++){
            if(i ==0){
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
    }
    tempElevator.objective_floor = getFirstObjecyiveFloor(tempElevator);

    //(*currAm)++;
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

void step(Elevator elevators[], int *currAm){
    int i = 0;

    //executing one step of simulation
    for(i = 0 ; i < MAX_AMOUNT_OF_ELEVATORS; i++) {
        if (elevators[i].empty == 0) {

            if (elevators[i].curr_floor == elevators[i].objective_floor) {


                for (int j = 0; j < 5; j++) {
                    if (elevators[i].people[j].floor == elevators[i].curr_floor && elevators[i].people[j].activePlace == 0 && elevators[i].people[j].isWaiting == 1) {
                        //getting on the elevator
                        //person went into the elevator
                        elevators[i].people[j].activePlace = 1;
                        elevators[i].people[j].isWaiting = 0;

                        //assignment objective floor of the elevator after a person went into the elevator
                        elevators[i].objective_floor = getFirstObjecyiveFloor(elevators[i]);
                        break;
                    }

                    //getting off the elevator
                    else if (elevators[i].people[j].objectiveFloor == elevators[i].curr_floor &&  elevators[i].people[j].activePlace == 1 && elevators[i].people[j].isWaiting == 0) {




                        elevators[i].people[j].activePlace = 0;
                        elevators[i].people[j].isWaiting = 0;

                        //assignment objective floor of the elevator after a person got off the elevator
                        elevators[i].objective_floor = getFirstObjecyiveFloor(elevators[i]);

                        if(checkIfElevatorEmpty(elevators[i]) == 1){
                            elevators[i].empty = 1;
                        }

                    }


                }

            } else if (elevators[i].curr_floor > elevators[i].objective_floor) {
                //move of elevator
                elevators[i].curr_floor--;
            } else if (elevators[i].curr_floor < elevators[i].objective_floor) {
                //move of elevator
                elevators[i].curr_floor++;
            }
        }
    }
}

Elevator* status(){
    //TODO how to return status
}

void init(Elevator *elevators){
    for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS-1; i++){

        elevators[i].curr_floor = 0;
        elevators[i].empty = 1;
        elevators[i].ID = i+1;

        for(int j=0; j<5;j++){
            elevators[i].people[j].activePlace = 0;
            elevators[i].people[j].isWaiting = 0;
        }
    }
}


int main() {
    Elevator elevators[MAX_AMOUNT_OF_ELEVATORS];

    init(&elevators);

    int i = 3, j =0;
    int *currAm = &j;
    Elevator e = pickUp(5,4,elevators,currAm);
    update(e,&elevators);

    Elevator e1 = pickUp(3,1,elevators,currAm);
    update(e1,&elevators);

    Elevator e3 = pickUp(8,2,elevators,currAm);
    update(e3,&elevators);
/*
    Elevator e3 = pickUp(8,3,elevators,currAm);
    update(e3,&elevators);*/
    while(1){

        step(elevators, currAm);

        //to show message
        //Elevator* elevators = status();
        i++;
        if (i == 14){
            Elevator e2 = pickUp(6,2,elevators,currAm);
            update(e2,&elevators);
        }
        //currAmountOfElevators++;
    }

    return 0;
}

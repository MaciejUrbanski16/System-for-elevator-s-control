#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_AMOUNT_OF_ELEVATORS  16

const uint32_t max_floor = 10;

int currAmountOfElevators = 0;

//data which represent person who wants to use elevator potentially
typedef struct Person{
    uint8_t isWaiting;
    uint8_t activePlace;
    uint32_t floor;
    uint32_t objectiveFloor;
}Person;

//data which represent particular elevator
typedef struct Elevator{
    uint32_t ID;
    uint32_t curr_floor;
    uint32_t objective_floor;
    int8_t empty;
    Person people[5];
    uint8_t actualAmountOfPeople;
}Elevator;



//table with elevators


Elevator pickUp(int floor, int dir, Elevator *elevators, int *currAm){
 /*
    for(int i = 0 ; i < *currAm; i++) {

        if (elevators[i].actualAmountOfPeople <= 5) {

            //check if elevator which may have the same route, can take the person
            if ((elevators[i].objective_floor > elevators[i].curr_floor && floor > elevators[i].curr_floor &&
                 floor < elevators[i].objective_floor) ||
                (elevators[i].objective_floor < elevators[i].curr_floor && floor < elevators[i].curr_floor &&
                 floor > elevators[i].objective_floor)) {

                Person p;
                p.floor = floor;
                p.objectiveFloor = floor + dir;
                p.isWaiting = 1;
                elevators[i].actualAmountOfPeople++;
                elevators[i].people[elevators[i].actualAmountOfPeople] = p;

                return elevators[i];
            }
        }
    }*/

 //TODO making signing clients who are waiting
 Elevator tempElevator;
 uint8_t clientGotInWithOther = 0;

     for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS; i++) {

         if (elevators[i].empty == 0) {
             if ((elevators[i].objective_floor > elevators[i].curr_floor && floor > elevators[i].curr_floor &&
                  floor < elevators[i].objective_floor) ||
                 (elevators[i].objective_floor < elevators[i].curr_floor && floor < elevators[i].curr_floor &&
                  floor > elevators[i].objective_floor)) {

                 //if the routes of different clients are covered  --> clients get in the same elevator

                 for (int j = 0; j < 5; j++) {
                     if (elevators[i].people[j].activePlace == 0) {
                         elevators[i].people[j].isWaiting = 1;
                         elevators[i].people[j].objectiveFloor = floor + dir;
                         elevators[i].objective_floor = floor;
                         tempElevator = elevators[i];
                         clientGotInWithOther = 1;
                         break;
                     }

                 }
             }
         }
     }
    if(clientGotInWithOther == 0) {

        //if client did not get in with other clients

        //new elevator has to be used
        tempElevator.objective_floor = floor;
        tempElevator.curr_floor = 0;
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



  /*  Person p1;
    p1.isWaiting = 1;
    p1.floor = floor;
    p1.objectiveFloor = floor + dir;
    p1.activePlace = 0;

    Elevator e;
    e.ID = *currAm;
    e.objective_floor = floor;
    e.curr_floor = 0;
    e.empty = 1;
    e.actualAmountOfPeople = 0;

    //person who picked up elevator and is waiting for it
    e.people[e.actualAmountOfPeople] = p1;*/

    int i = 0;

    //TODO przywaołanie przez pojedynczego klienta, co jesli chcemy obsłuzyc jedna winda wiecej klientów?
    //TODO rozwazyc przywołania innych klientów którzy są po drodze i moze i ich mozna obsłuzyc (program wydajniejszy)
   /* if(floor + dir < max_floor && floor + dir >= 0) {
        for (i = 0; i < *currAm; i++) {
            if (elevators[i].curr_floor == elevators[i].objective_floor) {

                //bład
                elevators[i].objective_floor = floor;
                //return elevators[i];
            }
        }
    }*/
    (*currAm)++;
    return tempElevator;
}

void update(Elevator e, Elevator *elevators){
    //elevators[e.ID] = e;
    for(int i=0; i<MAX_AMOUNT_OF_ELEVATORS; i++){
        if(elevators[i].empty == 1){
            elevators[i] = e;
            break;
        }
    }
}

int checkIfElevatorEmpty(Elevator e){
    int empty = 1;
    for(int i = 0 ; i< 5; i++){
        if(e.people[i].activePlace == 1){
            empty = 0;
            break;
        }
    }
    return empty;
}

void step(Elevator elevators[], int *currAm){
    int i = 0;

    //executing one step of simulation
    for(i = 0 ; i < MAX_AMOUNT_OF_ELEVATORS; i++) {
        if (elevators[i].empty == 0) {

            if (elevators[i].curr_floor == elevators[i].objective_floor) {


                for (int j = 0; j < 5; j++) {

                    //getting off the elevator
                    if (elevators[i].people[j].activePlace == 1) {
                        elevators[i].people[j].activePlace = 0;
                        elevators[i].people[j].isWaiting = 0;

                        if(checkIfElevatorEmpty(elevators[i]) == 1){
                            elevators[i].empty = 1;
                        }

                    }
                    if (elevators[i].people[j].activePlace == 0 && elevators[i].people[j].isWaiting == 1) {
                        //getting on the elevator
                        //person went into elevator
                        elevators[i].people[j].activePlace = 1;
                        elevators[i].people[j].isWaiting = 0;

                        //assignment objective floor of elevator after person went into the elevator
                        elevators[i].objective_floor = elevators[i].people[j].objectiveFloor;
                        break;
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
    Elevator e = pickUp(4,-2,elevators,currAm);
    update(e,&elevators);

    Elevator e1 = pickUp(6,2,elevators,currAm);
    update(e1,&elevators);
    while(1){

        step(elevators, currAm);

        //to show message
        //Elevator* elevators = status();
        i++;
        if (i ==14){
            Elevator e2 = pickUp(6,2,elevators,currAm);
            update(e2,&elevators);
        }
        //currAmountOfElevators++;
    }

    return 0;
}

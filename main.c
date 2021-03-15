#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_AMOUNT_OF_ELEVATORS  16

const uint32_t max_floor = 10;

int currAmountOfElevators = 0;

typedef struct Person{
    uint8_t isWaiting;
    uint8_t activePlace;
    uint32_t floor;
    uint32_t objectiveFloor;
}Person;

//data which represents particular elevator
typedef struct Elevator{
    uint32_t ID;
    uint32_t curr_floor;
    uint32_t objective_floor;
    uint8_t empty;
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

 for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS; i++){

 }

    Person p1;
    p1.isWaiting = 1;
    p1.floor = floor;
    p1.objectiveFloor = floor + dir;

    Elevator e;
    e.ID = *currAm;
    e.objective_floor = floor;
    e.curr_floor = 0;
    e.empty = 1;
    e.actualAmountOfPeople = 0;

    //person who picked up elevator and is waiting for it
    e.people[e.actualAmountOfPeople] = p1;

    int i = 0;

    //TODO przywaołanie przez pojedynczego klienta, co jesli chcemy obsłuzyc jedna winda wiecej klientów?
    //TODO rozwazyc przywołania innych klientów którzy są po drodze i moze i ich mozna obsłuzyc (program wydajniejszy)
    if(floor + dir < max_floor && floor + dir >= 0) {
        for (i = 0; i < *currAm; i++) {
            if (elevators[i].curr_floor == elevators[i].objective_floor) {

                //bład
                elevators[i].objective_floor = floor;
                return elevators[i];
            }
        }
    }
    (*currAm)++;
    return e;
}

void update(Elevator e, Elevator elevators[]){
    elevators[e.ID] = e;
}

void step(Elevator elevators[], int *currAm){
    int i = 0;

    //executing one step of simulation
    for(i = 0 ; i < *currAm; i++){

        if(elevators[i].curr_floor == elevators[i].objective_floor){


            for(int j = 0; j < 5; j++){

                //getting off the elevator
                if(elevators[i].people[j].activePlace == 1){
                    elevators[i].people[j].activePlace = 0;
                }

                else if(elevators[i].people[j].activePlace == 0){
                    //getting on the elevator
                    //person went into elevator
                    elevators[i].people[j].activePlace = 1;

                    //assignment objective floor of elevator after person went into the elevator
                    elevators[i].objective_floor = elevators[i].people[elevators[i].actualAmountOfPeople].objectiveFloor;
                }
            }

        }
        else if(elevators[i].curr_floor > elevators[i].objective_floor){
            //move of elevator
            elevators[i].curr_floor--;
        }
        else if(elevators[i].curr_floor < elevators[i].objective_floor){
            //move of elevator
            elevators[i].curr_floor++;
        }
    }
}

Elevator* status(){
    //TODO how to return status
}

void init(Elevator elevators[]){
    for(int i = 0; i<MAX_AMOUNT_OF_ELEVATORS-1; i++){
        elevators[i].curr_floor = 0;
        for(int j=0; j<5;j++){
            elevators[i].people[j].activePlace = 1;
        }
    }
}


int main() {
    Elevator elevators[MAX_AMOUNT_OF_ELEVATORS];

    init(elevators);

    int i = 3, j =0;
    int *currAm = &j;
    Elevator e = pickUp(4,-2,elevators,currAm);
    update(e,elevators);
    while(1){




        step(elevators, currAm);

        //to show message
        //Elevator* elevators = status();
        i++;
        //currAmountOfElevators++;
    }

    return 0;
}

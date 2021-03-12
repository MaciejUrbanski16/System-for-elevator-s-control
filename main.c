#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_AMOUNT_OF_ELEVATORS  16

int currAmountOfElevators = 0;

typedef struct Person{
    uint32_t floor;
}Person;

//data which represents particular elevator
typedef struct Elevator{
    uint32_t ID;
    uint32_t curr_floor;
    uint32_t objective_floor;
}Elevator;



//table with elevators
Elevator elevators[MAX_AMOUNT_OF_ELEVATORS];

Elevator pickUp(int floor, int dir){
    Elevator e;
    e.ID = 0;
    e.objective_floor = floor;
    e.curr_floor = 0;
    int flag = 0;
    int i = 0;
    //TODO przywaołanie przez pojedynczego klienta, co jesli chcemy obsłuzyc jedna winda wiecej klientów?
    //TODO rozwazyc przywołania innych klientów którzy są po drodze i moze i ich mozna obsłuzyc (program wydajniejszy)
    for(i = 0 ; i < currAmountOfElevators;i++){
        if(elevators[i].curr_floor == elevators[i].objective_floor){
            elevators[i].objective_floor = floor;
            return elevators[i];
        }
    }
    currAmountOfElevators++;
    return e;
}

void update(Elevator e){
    elevators[e.ID] = e;
}

void step(){
    int i = 0;
    //executing one step of simulation
    for(i = 0 ; i < MAX_AMOUNT_OF_ELEVATORS; i++){
        if(elevators[i].curr_floor > elevators[i].objective_floor){
            elevators[i].curr_floor--;
        }
        else if(elevators[i].curr_floor < elevators[i].objective_floor){
            elevators[i].curr_floor++;
        }
        //if curr_floor == objective_floor  --> the elevator is waiting for client
    }
}

Elevator* status(){
    //TODO how to return status
}


int main() {

    while(1){
        Elevator e = pickUp(10,-2);

        update(e);

        step(elevators);
        Elevator* elevators = status();
    }

    return 0;
}

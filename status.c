#include "status.h"


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

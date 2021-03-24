#include "status.h"

#include <stdio.h>
#include <stdint.h>
#include <conio.h>

int main() {

    //storage status of elevators
    Elevator elevators[MAX_AMOUNT_OF_ELEVATORS];

    init(elevators);

    while(1){
        char control;
        uint8_t exit = 0;

        showStatus(elevators);

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

#include <stdio.h>
#include <stdlib.h>

void elevatorSimulation();

int main() {
    int choice;
    
    do {
        printf("\n===== ELEVATOR SIMULATION =====\n");
        printf("1. Start Simulation\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: elevatorSimulation(); break;
            case 2: printf("Exiting...\n"); break;
            default: printf("Invalid Choice!\n");
        }
        
    } while(choice != 2);
    
    return 0;
}

void elevatorSimulation() {
    int currentFloor = 0;  
    int requestFloor, direction;

    while(1) {
        printf("\nCurrent Elevator Position: Floor %d\n", currentFloor);
        printf("Enter floor request (0 to 10) or -1 to stop: ");
        scanf("%d", &requestFloor);
        
        if(requestFloor == -1) {
            printf("Stopping Elevator...\n");
            break;
        }

        if(requestFloor < 0 || requestFloor > 10) {
            printf("Invalid floor! Try again.\n");
            continue;
        }

        if(requestFloor > currentFloor) {
            direction = 1; // Moving Up
            printf("Direction: UP\n");
        } 
        else if(requestFloor < currentFloor) {
            direction = -1; // Moving Down
            printf("Direction: DOWN\n");
        } 
        else {
            printf("Elevator already at Floor %d\n", currentFloor);
            continue;
        }

        printf("Moving elevator...\n");

        while(currentFloor != requestFloor) {
            currentFloor += direction;
            printf("Elevator at floor: %d\n", currentFloor);
        }

        printf("Ding! Elevator reached Floor %d\n", currentFloor);
    }
}

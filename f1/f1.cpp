/*
*  FILE: f1.cpp
*  PROJECT       : SENG1050 - Focused #1
*  PROGRAMMER    : Darsh Patel
*  FIRST VERSION : 17-05-2024
*  DESCRIPTION   :
*    This program uses  Dynamic memory allocation to store and
     show the Data of 10 Flights entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_STR_LEN 30

#pragma warning(disable : 4996)

typedef struct 
{
    char* destination;
    char* date;
} FlightInfo;

// Function Prototype
void fillFlightInfo(FlightInfo* flight, char* destinationStr, char* dateStr);

void printFlightInfo(FlightInfo* flights, int numFlights);


int main() 
{
    FlightInfo flights[10];   // Declare an array of FlightInfo structs
    int numFlights = 0;      // Initialize the number of flights entered to 0

    printf("Please enter ten pairs of flight information :\n");

    // Loop to get input for each flight
    for (int i = 0; i < 10; i++) 
    {
        char destinationStr[MAX_STR_LEN];
        char dateStr[MAX_STR_LEN];

        printf("Destination %d: ", i + 1);
        fgets(destinationStr, MAX_STR_LEN, stdin);
        destinationStr[strcspn(destinationStr, "\n")] = '\0';

        printf("Date %d: ", i + 1);
        fgets(dateStr, MAX_STR_LEN, stdin);
        dateStr[strcspn(dateStr, "\n")] = '\0';
        fillFlightInfo(&flights[numFlights], destinationStr, dateStr);
        numFlights++;

        if (numFlights == 10) 
        {
            break;
        }
    }
    // Print flight information
    printf("Destination \tDate\n");
    printf("--------------------------\n");
    printFlightInfo(flights, numFlights);
    printf("--------------------------\n");

    // Setting the memory allocated for the destination and date fields of each FlightInfo struct to Free.
    for (int i = 0; i < numFlights; i++) 
    {
        free(flights[i].destination);
        free(flights[i].date);
    }

    return 0;
}

/*
* 
* This function allocates memory for the destination and date strings, 
 copies the provided destination and date strings into the allocated memory, 
 and assigns them to the corresponding fields of the FlightInfo struct.
*/
void fillFlightInfo(FlightInfo* flight, char* destinationStr, char* dateStr) 
{
    // Allocating the memory for destination string
    flight->destination = (char*)malloc(strlen(destinationStr) + 1);
    if (flight->destination == NULL) 
    {
        exit(1);
    }
    // Copying the destination string
    strcpy(flight->destination, destinationStr);

    // Allocating the memory for date string
    flight->date = (char*)malloc(strlen(dateStr) + 1);
    if (flight->date == NULL) 
    {
        exit(1);
    }
    // Copying the date string
    strcpy(flight->date, dateStr);
}

/*
*This function prints the destination and date information for each flight
 in the provided array of FlightInfo structs in a formatted manner.
*/ 
void printFlightInfo(FlightInfo* flights, int numFlights) 
{
    // Iterating through each flight in the array
    for (int i = 0; i < numFlights; i++) 
    {
        // Printing destination and date for the current flight
        printf("%s \t\t%s\n", flights[i].destination, flights[i].date);
    }
}
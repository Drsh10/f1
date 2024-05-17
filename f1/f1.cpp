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


void fillFlightInfo(FlightInfo* flight, char* destinationStr, char* dateStr);

void printFlightInfo(FlightInfo* flights, int numFlights);




int main() 
{
    FlightInfo flights[10];
    int numFlights = 0;

    printf("Please enter ten pairs of flight information :\n");

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
    printf("Destination \tDate\n");
    printFlightInfo(flights, numFlights);

    // Free the memory allocated for the destination and date fields of each FlightInfo struct
    for (int i = 0; i < numFlights; i++) 
    {
        free(flights[i].destination);
        free(flights[i].date);
    }

    return 0;
}

void fillFlightInfo(FlightInfo* flight, char* destinationStr, char* dateStr) 
{
    flight->destination = (char*)malloc(strlen(destinationStr) + 1);
    if (flight->destination == NULL) 
    {
        exit(1);
    }
    strcpy(flight->destination, destinationStr);

    flight->date = (char*)malloc(strlen(dateStr) + 1);
    if (flight->date == NULL) 
    {
        exit(1);
    }
    strcpy(flight->date, dateStr);
}

void printFlightInfo(FlightInfo* flights, int numFlights) 
{
    for (int i = 0; i < numFlights; i++) 
    {
       
        printf("%s \t\t%s\n", flights[i].destination, flights[i].date);
    }
}
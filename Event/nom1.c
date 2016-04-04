#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Event.h"
#include "Collection.h"
#include "Sorting.h"

void readString(char* greet, char* destination)
{
    printf("%s", greet);
    char buffer[100];
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer)-1] = '\0';
    
    strcpy(destination, buffer);
}

int readNumber(char* greet)
{
    printf("%s", greet);
    char buffer[100];
    fgets(buffer, 100, stdin);
    return atoi(buffer);
}

bool readBool(char* greet)
{
    printf("%s", greet);
    char buffer[100];
    fgets(buffer, 100, stdin);
    return atoi(buffer);
}

int main()
{
    Collection* collection = createCollection();
    prepopulateCollection(collection);
    
    
    for(;;){
        printf("\n\n\n1 - input new event\n");
        printf("2 - prints number of places input\n");
        printf("3 - Print selected event\n");
        printf("4 - Sorting event in list\n");
        printf("5 - Find events\n");
        printf("0 - exit\n");
        int optionEnter = readNumber("\nChoose option: ");
        if(optionEnter == 1)
        {
            Event* event = (Event*)malloc(sizeof(Event));
            
            readString("\nInput city name\n", event->cityName);
            event->timestamp = readNumber("Input event time\n");
            event->participants = readNumber("Input number of participants\n");
            event->isCool=readBool("This is cool (1 or 0)?\n");
            
            addEventToCollection(event,collection);
            
        }
        else if(optionEnter==2)
        {
            int count = numberOfItemsInList(collection);
            printf("\nNumber of places input: %d\n", count);
        }
        else if(optionEnter==0)
        {
            break;
        }
        else if(optionEnter==3)
        {
            if(collection->head == NULL)
            {
                printf("data, error");
            }
            int option = readNumber("\nChoose event index: ");
            printItemAtIndexInCollection(option, collection);
        }
        else if(optionEnter==4)
        {
            printf("\n1 - Sorting by city name");
            printf("\n2 - Sorting by time stamp");
            printf("\n3 - Sorting by participants\n");
            int optionSort = readNumber("\nChoose sorting: ");
            sortCollectionByOption(collection, optionSort);
        }
        else if(optionEnter==5)
        {
            char* stringUser = (char*) malloc(sizeof(char)*100);
            readString("Google:", stringUser);
            
            printFoundEvents(collection, stringUser);
            free(stringUser);
        }
    }
    freeCollection(collection);
    return 0;
}


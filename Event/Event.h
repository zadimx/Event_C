#include <time.h>
#include <stdbool.h>

typedef struct Event {
	char cityName[100];
	time_t timestamp;
	int participants;
	bool isCool;
} Event;

char* eventDescription(Event* infoEvent)
{

	char* cityNameValue=infoEvent->cityName;

	time_t timestampConst = infoEvent->timestamp;
    char timestampValue[21];
    sprintf(timestampValue, "%ld", timestampConst);
    
	int participantsConst = infoEvent->participants;
    char participantsValue[21];
    sprintf(participantsValue, "%d", participantsConst);
		
	bool isCoolConst = infoEvent->isCool;
	char* isCoolValue = isCoolConst ? "true" : "false";

	const char* infoCityName = "\nCity name: ";
	const char* infoTimestamp = "\nEvent time: ";
	const char* infoParticipants = "\nNumber of participants: ";
	const char* infoIsCool = "\nIs event cool?: ";
	char* unite = (char*) malloc(strlen(cityNameValue) + strlen(timestampValue) + strlen(participantsValue) + strlen(isCoolValue) + strlen(infoCityName) + strlen(infoTimestamp) + strlen(infoParticipants) + strlen(infoIsCool) + 1);
	strcpy(unite, infoCityName);
	strcat(unite, cityNameValue);
	strcat(unite, infoTimestamp);
	strcat(unite, timestampValue);
	strcat(unite, infoParticipants);
	strcat(unite, participantsValue);
	strcat(unite, infoIsCool);
	strcat(unite, isCoolValue);
	return unite;

}
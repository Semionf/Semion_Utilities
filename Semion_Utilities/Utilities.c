#include <stdio.h>
#include <time.h>

#pragma warning(disable:4996)


void Log(char str[])
{
	char Log[100];
	strcpy(Log, str);
	time_t t;
	time(&t);
	struct tm* timeInfo;
	timeInfo = localtime(&t);
	sprintf(Log, "%d %d %d: %02d:%02d:%02d- %s", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, str);
	FILE* f = fopen("myProg.log", "a");
	if (!f)
	{
		printf("File Error");
		exit(1);
	}
	fputs(Log, f);
	fclose(f);
}

void LogError(char str[])
{
	char Error[100];
	sprintf(Error, "Error - %s", str);
	Log(str);
}

void LogEvent(char str[])
{
	char Event[100];
	sprintf(Event, "Event - %s", str);
	Log(Event);
}

void LogWarning(char str[])
{
	char Warning[100];
	sprintf(Warning, "Warning - %s", str);
	Log(Warning);
}
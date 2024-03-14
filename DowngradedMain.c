#include <stdio.h>
#include <string.h>

#define MAX_ROWS 203

#include "Q1_To_Q3.c"

int
getDataSet(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[])
{
	int rowsOfData = 0;
	while (scanf("%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		location[rowsOfData], &airPollution[rowsOfData], &ambientPM[rowsOfData], &ozone[rowsOfData],
		&HAP[rowsOfData], &environ[rowsOfData], &occup[rowsOfData], &unsafeWash[rowsOfData],
		&metabolic[rowsOfData], &dietary[rowsOfData], &plasma[rowsOfData], &tobacco[rowsOfData],
		&smoking[rowsOfData], &secondhandSmoke[rowsOfData], &unsafeSex[rowsOfData], &airPollution[rowsOfData])==16)
		rowsOfData++;

	return rowsOfData;
}

void
printDataSet(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData)
{
	for (int row = 0; row < rowsOfData; row++)
	{
		printf("%32s %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf",
			location[row], airPollution[row], ambientPM[row], ozone[row], HAP[row], environ[row], occup[row], 
			unsafeWash[row], metabolic[row], dietary[row], plasma[row], tobacco[row], smoking[row], secondhandSmoke[row],
			unsafeSex[row], airPollution[row]);
	}
}

int main()
{
	string location[MAX_ROWS];
	int rowsOfData;
	double baseLE[MAX_ROWS], airPollution[MAX_ROWS], ambientPM[MAX_ROWS], ozone[MAX_ROWS], HAP[MAX_ROWS],
		environ[MAX_ROWS], occup[MAX_ROWS], unsafeWash[MAX_ROWS], metabolic[MAX_ROWS], dietary[MAX_ROWS],
		plasma[MAX_ROWS], tobacco[MAX_ROWS], smoking[MAX_ROWS], secondhandSmoke[MAX_ROWS], unsafeSex[MAX_ROWS];

	rowsOfData = getDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
							environ, occup, unsafeWash, metabolic, dietary,
							plasma, tobacco, smoking, secondhandSmoke, unsafeSex);

	printDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);

	Q1_Question(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);

	return 0;
}
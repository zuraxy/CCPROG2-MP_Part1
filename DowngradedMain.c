#include <stdio.h>
#include <string.h>

#define ROWSOFDATA 203
#define COLUMNSOFDATA 16

typedef char string[50]; //32 highest string length in data provided but for buffer just set 50 as size

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
	string location[ROWSOFDATA];
	int rowsOfData;
	double baseLE[ROWSOFDATA], airPollution[ROWSOFDATA], ambientPM[ROWSOFDATA], ozone[ROWSOFDATA], HAP[ROWSOFDATA],
		environ[ROWSOFDATA], occup[ROWSOFDATA], unsafeWash[ROWSOFDATA], metabolic[ROWSOFDATA], dietary[ROWSOFDATA],
		plasma[ROWSOFDATA], tobacco[ROWSOFDATA], smoking[ROWSOFDATA], secondhandSmoke[ROWSOFDATA], unsafeSex[ROWSOFDATA];

	rowsOfData = getDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
							environ, occup, unsafeWash, metabolic, dietary,
							plasma, tobacco, smoking, secondhandSmoke, unsafeSex);

	printDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);


	return 0;
}
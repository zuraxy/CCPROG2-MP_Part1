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
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[])
{
	for (int rowsOfData = 0; rowsOfData < ROWSOFDATA; rowsOfData++)
	{
		for (int currentColumn = 0; currentColumn < COLUMNSOFDATA; currentColumn++)
		{
			switch (currentColumn)
			{
			case 0:printf("%32s", location[rowsOfData]); break;
			case 1:printf("%10lf", airPollution[rowsOfData]); break;
			case 2:printf("%10lf", ambientPM[rowsOfData]); break;
			case 3:printf("%10lf", ozone[rowsOfData]); break;
			case 4:printf("%10lf", HAP[rowsOfData]); break;
			case 5:printf("%10lf", environ[rowsOfData]); break;
			case 6:printf("%10lf", occup[rowsOfData]); break;
			case 7:printf("%10lf", unsafeWash[rowsOfData]); break;
			case 8:printf("%10lf", metabolic[rowsOfData]); break;
			case 9:printf("%10lf", dietary[rowsOfData]); break;
			case 10:printf("%10lf", plasma[rowsOfData]); break;
			case 11:printf("%10lf", tobacco[rowsOfData]); break;
			case 12:printf("%10lf", smoking[rowsOfData]); break;
			case 13:printf("%10lf", secondhandSmoke[rowsOfData]); break;
			case 14:printf("%10lf", unsafeSex[rowsOfData]); break;
			case 15:printf("%10lf", airPollution[rowsOfData]); break;
			default:
				break;
			}
		}
	}
}

int main()
{
	string location[ROWSOFDATA];
	double baseLE[ROWSOFDATA], airPollution[ROWSOFDATA], ambientPM[ROWSOFDATA], ozone[ROWSOFDATA], HAP[ROWSOFDATA],
		environ[ROWSOFDATA], occup[ROWSOFDATA], unsafeWash[ROWSOFDATA], metabolic[ROWSOFDATA], dietary[ROWSOFDATA],
		plasma[ROWSOFDATA], tobacco[ROWSOFDATA], smoking[ROWSOFDATA], secondhandSmoke[ROWSOFDATA], unsafeSex[ROWSOFDATA];

	getDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex);

	printDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex);


	return 0;
}
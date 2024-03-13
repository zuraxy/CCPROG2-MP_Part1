#include <stdio.h>
#include <string.h>

#define ROWSOFDATA 203
#define COLUMNSOFDATA 16

typedef char string[50]; //32 highest string legnth in data provided but for buffer just set 50 as size

void
getDataSet(string location[],double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
		   environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
		   plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[])
{
	for (int currentRow = 0; currentRow < ROWSOFDATA; currentRow++)
	{
		for (int currentColumn = 0; currentColumn < COLUMNSOFDATA; currentColumn++)
		{
			switch (currentColumn)
			{
			case 0:scanf("%s", location[currentRow]); break;
			case 1:scanf("%lf", &airPollution[currentRow]); break;
			case 2:scanf("%lf", &ambientPM[currentRow]); break;
			case 3:scanf("%lf", &ozone[currentRow]); break;
			case 4:scanf("%lf", &HAP[currentRow]); break;
			case 5:scanf("%lf", &environ[currentRow]); break;
			case 6:scanf("%lf", &occup[currentRow]); break;
			case 7:scanf("%lf", &unsafeWash[currentRow]); break;
			case 8:scanf("%lf", &metabolic[currentRow]); break;
			case 9:scanf("%lf", &dietary[currentRow]); break;
			case 10:scanf("%lf", &plasma[currentRow]); break;
			case 11:scanf("%lf", &tobacco[currentRow]); break;
			case 12:scanf("%lf", &smoking[currentRow]); break;
			case 13:scanf("%lf", &secondhandSmoke[currentRow]); break;
			case 14:scanf("%lf", &unsafeSex[currentRow]); break;
			case 15:scanf("%lf", &airPollution[currentRow]); break;
			default:
				break;
			}
		}
	}
}

void
printDataSet(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[])
{
	for (int currentRow = 0; currentRow < ROWSOFDATA; currentRow++)
	{
		for (int currentColumn = 0; currentColumn < COLUMNSOFDATA; currentColumn++)
		{
			switch (currentColumn)
			{
			case 0:printf("%32s", location[currentRow]); break;
			case 1:printf("%10lf", airPollution[currentRow]); break;
			case 2:printf("%10lf", ambientPM[currentRow]); break;
			case 3:printf("%10lf", ozone[currentRow]); break;
			case 4:printf("%10lf", HAP[currentRow]); break;
			case 5:printf("%10lf", environ[currentRow]); break;
			case 6:printf("%10lf", occup[currentRow]); break;
			case 7:printf("%10lf", unsafeWash[currentRow]); break;
			case 8:printf("%10lf", metabolic[currentRow]); break;
			case 9:printf("%10lf", dietary[currentRow]); break;
			case 10:printf("%10lf", plasma[currentRow]); break;
			case 11:printf("%10lf", tobacco[currentRow]); break;
			case 12:printf("%10lf", smoking[currentRow]); break;
			case 13:printf("%10lf", secondhandSmoke[currentRow]); break;
			case 14:printf("%10lf", unsafeSex[currentRow]); break;
			case 15:printf("%10lf", airPollution[currentRow]); break;
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

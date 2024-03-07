#include <stdio.h>
#include <string.h>

#define ROWSOFDATA 203
#define COLUMNSOFDATA 16

typedef char string[50]; //32 highest data but for buffer just 50 highest 

struct dataSet
	{
		string location;
		double baseLE;
		double airPollution;
		double ambientPM;
		double ozone;
		double HAP;
		double environ;
		double occup;
		double unsafeWash;
		double metabolic;
		double dietary;
		double plasma;
		double tobacco;
		double smoking;
		double secondhandSmoke;
		double unsafeSex;
	};

void
getDataSet(struct dataSet locations[])
{
	for (int currentRow = 0; currentRow < ROWSOFDATA; currentRow++)
	{
		for (int currentColumn = 0; currentColumn < COLUMNSOFDATA; currentColumn++)
		{
			switch (currentColumn)
			{
				case 1:scanf("%s", locations[currentRow].location); break;
				case 2:scanf("%lf", &locations[currentRow].baseLE); break;
				case 3:scanf("%lf", &locations[currentRow].airPollution); break;
				case 4:scanf("%lf", &locations[currentRow].ambientPM); break;
				case 5:scanf("%lf", &locations[currentRow].ozone); break;
				case 6:scanf("%lf", &locations[currentRow].HAP); break;
				case 7:scanf("%lf", &locations[currentRow].environ); break;
				case 8:scanf("%lf", &locations[currentRow].occup); break;
				case 9:scanf("%lf", &locations[currentRow].unsafeWash); break;
				case 10:scanf("%lf", &locations[currentRow].metabolic); break;
				case 11:scanf("%lf", &locations[currentRow].dietary); break;
				case 12:scanf("%lf", &locations[currentRow].plasma); break;
				case 13:scanf("%lf", &locations[currentRow].tobacco); break;
				case 14:scanf("%lf", &locations[currentRow].smoking); break;
				case 15:scanf("%lf", &locations[currentRow].secondhandSmoke); break;
				case 16:scanf("%lf", &locations[currentRow].unsafeSex); break;
				default:
					break;
			}
		}
	}
}

void
printDataSet(struct dataSet locations[])
{
	for (int currentRow = 0; currentRow < ROWSOFDATA; currentRow++)
	{
		for (int currentColumn = 0; currentColumn < COLUMNSOFDATA; currentColumn++)
		{
			switch (currentColumn)
			{
			case 1:printf("\n\t%s", locations[currentRow].location); break;
			case 2:printf("\t%lf", locations[currentRow].baseLE); break;
			case 3:printf("\t%lf", locations[currentRow].airPollution); break;
			case 4:printf("\t%lf", locations[currentRow].ambientPM); break;
			case 5:printf("\t%lf", locations[currentRow].ozone); break;
			case 6:printf("\t%lf", locations[currentRow].HAP); break;
			case 7:printf("\t%lf", locations[currentRow].environ); break;
			case 8:printf("\t%lf", locations[currentRow].occup); break;
			case 9:printf("\t%lf", locations[currentRow].unsafeWash); break;
			case 10:printf("\t%lf", locations[currentRow].metabolic); break;
			case 11:printf("\t%lf", locations[currentRow].dietary); break;
			case 12:printf("\t%lf", locations[currentRow].plasma); break;
			case 13:printf("\t%lf", locations[currentRow].tobacco); break;
			case 14:printf("\t%lf", locations[currentRow].smoking); break;
			case 15:printf("\t%lf", locations[currentRow].secondhandSmoke); break;
			case 16:printf("\t%lf\n\n", locations[currentRow].unsafeSex); break;
			default:
				break;
			}
		}

	}
}

int 
main()
{
	struct dataSet locations[203];

	getDataSet(locations);
	printDataSet(locations);

	return 0;
}

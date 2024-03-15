#include "definitions.h"

//inline 
void
Q2_Question(string location[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double plasma[], double tobacco[], double smoking[],
	double secondhandSmoke[], double unsafeSex[], int rowsOfData)
{
	int invalid = 1;
	double tempCountry[5][14]; //[country][parameter]

	printf("Please input 5 countries: ");

	//initialize
	string countries[5];
	strcpy(countries[0],"China");
	strcpy(countries[1], "Dominican_Republic");
	strcpy(countries[2], "Philippines");
	strcpy(countries[3], "Taiwan");
	strcpy(countries[4], "Japan");

	while (invalid)
	{
		if (linearSearchString(location, countries[0], rowsOfData)!=-1 && linearSearchString(location, countries[1], rowsOfData) != -1 &&
			linearSearchString(location, countries[2], rowsOfData) != -1 && linearSearchString(location, countries[3], rowsOfData) != -1 &&
			linearSearchString(location, countries[4], rowsOfData) != -1)
		{
			invalid = 0;
			
			for (int i = 0; i < 5; i++)
			{
				tempCountry[i][0] = airPollution[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][1] = ambientPM[linearSearchString(location, countries[i], rowsOfData)];;
				tempCountry[i][2] = ozone[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][3] = HAP[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][4] = environ[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][5] = occup[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][6] = unsafeWash[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][7] = metabolic[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][8] = dietary[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][9] = plasma[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][10] = tobacco[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][11] = smoking[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][12] = secondhandSmoke[linearSearchString(location, countries[i], rowsOfData)];
				tempCountry[i][13] = unsafeSex[linearSearchString(location, countries[i], rowsOfData)];
				selectionSortDouble(tempCountry[i], 14);
				
				printf("\n\n%s's top 5 risk factors in descending order: \n", countries[i]);
				for (int j = 0; j < 5; j++)
				{
					if (tempCountry[i][j] == airPollution[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. airPollution [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == ambientPM[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. ambientPM [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == ozone[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. ozone [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == HAP[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. HAP [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == environ[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. environ [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == occup[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. occup [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == unsafeWash[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. unsafeWash [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == metabolic[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. metabolic [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == dietary[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. dietary [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == plasma[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. plasma [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == tobacco[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. tobacco [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == smoking[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. smoking [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == secondhandSmoke[linearSearchString(location, countries[i], rowsOfData)])
					{
						printf("%d. secondhandSmoke [%lf] \n", j + 1, tempCountry[i][j]);
					}
					if (tempCountry[i][j] == unsafeSex[linearSearchString(location, countries[i], rowsOfData)])
					{ 
						printf("%d. unsafeSex [%lf] \n", j + 1, tempCountry[i][j]);
					}
				}
			}
		}

		else
		{
			printf("Invalid input data. Please input a new dataset.");

			//just to avoid looping if invalid, assume user enters something valid at some point in time
			strcpy(countries[0], "China");
			strcpy(countries[1], "Dominican_Republic");
			strcpy(countries[2], "Philippines");
			strcpy(countries[3], "Taiwan");
			strcpy(countries[4], "Japan");
		}
			
	}

}
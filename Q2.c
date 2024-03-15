#include "definitions.h"

//inline 
void
Q2_Question(string location[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double plasma[], double tobacco[], double smoking[],
	double secondhandSmoke[], double unsafeSex[], int rowsOfData)
{
	int invalid = 1, topAverage=3;
	double tempCountry[5][14]= {{0}}, averagePlaceHolder[14] = {0},
		avgAirPollution=0, avgAmbientPM=0, avgOzone=0, avgHAP=0, avgEnviron=0, avgOccup=0, avgUnsafeWash=0, avgMetabolic=0, avgDietary=0, avgPlasma=0, avgTobacco=0, avgSmoking=0, 
		avgSecondhandSmoke=0, avgUnsafeSex=0;

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
				avgAirPollution = averagePlaceHolder[0] += tempCountry[i][0] / 5.0; //store average to array

				tempCountry[i][1] = ambientPM[linearSearchString(location, countries[i], rowsOfData)];
				avgAmbientPM = averagePlaceHolder[1] += tempCountry[i][1];

				tempCountry[i][2] = ozone[linearSearchString(location, countries[i], rowsOfData)];
				avgOzone = averagePlaceHolder[2] += tempCountry[i][2] / 5.0; //store average to array				

				tempCountry[i][3] = HAP[linearSearchString(location, countries[i], rowsOfData)];
				avgHAP = averagePlaceHolder[3] += tempCountry[i][3] / 5.0; //store average to array	

				tempCountry[i][4] = environ[linearSearchString(location, countries[i], rowsOfData)];
				avgEnviron = averagePlaceHolder[4] += tempCountry[i][4] / 5.0; //store average to array				

				tempCountry[i][5] = occup[linearSearchString(location, countries[i], rowsOfData)];
				avgOccup = averagePlaceHolder[5] += tempCountry[i][5] / 5.0; //store average to array				

				tempCountry[i][6] = unsafeWash[linearSearchString(location, countries[i], rowsOfData)];
				avgUnsafeWash = averagePlaceHolder[6] += tempCountry[i][6] / 5.0; //store average to array				

				tempCountry[i][7] = metabolic[linearSearchString(location, countries[i], rowsOfData)];
				avgMetabolic = averagePlaceHolder[7] += tempCountry[i][7] / 5.0; //store average to array				

				tempCountry[i][8] = dietary[linearSearchString(location, countries[i], rowsOfData)];
				avgDietary = averagePlaceHolder[8] += tempCountry[i][8] / 5.0; //store average to array				

				tempCountry[i][9] = plasma[linearSearchString(location, countries[i], rowsOfData)];
				avgPlasma = averagePlaceHolder[9] += tempCountry[i][9] / 5.0; //store average to array				

				tempCountry[i][10] = tobacco[linearSearchString(location, countries[i], rowsOfData)];
				avgTobacco = averagePlaceHolder[10] += tempCountry[i][10] / 5.0; //store average to array				

				tempCountry[i][11] = smoking[linearSearchString(location, countries[i], rowsOfData)];
				avgSmoking = averagePlaceHolder[11] += tempCountry[i][11] / 5.0; //store average to array				

				tempCountry[i][12] = secondhandSmoke[linearSearchString(location, countries[i], rowsOfData)];
				avgSecondhandSmoke = averagePlaceHolder[12] += tempCountry[i][12] / 5.0; //store average to array

				tempCountry[i][13] = unsafeSex[linearSearchString(location, countries[i], rowsOfData)];
				avgUnsafeSex = averagePlaceHolder[13] += tempCountry[i][13] / 5.0; //store average to array

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
			printf("How many do you want to average?\n\n");
			

			selectionSortDouble(averagePlaceHolder, 14);
			printf("Overall: \n");
			for (int i = 0; i < topAverage; i++)
			{
				if (averagePlaceHolder[i] == avgAirPollution)
					printf("%d. air pollution\n", i+1);
				if (averagePlaceHolder[i] == avgAmbientPM)
					printf("%d. ambientPM\n", i+1);
				if (averagePlaceHolder[i] == avgOzone)
					printf("%d. ozone\n", i+1);
				if (averagePlaceHolder[i] == avgHAP)
					printf("%d. HAP\n", i+1);
				if (averagePlaceHolder[i] == avgEnviron)
					printf("%d. environ\n", i+1);
				if (averagePlaceHolder[i] == avgOccup)
					printf("%d. occup\n", i+1);
				if (averagePlaceHolder[i] == avgUnsafeWash)
					printf("%d. unsafe wash\n", i+1);
				if (averagePlaceHolder[i] == avgMetabolic)
					printf("%d. metabolic\n", i+1);
				if (averagePlaceHolder[i] == avgDietary)
					printf("%d. dietary\n", i+1);
				if (averagePlaceHolder[i] == avgPlasma)
					printf("%d. plasma\n", i+1);
				if (averagePlaceHolder[i] == avgTobacco)
					printf("%d. tobacco\n", i+1);
				if (averagePlaceHolder[i] == avgSmoking)
					printf("%d. smoking\n", i+1);
				if (averagePlaceHolder[i] == avgSecondhandSmoke)
					printf("%d. secondHandSmoke\n", i+1);
				if (averagePlaceHolder[i] == avgUnsafeSex)
					printf("%d. unsafe sex\n", i+1);
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
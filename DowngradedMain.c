#include <stdio.h>
#include "Q1.c"
#include "Q2.c"
#include "Q3.c"
#include "definitions.h"

int
getDataSet(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[])
{
	int rowsOfData = 0;
	while (scanf("%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		location[rowsOfData], &baseLE[rowsOfData], &airPollution[rowsOfData], &ambientPM[rowsOfData], &ozone[rowsOfData],
		&HAP[rowsOfData], &environ[rowsOfData], &occup[rowsOfData], &unsafeWash[rowsOfData],
		&metabolic[rowsOfData], &dietary[rowsOfData], &plasma[rowsOfData], &tobacco[rowsOfData],
		&smoking[rowsOfData], &secondhandSmoke[rowsOfData], &unsafeSex[rowsOfData]) == 16)
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
		printf("%32s %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf %10lf\n",
			location[row], airPollution[row], ambientPM[row], ozone[row], HAP[row], environ[row], occup[row],
			unsafeWash[row], metabolic[row], dietary[row], plasma[row], tobacco[row], smoking[row], secondhandSmoke[row],
			unsafeSex[row], airPollution[row]);
	}
}

void Q4_Answer(string location[], double baseLE[], int rowsOfData, string option) {
	int i, j = 0, ctr = 0;
	double sum = 0, avg;
	string newLoc[MAX_ROWS];			//locations of countries greater/less than average baseLE stored here

	for (i = 1; i < rowsOfData; i++) {	//i starts at 1 since Global is not included
		sum += baseLE[i];
	}

	avg = sum / (rowsOfData - 1);

	if (strcmp(option, "greater") == 0)
		for (i = 1; i < rowsOfData; i++)	//i starts at 1 since Global is not included
			if (baseLE[i] > avg) {
				ctr++;
				strcpy(newLoc[j], location[i]);
				j++;
			}

	if (strcmp(option, "less") == 0)
		for (i = 1; i < rowsOfData; i++)	//i starts at 1 since Global is not included
			if (baseLE[i] < avg) {
				ctr++;
				strcpy(newLoc[j], location[i]);
				j++;
			}

	printf("%d countries:\n", ctr);

	for (i = 0; i < ctr; i++) {
		printf("%s, ", newLoc[i]);
	}
	printf("\n\n");
}

void Q5_Answer(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData, double num) {
	int i, j, m;
	double temp;
	string temp2;
	int ctrMin = 0, ctrMax = 0, min = 1, max = 1; // assume that 1st country is lowest/largest (and skip global at index 0)
	string factorsMin[14];
	double factorsMinVal[14];
	string factorsMax[14];
	double factorsMaxVal[14];

	for (i = 1; i < rowsOfData; i++) {	// finding indexes of country with min baseLE and country with max baseLE
		if (baseLE[min] > baseLE[i])
			min = i;

		if (baseLE[max] < baseLE[i])
			max = i;
	}

	// counting number of factors that exceed num per country and copying names and values into new arrays

	j = 0;
	if (airPollution[min] > num) { ctrMin++; strcpy(factorsMin[j], "Air_Pollution");	factorsMinVal[j] = airPollution[min]; j++; }
	if (ambientPM[min] > num) { ctrMin++; strcpy(factorsMin[j], "Ambient_PM"); 		factorsMinVal[j] = ambientPM[min]; j++; }
	if (ozone[min] > num) { ctrMin++; strcpy(factorsMin[j], "Ozone"); 		factorsMinVal[j] = ozone[min]; j++; }
	if (HAP[min] > num) { ctrMin++; strcpy(factorsMin[j], "HAP"); 		factorsMinVal[j] = HAP[min]; j++; }
	if (environ[min] > num) { ctrMin++; strcpy(factorsMin[j], "Environ/Occup"); 	factorsMinVal[j] = environ[min]; j++; }
	if (occup[min] > num) { ctrMin++; strcpy(factorsMin[j], "Occup"); 		factorsMinVal[j] = occup[min]; j++; }
	if (unsafeWash[min] > num) { ctrMin++; strcpy(factorsMin[j], "Unsafe_WaSH"); 	factorsMinVal[j] = unsafeWash[min]; j++; }
	if (metabolic[min] > num) { ctrMin++; strcpy(factorsMin[j], "Metabolic"); 		factorsMinVal[j] = metabolic[min]; j++; }
	if (dietary[min] > num) { ctrMin++; strcpy(factorsMin[j], "Dietary"); 		factorsMinVal[j] = dietary[min]; j++; }
	if (plasma[min] > num) { ctrMin++; strcpy(factorsMin[j], "High_fasting_plasma_glucose");	factorsMinVal[j] = plasma[min]; j++; }
	if (tobacco[min] > num) { ctrMin++; strcpy(factorsMin[j], "Tobacco"); 		factorsMinVal[j] = tobacco[min]; j++; }
	if (smoking[min] > num) { ctrMin++; strcpy(factorsMin[j], "Smoking"); 		factorsMinVal[j] = smoking[min]; j++; }
	if (secondhandSmoke[min] > num) { ctrMin++; strcpy(factorsMin[j], "Secondhand_Smoke");	factorsMinVal[j] = secondhandSmoke[min]; j++; }
	if (unsafeSex[min] > num) { ctrMin++; strcpy(factorsMin[j], "Unsafe_Sex"); 		factorsMinVal[j] = unsafeSex[min]; j++; }

	j = 0;
	if (airPollution[max] > num) { ctrMax++; strcpy(factorsMax[j], "Air_Pollution"); 	factorsMaxVal[j] = airPollution[max]; j++; }
	if (ambientPM[max] > num) { ctrMax++; strcpy(factorsMax[j], "Ambient_PM"); 		factorsMaxVal[j] = ambientPM[max]; j++; }
	if (ozone[max] > num) { ctrMax++; strcpy(factorsMax[j], "Ozone"); 		factorsMaxVal[j] = ozone[max]; j++; }
	if (HAP[max] > num) { ctrMax++; strcpy(factorsMax[j], "HAP"); 		factorsMaxVal[j] = HAP[max]; j++; }
	if (environ[max] > num) { ctrMax++; strcpy(factorsMax[j], "Environ/Occup"); 	factorsMaxVal[j] = environ[max]; j++; }
	if (occup[max] > num) { ctrMax++; strcpy(factorsMax[j], "Occup"); 		factorsMaxVal[j] = occup[max]; j++; }
	if (unsafeWash[max] > num) { ctrMax++; strcpy(factorsMax[j], "Unsafe_WaSH"); 	factorsMaxVal[j] = unsafeWash[max]; j++; }
	if (metabolic[max] > num) { ctrMax++; strcpy(factorsMax[j], "Metabolic"); 		factorsMaxVal[j] = metabolic[max]; j++; }
	if (dietary[max] > num) { ctrMax++; strcpy(factorsMax[j], "Dietary"); 		factorsMaxVal[j] = dietary[max]; j++; }
	if (plasma[max] > num) { ctrMax++; strcpy(factorsMax[j], "High_fasting_plasma_glucose"); factorsMaxVal[j] = plasma[max]; j++; }
	if (tobacco[max] > num) { ctrMax++; strcpy(factorsMax[j], "Tobacco"); 		factorsMaxVal[j] = tobacco[max]; j++; }
	if (smoking[max] > num) { ctrMax++; strcpy(factorsMax[j], "Smoking"); 		factorsMaxVal[j] = smoking[max]; j++; }
	if (secondhandSmoke[max] > num) { ctrMax++; strcpy(factorsMax[j], "Secondhand_Smoke"); factorsMaxVal[j] = secondhandSmoke[max]; j++; }
	if (unsafeSex[max] > num) { ctrMax++; strcpy(factorsMax[j], "Unsafe_Sex"); 		factorsMaxVal[j] = unsafeSex[max]; j++; }

	//selection sort
	for (i = 0; i < ctrMin - 1; i++) {
		m = i;

		for (j = i + 1; j < ctrMin; j++)
			if (factorsMinVal[m] > factorsMinVal[j]) {
				m = j;
			}

		if (i != m) {
			temp = factorsMinVal[i];
			factorsMinVal[i] = factorsMinVal[m];
			factorsMinVal[m] = temp;

			strcpy(temp2, factorsMin[i]);
			strcpy(factorsMin[i], factorsMin[m]);
			strcpy(factorsMin[i], temp2);
		}
	}

	for (i = 0; i < ctrMax - 1; i++) {
		m = i;

		for (j = i + 1; j < ctrMax; j++)
			if (factorsMaxVal[m] > factorsMaxVal[j]) {
				m = j;
			}

		if (i != m) {
			temp = factorsMaxVal[i];
			factorsMaxVal[i] = factorsMaxVal[m];
			factorsMaxVal[m] = temp;

			strcpy(temp2, factorsMax[i]);
			strcpy(factorsMax[i], factorsMax[m]);
			strcpy(factorsMax[i], temp2);
		}
	}

	printf("Country with minimum LE: %s\n", location[min]);
	printf("%d factors\n", ctrMin);
	for (i = 0; i < ctrMin; i++) {
		printf("%s\n", factorsMin[i]);
	}
	printf("\n\n");

	printf("Country with maximum LE: %s\n", location[max]);
	printf("%d factors\n", ctrMax);
	for (i = 0; i < ctrMax; i++) {
		printf("%s\n", factorsMax[i]);
	}
}

void Q4_Question(string location[], double baseLE[], int rowsOfData) {
	printf("The question you wanted to ask is:\n"
		"Are there locations that have values <greater/less> than the average value of life expectancy (not including global)? "
		"If yes, how many? (print array of strings)\n"
		"Please input 'greater' or 'less': \n");

	//since we cannot have inputs from the keyboard due to input redirection - the file is the one being read[], we initialize values instead.
	string option;
	strcpy(option, "greater"); //copy to option

	Q4_Answer(location, baseLE, rowsOfData, option);
}

void Q5_Question(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData) {
	printf("The question you wanted to ask is:\n"
		"Indicate and compare the countries with minimum and maximum LE. "
		"For each of the two countries, how many factors affecting LE exceed the value of <number>, "
		"and what are those identified factors, arranged in ascending order for each? (print array of strings)\n");

	//since we cannot have inputs from the keyboard due to input redirection - the file is the one being read[], we initialize values instead.

	double num = 1.0;

	Q5_Answer(location, baseLE, airPollution, ambientPM, ozone, HAP, environ, occup,
		unsafeWash, metabolic, dietary, plasma, tobacco, smoking, secondhandSmoke,
		unsafeSex, rowsOfData, num);
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

	/*printDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);*/

	Q1_Question(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);

	Q2_Question(location, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);

	Q3_Question(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary,
		plasma, tobacco, smoking, secondhandSmoke, unsafeSex, rowsOfData);

	Q4_Question(location, baseLE, rowsOfData);
	Q5_Question(location, baseLE, airPollution, ambientPM, ozone, HAP, environ, occup,
		unsafeWash, metabolic, dietary, plasma, tobacco, smoking, secondhandSmoke,
		unsafeSex, rowsOfData);

	return 0;
}
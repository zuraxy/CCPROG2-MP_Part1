#include "definitions.h"

void Q5_Answer(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
		environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
		plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData, double num) {
	int i, j = 0, k = 0, m;
	int ctrMin = 0, ctrMax = 0, min = 1, max = 1; // assume that 1st country is lowest/largest (and skip global at index 0)
	double factorsMinVal[14], factorsMaxVal[14];
	double temp;
	string factorsMin[14], factorsMax[14];
	string temp2;
	
	string factorsList[14] = {"Air Pollution", "Ambient PM", "Ozone", "HAP", "Environ/Occup", "Occup", "Unsafe WaSH", "Metabolic",
								"Dietary", "High fasting plasma glucose", "Tobacco", "Smoking", "Secondhand Smoke", "Unsafe Sex"};
	
	// finding indexes of country with min baseLE and country with max baseLE
	for(i = 1; i < rowsOfData; i++) {
		if(baseLE[min] > baseLE[i])
			min = i;
		
		if(baseLE[max] < baseLE[i])
			max = i;
	}
	
	double tempFactorsMinVal[14] = {airPollution[min], ambientPM[min], ozone[min], HAP[min], environ[min], occup[min],
								unsafeWash[min], metabolic[min], dietary[min], plasma[min], tobacco[min],
								smoking[min], secondhandSmoke[min], unsafeSex[min]};
	double tempFactorsMaxVal[14] = {airPollution[max], ambientPM[max], ozone[max], HAP[max], environ[max], occup[max],
								unsafeWash[max], metabolic[max], dietary[max], plasma[max], tobacco[max],
								smoking[max], secondhandSmoke[max], unsafeSex[max]};
	
	// counting number of factors that exceed num per country
	// and copying names and values into new arrays
	for(i = 0; i < 14; i++) {
		if(tempFactorsMinVal[i] > num) {
			factorsMinVal[j] = tempFactorsMinVal[i];
			strcpy(factorsMin[j], factorsList[i]);
			ctrMin++;
			j++;
		}
		
		if(tempFactorsMaxVal[i] > num) {
			factorsMaxVal[k] = tempFactorsMaxVal[i];
			strcpy(factorsMax[k], factorsList[i]);
			ctrMax++;
			k++;
		}
	}
	
	//selection sort for factors of country with min LE
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
			strcpy(factorsMin[m], temp2);
		}
	}
	
	//selection sort for factors of country with max LE
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
			strcpy(factorsMax[m], temp2);
		}
	}
		
	printf("Country with minimum LE: %s\n", location[min]);
	printf("%d factors\n", ctrMin);
	
	for(i = 0; i < ctrMin; i++) {
		printf("%s\n", factorsMin[i]);
	}
	printf("\n");
	
	printf("Country with maximum LE: %s\n", location[max]);
	printf("%d factors\n", ctrMax);
	for(i = 0; i < ctrMax; i++) {
		printf("%s\n", factorsMax[i]);
	}
}

void Q5_Question(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
		environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
		plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData) {
	int i;
	
	printf("The question you wanted to ask is:\n"
			"Indicate and compare the countries with minimum and maximum LE. "
			"For each of the two countries, how many factors affecting LE exceed the value of <number>, "
			"and what are those identified factors, arranged in ascending order for each? (print array of strings)");
			
	//since we cannot have inputs from the keyboard due to input redirection - the file is the one being read[], we initialize values instead.
	
	double num[3] = {1.0, 2.0, 5.0};
	
	for(i = 0; i < 3; i++) {
		printf("\n\nTest case %d: When input is %lf\n", (i + 1), num[i]);
		Q5_Answer(location, baseLE, airPollution, ambientPM, ozone, HAP, environ, occup, 
				unsafeWash, metabolic, dietary, plasma, tobacco, smoking, secondhandSmoke,
				unsafeSex, rowsOfData, num[i]);
	}
}

#include "definitions.h"

//inline
int
Q1_Answer(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double plasma[], double tobacco[], double smoking[],
	double secondhandSmoke[], double unsafeSex[], int rowsOfData, double number, int parameter, string option)
{
	int count = 0;

	printf("Territories that qualified are: ");

	for (int i = 0; i < rowsOfData; i++)
		if (strcmp(option, "greater") == 0)
		{
			switch (parameter)
			{
			case 1: if (airPollution[i] > number) { printf("%s", location[i]); count++; } break;
			case 2: if (ambientPM[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 3: if (ozone[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 4: if (HAP[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 5: if (environ[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 6: if (occup[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 7: if (unsafeWash[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 8: if (metabolic[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 9: if (dietary[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 10: if (plasma[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 11: if (tobacco[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 12: if (smoking[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 13: if (secondhandSmoke[i] > number) { printf("%s\n", location[i]); count++; } break;
			case 14: if (unsafeSex[i] > number) { printf("%s\n", location[i]); count++; } break;
			}
		}
		else if (strcmp(option, "less") == 0)
		{
			switch (parameter)
			{
			case 1: if (airPollution[i] < number) { printf("%s", location[i]); count++; } break;
			case 2: if (ambientPM[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 3: if (ozone[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 4: if (HAP[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 5: if (environ[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 6: if (occup[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 7: if (unsafeWash[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 8: if (metabolic[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 9: if (dietary[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 10: if (plasma[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 11: if (tobacco[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 12: if (smoking[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 13: if (secondhandSmoke[i] < number) { printf("%s\n", location[i]); count++; } break;
			case 14: if (unsafeSex[i] < number) { printf("%s\n", location[i]); count++; } break;
			}
		}
	if (count == 0)
		printf("None. There are no territories that meet the provided input\n");
	return count;
}

//inline
void
Q1_Question(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData)
{
	printf("The question you wanted to ask is: How many territories have values (greater/less) than (number) in (param_risk_factor)?"
		"What are the names of these territories?\n"
		"Please input 'greater' or 'lesser': ");

	//since we cannot have inputs from the keyboard due to input redirection - the file is the one being read[], we initialize values instead.
	string option;
	strcpy(option, "greater"); //copy to option

	printf("Please input a number to compare with: ");
	double number = 1000.1234;

	printf("Please enter the number corresponding to your selected parameter risk factor:\n"
		"list of parameters:\n 1 - pollution\n 2 - ambient\n 3 - ozone\n 4 - HAP\n 5 - environ\n 6 - occup\n 7 - unsafeWash\n 8 - metabolic\n 9 - dietary\n 10 - plasma\n 11 - tobacco\n 12 - smoking\n 13 - secondhandSmoke\n 14 - unsafeSex\n\n");
	int parameter = 3;

	Q1_Answer(location, baseLE, airPollution, ambientPM, ozone, HAP,
		environ, occup, unsafeWash, metabolic, dietary, plasma, tobacco, smoking,
		secondhandSmoke, unsafeSex, rowsOfData, number, parameter, option);
}


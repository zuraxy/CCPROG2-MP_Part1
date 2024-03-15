#include "definitions.h"

void Q4_Answer(string location[], double baseLE[], int rowsOfData, string option) {
	int i, j = 0, ctr = 0;
	double sum = 0, avg;
	string newLoc[rowsOfData];			//locations of countries greater/less than average baseLE stored here
	
	for(i = 1; i < rowsOfData; i++) {	//i starts at 1 since Global is not included
		sum += baseLE[i];
	}

	avg = sum / (rowsOfData - 1);
	
	if(strcmp(option, "greater") == 0)
		for(i = 1; i < rowsOfData; i++)	//i starts at 1 since Global is not included
			if(baseLE[i] > avg) {
				ctr++;
				strcpy(newLoc[j], location[i]);
				j++;
			}
	
	if(strcmp(option, "less") == 0)
		for(i = 1; i < rowsOfData; i++)	//i starts at 1 since Global is not included
			if(baseLE[i] < avg) {
				ctr++;
				strcpy(newLoc[j], location[i]);
				j++;
			}
			
	if(strcmp(option, "greater") != 0 && strcmp(option, "less") != 0)
		printf("Please input either 'greater' or 'less'. ");
	
	if(strcmp(option, "greater") == 0 || strcmp(option, "less") == 0)
		printf("%d countries:\n", ctr);
	
	for(i = 0; i < ctr; i++)
		printf("%s, ", newLoc[i]);

	printf("\n\n");
}

void Q4_Question(string location[], double baseLE[], int rowsOfData) {
	int i;
	
	printf("The question you wanted to ask is:\n"
			"Are there locations that have values <greater/less> than the average value of life expectancy (not including global)? "
			"If yes, how many? (print array of strings)\n"
			"Please input 'greater' or 'less': \n\n");
	
	//since we cannot have inputs from the keyboard due to input redirection - the file is the one being read[], we initialize values instead.
	string option[3] = {"greater", "less", "something"};
	
	for(i = 0; i < 3; i++) {
		printf("Test case %d: When input is '%s'\n", (i + 1), option[i]);
		Q4_Answer(location, baseLE, rowsOfData, option[i]);
	}
}

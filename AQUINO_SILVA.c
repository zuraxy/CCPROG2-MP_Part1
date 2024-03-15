/*
	CCPROG2 MP1 SOURCE CODE

    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1: AQUINO, Bon Windel E.                              SECTION1: S11A
    LASTNAME2, FIRSTNAME2: SILVA, Paulo Grane Gabriel C.                      SECTION2: S12A
    
    DATE SUBMITTED     : March 15, 2024
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	Run the resulting a.exe file in the command line with input and output (I/O) redirection.
	   Example: a < SoGA_DATASET.TXT > OUTPUT_LASTNAME1_LASTNAME2.TXT

*/

#include <stdio.h>
#include <string.h>
#define MAX_ROWS 203
/* Do NOT include other header files. */ 

/* 
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
	1. You must apply arrays and strings in MP Part 1 (MP1).
    2. Document your codes with SENSIBLE comments.
    3. Use double data type (not float) for all floating point 
       values/variables/functions/return type
    4. Do NOT use any global variables.
    5. Do NOT call printf() except inside the main() function.
    6. Do NOT use the following yet this MP.
        a. struct data type
	    b. file processing functions such as fopen(), fclose(), etc.
	7. Do NOT use library functions that were NOT discussed in our class.
 */


/*
    You may declare any typedef that you need below this comment.
*/

typedef char string[50]; //32 highest string length in data provided but for buffer just set 50 as size

/*
    Define any function that you need below this comment.  

    The following should be included as comments and appear BEFORE EACH function definition:
       a. Purpose: describe succintly what the function is supposed to accomplish.
       b. Parameters: describe succintly the nature/purpose of each parameter.
       c. Return type: if the function is not void, describe succintly what it will return as a result.          

    For functions that serve as answers to the questions, include the following as comments
    BEFORE the function definition itself:
       a. Question number, and the actual question.
       b. Thereafter, type the answer number, and the corresponding expected answer.
    
    For example: 
      Q1:  Which country has the lowest baseline life expectancy?
      A1:  Lesotho

    Document the body of the function by including comments alongside codes that you think
    may not be easy to understand to the person reading the codes. 
*/

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function retrieves the dataset fed/provided to it by using the scan function to get values.
	b. Parameters: The parameters serve as the dataset's parameter risk factors (while also including the location and the Base Life Expectancy)
	c. Return type: This function returns an integer value which indicates how many rows of values were retrieved and scanned  
*/

/*	<<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: 	This function switches the values of 2 array elements with data type double
	b. Parameters: 	A[] is where the values will be stored
					i is the index of 1st value to be switched
					j is the index of 2nd value to be switched
	c. Result:		The values of the 2 array elements will be switched.
*/

void doubleSwitch(double A[], int i, int j) {
	double temp;
	
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int
getDataSet(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
	plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[])
{
	int rowsOfData = 0;
	int i;

	while (scanf("%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
		location[rowsOfData], &baseLE[rowsOfData], &airPollution[rowsOfData], &ambientPM[rowsOfData], &ozone[rowsOfData],
		&HAP[rowsOfData], &environ[rowsOfData], &occup[rowsOfData], &unsafeWash[rowsOfData],
		&metabolic[rowsOfData], &dietary[rowsOfData], &plasma[rowsOfData], &tobacco[rowsOfData],
		&smoking[rowsOfData], &secondhandSmoke[rowsOfData], &unsafeSex[rowsOfData]) == 16) //scans data as long as it is able to scan 16 proper values.
		rowsOfData++; //indicate how many rows the data has

	//handle global being included but not in index 0
	if(strcmp(location[0], "Global") != 0) {
		for(i = 0; i < rowsOfData; i++) {
			if(strcmp(location[i], "Global") == 0) {	
				strcpy(location[i], location[0]);
				
				doubleSwitch(baseLE, i, 0);
				doubleSwitch(airPollution, i, 0);
				doubleSwitch(ambientPM, i, 0);
				doubleSwitch(ozone, i, 0);
				doubleSwitch(HAP, i, 0);
				doubleSwitch(environ, i, 0);
				doubleSwitch(occup, i, 0);
				doubleSwitch(unsafeWash, i, 0);
				doubleSwitch(metabolic, i, 0);
				doubleSwitch(dietary, i, 0);
				doubleSwitch(plasma, i, 0);
				doubleSwitch(tobacco, i, 0);
				doubleSwitch(smoking, i, 0);
				doubleSwitch(secondhandSmoke, i, 0);
				doubleSwitch(unsafeSex, i, 0);

				strcpy(location[0], "Global");
			}
		}
	}

	//handle global not being included
	if(strcmp(location[0], "Global") != 0) {
		for(i = rowsOfData; i >= 0; i--) {
			strcpy(location[i], location[i - 1]);
			baseLE[i] = baseLE[i - 1];
			airPollution[i] = airPollution[i - 1];
			ambientPM[i] = ambientPM[i - 1];
			ozone[i] = ozone[i - 1];
			metabolic[i] = metabolic[i - 1];
			dietary[i] = dietary[i - 1];
			plasma[i] = plasma[i - 1];
			tobacco[i] = tobacco[i - 1];
			smoking[i] = smoking[i - 1];
			secondhandSmoke[i] = secondhandSmoke[i - 1];
			unsafeSex[i] = unsafeSex[i - 1];
		}
		strcpy(location[0], "Global");
		rowsOfData++;
	}

	return rowsOfData; //this return statement dictates how many rows of data there are
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function uses a linear search algorithm in attempting to find if a given string is present in the provided dataset
	b. Parameters: string arrString[] is the general dataset or the array of strings where key will be performed a linear search upon. string key is the string that the algorithm is trying to find. n is the number of values in the array dataset.
	c. Return type:
*/
int
linearSearchString(string arrString[], string key, int n)
{
	for (int i = 0; i < n; i++)
		if (strcmp(arrString[i], key) == 0)
			return i;
	return -1;
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function utilizes a selectionSort algorithm to sort an array of type double.
	b. Parameters: double arrDouble[] is the general array dataset that is trying to be sorted. int n indicates the number of elements in the provided dataset.
*/
void
selectionSortDouble(double arrDouble[], int n)
{
	double temp = 0;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (arrDouble[max] < arrDouble[j])
				max = j;

		if (max != i)
		{
			temp = arrDouble[i];
			arrDouble[i] = arrDouble[max];
			arrDouble[max] = temp;
		}
	}
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function is used to answer Question 1 by checking the users' options and thereby comparing numbers to see if the condition is met and how many countries have met the condition provided.
	b. Parameters: This function uses location - countries that qualify the condition are copied into an array found in main.
					Other parameters are the general self-explanatory param_risk_factor which are selected by the user and used as filters or conditions
					int rowsOfData contains the number of data in the given dataset
					double number is the number being compared with a country's param_risk_factor
					string qualifiedterritories[] is the array where qualifying countries will be stored
					string parameter is the selected and specified parameter_risk_factor used as filter/condition
					string option is the selected option or operator - greater than or less than

	c. Return type: this function returns an integer which indicate how many countries qualified given the conditions.
    
	a. Q1: How many countries have values <greater/less> than <number> in <param_risk_factor>? Also, what are the names of these countries? (print array of strings)
	b. A1: Thereafter, type the answer number, and the corresponding expected answer.
    
    For example: 
      Q1:  Which country has the lowest baseline life expectancy?
      A1: When <greater/less> is set to “greater”, <number> is set to 2.5, and <param_risk_factor> is set to “Air_Pollution”, the answer is as follows.
			22 countries

			Benin
			Haiti
			Myanmar
			Mali
			Guinea-Bissau
			Madagascar
			Afghanistan
			India
			Sierra_Leone
			Burkina_Faso
			Laos
			Guinea
			Pakistan
			Chad
			Bangladesh
			Vanuatu
			Somalia
			Nepal
			Niger
			North_Korea
			Papua_New_Guinea
			Solomon_Islands
*/
int
Q1(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double plasma[], double tobacco[], double smoking[],
	double secondhandSmoke[], double unsafeSex[], int rowsOfData, double number, string qualifiedterritories[], string parameter, string option)
{
	int count = 0;

	for (int i = 0; i < rowsOfData; i++)
	{
		if (strcmp(option, "greater") == 0) //handler when chosen option is greater
		{ //full of strcmps. These are used to check which parameter should be used as the condition or filter
			if(strcmp(parameter,"Air_Pollution")==0&&(airPollution[i] > number)) 
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"ambientPM")==0&&(ambientPM[i] > number)) 
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"ozone")==0&&(ozone[i] > number)) 
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"HAP")==0 && (HAP[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"environ")==0 && (environ[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"occup")==0 && (occup[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
				
			else if(strcmp(parameter,"unsafeWash")==0 && (unsafeWash[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"metabolic")==0 && (metabolic[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"dietary")==0 && (dietary[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"plasma")==0 && (plasma[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"tobacco")==0 && (tobacco[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"smoking")==0 && (smoking[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"secondhandSmoke")==0 && (secondhandSmoke[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"unsafeSex")==0 && (unsafeSex[i] > number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
		}

		else if (strcmp(option, "less") == 0) //works the exact same way as above, but this time the condition is less than instead of greater than.
		{
			if(strcmp(parameter,"Air_Pollution")==0&&(airPollution[i] < number)) 
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"ambientPM")==0&&(ambientPM[i] < number)) 
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"ozone")==0&&(ozone[i] < number)) 
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"HAP")==0 && (HAP[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"environ")==0 && (environ[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"occup")==0 && (occup[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
				
			else if(strcmp(parameter,"unsafeWash")==0 && (unsafeWash[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"metabolic")==0 && (metabolic[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"dietary")==0 && (dietary[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"plasma")==0 && (plasma[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"tobacco")==0 && (tobacco[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"smoking")==0 && (smoking[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}

			else if(strcmp(parameter,"secondhandSmoke")==0 && (secondhandSmoke[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
			
			else if(strcmp(parameter,"unsafeSex")==0 && (unsafeSex[i] < number))
					{strcpy(qualifiedterritories[count],location[i]); count++;}
		}
	}
	return count; //return how many qualified or fulfilled the condition
}

/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose:
	b. Parameters:
	c. Return type:
    
	a. Question number, and the actual question.
	b. Thereafter, type the answer number, and the corresponding expected answer.
    
    For example: 
      Q1:  Which country has the lowest baseline life expectancy?
      A1:  Lesotho
*/
/*void
Q2(string location[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double plasma[], double tobacco[], double smoking[],
	double secondhandSmoke[], double unsafeSex[], int rowsOfData)
{
	
}*/


/* <<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	a. Purpose: This function is used to answer Question 3 by modifying the array found in main and assigning the correct values to them.
	b. Parameters: This function uses location - countries that qualify the condition are copied into an array found in main.
					Other parameters are the general self-explanatory param_risk_factor which are selected by the user and used as filters or conditions
					int rowsOfData contains the number of data in the given dataset
					double countryStats is the array that the function is modifying and storing correct values in
	
	Q3: How do <countryA> and <countryB>’s parameter risk factors compare? [algorithm(s): binary search] 

	A3: When Countries <China> and <Philippines> are selected. Their parameter risk factors comparison is as follows
	China		Philippines
	77.5821751	71.79842343
	1.850731275	1.67568055
	1.393518094	0.691634481
	0.074187132	0.002370234
	0.340365291 0.929484446
	2.861275657	2.383616195
	0.352631825	0.224456865
	0.017427718	0.242926132
	4.716209801	6.165007733
	2.028727547	2.162167406
	0.987177162	1.885343374
	2.777920007	2.575556176
	2.437863372	2.159934841
	0.386616542	0.460447557
	0.09001617	0.164648196
*/
void Q3(string location[],string country,int rowsOfData,double countryStats[],double baseLE[],double airPollution[],double ambientPM[],double ozone[],double HAP[],double environ[],double occup[],double unsafeWash[],double metabolic[],double dietary[],double plasma[],double tobacco[],double smoking[],double secondhandSmoke[],double unsafeSex[])
{
	int index = linearSearchString(location,country,rowsOfData);
	countryStats[0] = baseLE[index];
	countryStats[1] = airPollution[index];
	countryStats[2] = ambientPM[index];
	countryStats[3] = ozone[index];
	countryStats[4] = HAP[index];
	countryStats[5] = environ[index];
	countryStats[6] = occup[index];
	countryStats[7] = unsafeWash[index];
	countryStats[8] = metabolic[index];
	countryStats[9] = dietary[index];
	countryStats[10] = plasma[index];
	countryStats[11] = tobacco[index];
	countryStats[12] = smoking[index];
	countryStats[13] = secondhandSmoke[index];
	countryStats[14] = unsafeSex[index];
}

/*	<<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	Purpose: 	The function counts the number of countries with greater/less than average baseLE
				and lists their names in an array.
	Parameters: location[] is where the name of the countries is stored
				baseLE[] is where the baseLE of the countries is stored
				rowsOfData is the rows of data
				option is either 'greater' or 'less' to determine how function will continue
				newLoc[] is where the names of the countries with greater/less than average baseLE
					will be stored
	Result:		The function returns the number of countries with greater/less than average baseLE
				and stores their names into array newLoc.
*/
int Q4_Answer(string location[], double baseLE[], int rowsOfData, string option, string newLoc[]) {
	int i, j = 0, ctr = 0;
	double sum = 0, avg;
	
	for(i = 1; i < rowsOfData; i++) {	//i starts at 1 since Global is not included
		sum += baseLE[i];
	}

	avg = sum / (rowsOfData - 1);
	
	if(strcmp(option, "greater") == 0)	//count countries with greater than average baseLE
		for(i = 1; i < rowsOfData; i++)
			if(baseLE[i] > avg) {
				ctr++;
				strcpy(newLoc[j], location[i]); //store names of those countries in array newLoc
				j++;
			}
	
	if(strcmp(option, "less") == 0)
		for(i = 1; i < rowsOfData; i++)	//count countries with less than average baseLE
			if(baseLE[i] < avg) {
				ctr++;
				strcpy(newLoc[j], location[i]); //store names of those countries in array newLoc
				j++;
			}
	
	if(strcmp(option, "greater") != 0 && strcmp(option, "less") != 0)
		ctr = -1;
		
	return ctr;
}

/*	<<<<<<<<<<FUNCTION HEADER COMMENT>>>>>>>>>>>
	Purpose: 	The function finds the countries with minimum and maximum baseLE
	Parameters: location[] is where the name of the countries is stored
				baseLE[] is where the baseLE of the countries is stored
				airPollution[], ambientPM[], ozone[], HAP[], environ[], occup[], unsafeWash[], metabolic[],
					dietary[], plasma[], tobacco[], smoking[], secondhandSmoke[], unsafeSex[] all contain
					the values of their respective risk factors per country
				rowsOfData is the rows of data
				num is the number that the listed factors exceed
				factorsMin[] will store the listed factors of the country with min baseLE
				factorsMax[] will store the listed factors of the country with max baseLE
				*ctrMin is the number of factors that exceed num of country with min baseLE
				*ctrMax is the number of factors that exceed num of country with max baseLE
				*minLECountry is the country with min baseLE
				*maxLECountry is the country with max baseLE
	Result:		The function returns the number of countries with greater/less than average baseLE
				and stores their names into array newLoc.
*/
void Q5_Answer(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
		environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double
		plasma[], double tobacco[], double smoking[], double secondhandSmoke[], double unsafeSex[], int rowsOfData, double num,
		string factorsMin[], string factorsMax[], int *ctrMin, int *ctrMax, string *minLECountry, string *maxLECountry) {
	int i, j = 0, k = 0, m;
	int min = 1, max = 1; // assume that 1st country is lowest/largest (and skip global at index 0)
	double temp;
	double factorsMinVal[14], factorsMaxVal[14];
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
	
	strcpy(*minLECountry, location[min]);
	strcpy(*maxLECountry, location[max]);
	
	double tempFactorsMinVal[14] = {airPollution[min], ambientPM[min], ozone[min], HAP[min], environ[min], occup[min],
								unsafeWash[min], metabolic[min], dietary[min], plasma[min], tobacco[min],
								smoking[min], secondhandSmoke[min], unsafeSex[min]};
	double tempFactorsMaxVal[14] = {airPollution[max], ambientPM[max], ozone[max], HAP[max], environ[max], occup[max],
								unsafeWash[max], metabolic[max], dietary[max], plasma[max], tobacco[max],
								smoking[max], secondhandSmoke[max], unsafeSex[max]};
	
	// counting number of factors that exceed num per country, and copying names and values into new arrays
	for(i = 0; i < 14; i++) {
		if(tempFactorsMinVal[i] > num) {
			factorsMinVal[j] = tempFactorsMinVal[i];
			strcpy(factorsMin[j], factorsList[i]);
			*ctrMin += 1;
			j++;
		}
		
		if(tempFactorsMaxVal[i] > num) {
			factorsMaxVal[k] = tempFactorsMaxVal[i];
			strcpy(factorsMax[k], factorsList[i]);
			*ctrMax += 1;
			k++;
		}
	}
	
	//selection sort for factors of country with min LE
	for (i = 0; i < *ctrMin - 1; i++) {
		m = i;

		for (j = i + 1; j < *ctrMin; j++)
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
	for (i = 0; i < *ctrMax - 1; i++) {
		m = i;

		for (j = i + 1; j < *ctrMax; j++)
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
}

int
main()
{
    /* Declare your own local variables. Describe the purpose of your local variables. */
	//Array storing all the string locations
	string location[MAX_ROWS];

	//Arrays storing all the risk parameters contained in the SOGA dataset 
	double baseLE[MAX_ROWS], airPollution[MAX_ROWS], ambientPM[MAX_ROWS], ozone[MAX_ROWS], HAP[MAX_ROWS],
		environ[MAX_ROWS], occup[MAX_ROWS], unsafeWash[MAX_ROWS], metabolic[MAX_ROWS], dietary[MAX_ROWS],
		plasma[MAX_ROWS], tobacco[MAX_ROWS], smoking[MAX_ROWS], secondhandSmoke[MAX_ROWS], unsafeSex[MAX_ROWS];

	//Via input redirection, get how many rows are being scanned and store the integer in a variable.
	int rowsOfData = getDataSet(location, baseLE, airPollution, ambientPM, ozone, HAP, environ, occup, unsafeWash, metabolic, dietary, plasma, tobacco, smoking, secondhandSmoke, unsafeSex);

	/***********************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 ****************************************************************************|O-N-E|************************************************************************/

	//Initial question being asked
    printf("Set Parameters for Q1: How many territories have values <greater/less> than <number> in <param_risk_factor>? Also, what are the names of these territories?\n");
	string option, param_risk_factor, qualifiedterritories[MAX_ROWS];
	double number;

	//Set values for parameters required to answer the question.
	strcpy(option, "greater");
	strcpy(param_risk_factor, "Air_Pollution");	
	number = 2.5;

	//Invalid input handlers
	if(strcmp(option, "greater")!=0&&strcmp(option, "less")!=0)
		printf("Invalid. Please input either greater than or less than.");
	if(strcmp(param_risk_factor, "Air_Pollution")!=0&&strcmp(param_risk_factor, "ambientPM")!=0&&strcmp(param_risk_factor, "ozone")!=0&&strcmp(param_risk_factor, "HAP")!=0&&strcmp(param_risk_factor, "environ")!=0&&strcmp(param_risk_factor, "occup")!=0&&strcmp(param_risk_factor, "unsafeWash")!=0&&strcmp(param_risk_factor, "metabolic")!=0&&strcmp(param_risk_factor, "dietary")!=0&&strcmp(param_risk_factor, "plasma")!=0&&strcmp(param_risk_factor, "tobacco")!=0&&strcmp(param_risk_factor, "smoking")!=0&&strcmp(param_risk_factor, "secondhandSmoke")!=0&&strcmp(param_risk_factor, "unsafeSex")!=0)
		printf("Invalid. Please input one of the listed factors that affect life expectancy.");
		//can add functions that handle error and ask for input, if scanfs are allowed.

	//Display the true question being answered
	printf("> Q1: How many territories have values %s than %lf in %s? Also, what are the names of these territories?\n\n", option, number, param_risk_factor);

	//Real answer to Q1.
	printf("A1:\n%d territories\n\n",Q1(location,baseLE,airPollution,ambientPM,ozone,HAP,environ,occup,unsafeWash,metabolic,dietary,plasma,tobacco,smoking,secondhandSmoke,unsafeSex,rowsOfData,number,qualifiedterritories,param_risk_factor,option));
	for (int i = 0; i<rowsOfData&&strcmp(qualifiedterritories[i],"\0")!=0;i++)
	{
		printf("%s\n",qualifiedterritories[i]);
	}

	/************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 *****************************************************************************|T-W-O|************************************************************************/
	
	/*printf("Set Parameters for Q2: What are the top 5 factors affecting life expectancy for each of the following territories, <5_territories>, arranged in descending order of value, and what are their top <number> average leading factors?\n");
	string territories[5] ={{' '}};
	int topAverages = 0;
	double 
	double average[14]={0};

	//pre-assign inputs to arrays and variables
	strcpy(territories[0],"China"); strcpy(territories[0],"Dominican_Republic"); strcpy(territories[0],"Philippines"); strcpy(territories[0],"Taiwan"); strcpy(territories[0],"Japan"); 
	topAverages = 3;

	//handle invalid inputs
	if(linearSearchString(location, territories[0],rowsOfData)==-1 || linearSearchString(location, territories[1],rowsOfData)==-1 || linearSearchString(location, territories[2],rowsOfData)==-1 || linearSearchString(location, territories[3],rowsOfData)==-1 || linearSearchString(location, territories[4],rowsOfData)==-1)
		printf("Invalid input. Please enter valid territories");
	
	//re-print question to answer
	printf("> Q2: What are the top 5 factors affecting life expectancy for each of the following territories, %s %s %s %s %s, arranged in descending order of value, and what are their top %d average leading factors?\n",territories[0],territories[1],territories[2],territories[3],territories[4],topAverages);
	
	Q2()*/

	/*************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 ****************************************************************************|T-H-R-E-E|************************************************************************/
	printf("Set Parameters for Q3: How do <countryA> and <countryB>'s parameter risk factors compare?\n");
	string countryA = {' '}, countryB = {' '};
	double countryAStats[15] ={0}, countryBStats[15];

	//pre-assign values
	strcpy(countryA,"China"); strcpy(countryB,"Philippines");

	//handle invalid inputs
	if(linearSearchString(location, countryA,rowsOfData)==-1 || linearSearchString(location, countryB,rowsOfData)==-1)
		printf("Invalid input. Please input valid territories");

	//transfer from multiple arrays into one array for the specified country
	Q3(location,countryA,rowsOfData,countryAStats,baseLE, airPollution,ambientPM,ozone,HAP,environ,occup,unsafeWash,metabolic,dietary,plasma,tobacco,smoking,secondhandSmoke,unsafeSex);
	Q3(location,countryB,rowsOfData,countryBStats,baseLE, airPollution,ambientPM,ozone,HAP,environ,occup,unsafeWash,metabolic,dietary,plasma,tobacco,smoking,secondhandSmoke,unsafeSex);

	//values printer using array's content
	printf("\n\n%s\t\t\t%s",countryA,countryB);
	for(int i=0;i<15;i++)
	{
		printf("\n%lf\t\t%lf",countryAStats[i],countryBStats[i]);
	}

	/*************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 *****************************************************************************|F-O-U-R|************************************************************************/

    /* 
       Call the function that answers a question. Thereafter, use printf() to print the question 
       and the corresponding answer.  For example:

       expectancy = Q1_Answer(territory, param_x, param_y); // where expectancy, territory, param_x and param_y are local variables.

       printf("Q1: Which territory has the lowest baseline life expectancy?\n");
       printf("A1: %s %lf\n", territory, expectancy);       

       TEST CASES HARD REQUIREMENTS:
       You should have multiple test cases, i.e., functions calls to answer those 
       Questions that involve parameter(s).  There should be function calls with
       different actual paramete values.  For questions that require searching
       (linear or binary search), there should be a test case, i.e., a  function 
       call with a search key parameter that does not exist, i.e., NOT FOUND scenario.
    */
    int i, j;							//for loops
	int countQ4; 						//counter for Q4
	string minLECountry, maxLECountry;	//names of country with min LE and max LE respectively
	string newLocQ4[rowsOfData];		//array where the names of countries in Q4 will be stored
	
	//Question 4 Print statement
	printf("A4. The question you wanted to ask is:\n"
			"Are there locations that have values <greater/less> than the average value of life expectancy (not including global)? "
			"If yes, how many? (print array of strings)\n"
			"Please input 'greater' or 'less': \n\n");
	
	//Question 4 Test cases
	string optionQ4[3] = {"greater", "less", "something"};
	
	for(i = 0; i < 3; i++) {
		printf("Test case %d: When input is '%s'\n", (i + 1), optionQ4[i]);
		
		countQ4 = Q4_Answer(location, baseLE, rowsOfData, optionQ4[i], newLocQ4); //function call
		
		if(countQ4 == -1)
			printf("Please input either 'greater' or 'less'.");
		else {
			printf("%d countries: ", countQ4);
			for(j = 0; j < countQ4; j++)
				printf("%s, ", newLocQ4[j]);
		}
		
		printf("\n\n");
	}

	/*************************************************************************|Q-U-E-S-T-I-O-N|*************************************************************************
	 ****************************************************************************|F-I-V-E|************************************************************************/
	string newLocQ5Min[rowsOfData];	//array where the name of risk factors of country with min LE will be stored
	string newLocQ5Max[rowsOfData];	//array where the name of risk factors of country with max LE will be stored
	int ctrMin, ctrMax; 			//1 counter each for country with min LE and country with max LE
	
	//Question 5 Print statement
	printf("A5. The question you wanted to ask is:\n"
			"Indicate and compare the countries with minimum and maximum LE. "
			"For each of the two countries, how many factors affecting LE exceed the value of <number>, "
			"and what are those identified factors, arranged in ascending order for each? (print array of strings)");
			
	//Question 5 Test cases
	double optionQ5[3] = {1.0, 2.0, 5.0};
	
	for(i = 0; i < 3; i++) {
		ctrMin = 0;
		ctrMax = 0;
		
		printf("\n\nTest case %d: When input is %lf\n", (i + 1), optionQ5[i]);
		Q5_Answer(location, baseLE, airPollution, ambientPM, ozone, HAP, environ, occup, 
				unsafeWash, metabolic, dietary, plasma, tobacco, smoking, secondhandSmoke,
				unsafeSex, rowsOfData, optionQ5[i], newLocQ5Min, newLocQ5Max, &ctrMin, &ctrMax,
				&minLECountry, &maxLECountry); // function call
				
		printf("Country with minimum LE: %s\n", minLECountry);
		printf("%d factors\n", ctrMin);
		
		for(j = 0; j < ctrMin; j++) {
			printf("%s\n", newLocQ5Min[j]);
		}
		printf("\n");
		
		printf("Country with maximum LE: %s\n", maxLECountry);
		printf("%d factors\n", ctrMax);
		for(j = 0; j < ctrMax; j++) {
			printf("%s\n", newLocQ5Max[j]);
		}
	}
	return 0;
}

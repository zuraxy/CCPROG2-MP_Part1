#include "definitions.c"

inline
void
caller(string strArr[], string key, int n)
{
	printStringData(strArr, n);
	selectionSortString(strArr, n);
	printStringData(strArr, n);
	printf("index: %d",binarySearchString(strArr, key, n));
}

inline 
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
	strcpy(countries[0], "Dominican_Republic");
	strcpy(countries[0], "Philippines");
	strcpy(countries[0], "Taiwan");
	strcpy(countries[0], "Japan");

	//sort then find if these are valid
	selectionSortString(location, rowsOfData);

	while (invalid)
	{
		if (binarySearchString(location, countries[0], rowsOfData) && binarySearchString(location, countries[1], rowsOfData) &&
			binarySearchString(location, countries[2], rowsOfData) && binarySearchString(location, countries[3], rowsOfData) &&
			binarySearchString(location, countries[4], rowsOfData))
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
			}
		}

		else
			printf("Invalid input data. Please input a new dataset.");
	}

}
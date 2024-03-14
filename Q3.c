#include "definitions.c"

inline
void
Q3_Question(string location[], double baseLE[], double airPollution[], double ambientPM[], double ozone[], double HAP[], double
	environ[], double occup[], double unsafeWash[], double metabolic[], double dietary[], double plasma[], double tobacco[], double smoking[],
	double secondhandSmoke[], double unsafeSex[], int rowsOfData)
{
	int invalid = 1;
	printf("The question you wanted to ask is: How do countries <countryA> and <countryB>'s risk factors compare?\n"
		"Before we can answer this question, please enter 2 countries: ");
	
	string country1, country2;
	strcpy(country1, "China");
	strcpy(country2, "Philippines");

	while (invalid)
	{
		if (linearSearchString(location, country1, rowsOfData) && linearSearchString(location, country2, rowsOfData))
			printf("%s\t\t%s"
				"%lf\t\t%lf | baseLineLE\n"
				"%lf\t\t%lf | LE Air Pollution\n"
				"%lf\t\t%lf | Ambient PM\n"
				"%lf\t\t%lf | Ozone\n"
				"%lf\t\t%lf | HAP\n"
				"%lf\t\t%lf | environ\n"
				"%lf\t\t%lf | occup\n"
				"%lf\t\t%lf | unsafe wash\n"
				"%lf\t\t%lf | metabolic\n"
				"%lf\t\t%lf | dietary\n"
				"%lf\t\t%lf | high fasting plasma glucose\n"
				"%lf\t\t%lf | tobacco\n"
				"%lf\t\t%lf | smoking\n"
				"%lf\t\t%lf | secondhand smoke\n"
				"%lf\t\t%lf | unsafe sex\n", country1, country2, baseLE[linearSearchString(location, country1, rowsOfData)], baseLE[linearSearchString(location, country2, rowsOfData)],
				airPollution[linearSearchString(location, country1, rowsOfData)], airPollution[linearSearchString(location, country2, rowsOfData)],
				ambientPM[linearSearchString(location, country1, rowsOfData)], ambientPM[linearSearchString(location, country2, rowsOfData)],
				ozone[linearSearchString(location, country1, rowsOfData)], ozone[linearSearchString(location, country2, rowsOfData)],
				HAP[linearSearchString(location, country1, rowsOfData)], HAP[linearSearchString(location, country2, rowsOfData)],
				environ[linearSearchString(location, country1, rowsOfData)], environ[linearSearchString(location, country2, rowsOfData)],
				occup[linearSearchString(location, country1, rowsOfData)], occup[linearSearchString(location, country2, rowsOfData)],
				unsafeWash[linearSearchString(location, country1, rowsOfData)], unsafeWash[linearSearchString(location, country2, rowsOfData)],
				metabolic[linearSearchString(location, country1, rowsOfData)], metabolic[linearSearchString(location, country2, rowsOfData)],
				dietary[linearSearchString(location, country1, rowsOfData)], dietary[linearSearchString(location, country2, rowsOfData)],
				plasma[linearSearchString(location, country1, rowsOfData)], plasma[linearSearchString(location, country2, rowsOfData)],
				tobacco[linearSearchString(location, country1, rowsOfData)], tobacco[linearSearchString(location, country2, rowsOfData)],
				smoking[linearSearchString(location, country1, rowsOfData)], smoking[linearSearchString(location, country2, rowsOfData)],
				secondhandSmoke[linearSearchString(location, country1, rowsOfData)], secondhandSmoke[linearSearchString(location, country2, rowsOfData)],
				unsafeSex[linearSearchString(location, country1, rowsOfData)], unsafeSex[linearSearchString(location, country2, rowsOfData)]);
		else
			printf("Invalid inputs. Please enter a new set of data.\n");
	}
}
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"Header.h"


int main()
{
	char date[11] = { NULL };
	char option[4] = { NULL };
	int size = 0;
	int Increment = 0;
	int reps = 0;
	Lift BenchPress, Deadlift, Squat;

	printf("Enter the date MM/DD/YYYY\n");
	scanf("%s", date);

	printf("Enter your Bech press 1RM\n");
	scanf("%d", &BenchPress.One_RM);

	printf("Enter your Dealfit 1RM\n");
	scanf("%d", &Deadlift.One_RM);

	printf("Enter your Squat 1RM\n");
	scanf("%d", &Squat.One_RM);

	printf("How many cycles do you want to see? ");
	scanf("%d", &size);

	BenchPress.month = (Month*)malloc(size * sizeof(Month));
	Deadlift.month = (Month*)malloc(size * sizeof(Month));
	Squat.month = (Month*)malloc(size * sizeof(Month));


	for (int i = 0; i < size; i++)
	{
		for (int wek = 0; wek < 4; wek++)
		{
			for (int set = 0; set < 3; set++)
			{
				BenchPress.month[i].week[wek][set] = ((BenchPress.One_RM *  Percentage[wek][set]) / 100) + Increment;
				Deadlift.month[i].week[wek][set] = ((Deadlift.One_RM *  Percentage[wek][set]) / 100) + Increment;
				Squat.month[i].week[wek][set] = ((Squat.One_RM *  Percentage[wek][set]) / 100) + Increment;
			}
		}
		Increment += 10;
	}

	for (int i = 0; i < size; i++)
	{
		reps = 5;
		printf("\t\tCycle %d\n", i + 1);
		for (int wek = 0; wek < 4; wek++)
		{
			reps = 5;
			printf("\tWeek %d\n", wek + 1);
			for (int set = 0; set < 3; set++)
			{
				if (wek == 1)
				{
					reps = 3;
				}
				else if (wek == 2 && set > 0)
				{
					reps -= 2;
				}
				else if (wek > 2)
				{
					reps = 10;
				}
				printf("Bench Press : %dlbs  set %d  reps : %d\n", BenchPress.month[i].week[wek][set], set + 1, reps);
				printf("Deadlift :    %dlbs  set %d  reps : %d\n", Deadlift.month[i].week[wek][set], set + 1, reps);
				printf("Squat :       %dlbs  set %d  reps : %d\n", Squat.month[i].week[wek][set], set + 1, reps);
			}
		}
	}

	printf("Do you want to save the data in a file? ");
	for (;;)
	{
		printf("Enter yes or no\n");
		scanf("%s", option);

		for (int i = 0; i < 3; i++)
		{
			option[i] = toupper(option[i]);
		}

		if ((strncmp(option, "YES", 3) == 0) || (strncmp(option, "NO", 2) == 0))
			break;
	}

	if ((strncmp(option, "YES", 3) == 0))
	{
		FILE *fptr;
		char path[] = "C:\\Users\\joshw\\Desktop\\Wendler531.txt";
		fptr = fopen(path, "w");
		fprintf(fptr, "Date : %s \n", date);

		for (int i = 0; i < size; i++)
		{
			reps = 5;
			fprintf(fptr, "\t\tCycle %d\n", i + 1);
			for (int wek = 0; wek < 4; wek++)
			{
				reps = 5;
				fprintf(fptr, "\tWeek %d\n", wek + 1);
				for (int set = 0; set < 3; set++)
				{
					if (wek == 1)
					{
						reps = 3;
					}
					else if (wek == 2 && set > 0)
					{
						reps -= 2;
					}
					else if (wek > 2)
					{
						reps = 10;
					}
					fprintf(fptr, "Bench Press : %dlbs  set %d  reps : %d\n", BenchPress.month[i].week[wek][set], set + 1, reps);
					fprintf(fptr, "Deadlift :    %dlbs  set %d  reps : %d\n", Deadlift.month[i].week[wek][set], set + 1, reps);
					fprintf(fptr, "Squat :       %dlbs  set %d  reps : %d\n", Squat.month[i].week[wek][set], set + 1, reps);
				}
			}
		}
		fclose(fptr);
		printf("\tThe file was saved to your Desktop\n");
		getchar();
	}


	free(BenchPress.month);
	free(Deadlift.month);
	free(Squat.month);
}
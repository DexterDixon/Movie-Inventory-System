
#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>	    	  
#include <ctype.h>
#include <string.h>
#define SIZE 50

typedef struct 
{
	char Title[SIZE];
	char Genre;

	int Id;
	int ReleaseDate;
	
	double Budget;
	double Revenue;
} Movie;

void Greeting();
void InventoryMenu(char *choice);
void InitialEntries(Movie archive[]);
void PrintMovies(Movie archive[], int count);
void SaveFile(Movie archive[], int count);
void AddMovie(Movie archive[], int count);
int DisplayIds(Movie archive[], int count);
int SearchId(Movie archive[], int count, int id);
void EditMovie(Movie archive[], int count);

int main(void)
{
	Movie archive[SIZE];
	int MovieCount = 6;
	char selection = 'z';
	int Id;
	int change;

	InitialEntries(archive);//hardcodes five entries
	Greeting(); //greets the user




	
	while (selection != 'Q') // while loop for Inventory Menu selections
	{	
		InventoryMenu(&selection); //Displays the list of options available 
		selection = toupper(selection);
		if (selection == 'P' || selection == 'p')
		{
			PrintMovies(archive, MovieCount);
		}

		if (selection == 'A' || selection == 'a')
		{
			AddMovie(archive, MovieCount);
			MovieCount = MovieCount + 1;
		}

		if (selection == 'C' || selection == 'c')
		{
			MovieCount = 0;
			printf("\nMovie Archive has been cleared");
		}

		if (selection == 'S' || selection == 's')
		{
			SaveFile(archive, MovieCount);
			printf("Movie Archive has been saved");
		}

		if (selection == 'D' ||selection == 'd')
		{
			Id = DisplayIds(archive, MovieCount);
			printf("\nThis is the ID you Choose: %d\n", Id);
			
			change = SearchId(archive, MovieCount, Id);

			if (change == -1)
			{
				printf("Index not found\n");
			}
			else
			{
				archive[change] = archive[change - 1];
				MovieCount = MovieCount - 1;
			}

		}

		if (selection == 'U')
		{
			Id = DisplayIds(archive, MovieCount);
			printf("\nThis is the ID you Choose: %d\n", Id);

			change = SearchId(archive, MovieCount, Id);

			if (change == -1)
			{
				printf("Index not found\n");
			}
			else
			{
				EditMovie(archive, change);
			}
		}

	} 

	return (0);
}

void Greeting()
{
	printf("*******************************\n\n");
	printf("Welcome to the Movie Inventory\n\n");
	printf("Each movie has a unique id\n\n");
	printf("Follow the prompts on the menu:\n\n");

}

void InventoryMenu(char *choice)
{
	printf("------------------------\n\n");
	printf("(P) to Print the inventory list onto the screen");
	printf("(A) to Add new entry\n");
	printf("(C) to Clear all records\n");
	printf("(S) to Create a current report (save it to a file)\n");
	printf("(D) to Delete an item from the list (inventory)\n");
	printf("(U) to Update ONE OF THE FIELDS (not THE id)\n");
	printf("(Q) to Quit\n");
	printf("Select and option: ");
	scanf(" %c", &*choice);
	printf("The selection you choose was %c\n", *choice);
}

void InitialEntries(Movie archive[])
{
	strcpy(archive[0].Title, "Inception");
	archive[0].Genre = 'T';
	archive[0].Id = 1;
	archive[0].ReleaseDate = 2008;
	archive[0].Budget = 6.6;
	archive[0].Revenue = 11.6;

	strcpy(archive[1].Title, "Shrek");
	archive[1].Genre = 'C';
	archive[1].Id = 2;
	archive[1].ReleaseDate = 2004;
	archive[1].Budget = 2.3;
	archive[1].Revenue = 15.7;

	strcpy(archive[2].Title, "Avengers");
	archive[2].Genre = 'A';
	archive[2].Id = 3;
	archive[2].ReleaseDate = 2012;
	archive[2].Budget = 10.2;
	archive[2].Revenue = 22.5;

	strcpy(archive[3].Title, "Batman");
	archive[3].Genre = 'A';
	archive[3].Id = 4;
	archive[3].ReleaseDate = 2010;
	archive[3].Budget = 10.4;
	archive[3].Revenue = 20.1;

	strcpy(archive[4].Title, "Transformers");
	archive[4].Genre = 'A';
	archive[4].Id = 5;
	archive[4].ReleaseDate = 2011;
	archive[4].Budget = 11.2;
	archive[4].Revenue = 10.1;

	strcpy(archive[5].Title, "StarWars");
	archive[5].Genre = 'A';
	archive[5].Id = 6;
	archive[5].ReleaseDate = 1990;
	archive[5].Budget = 3.5;
	archive[5].Revenue = 15.6;
}

void PrintMovies(Movie archive[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("\nTitle: %s\n", archive[i].Title);
		printf("Genre: %c\n", archive[i].Genre);
		printf("Id: %d\n", archive[i].Id);
		printf("Release Date: %d\n", archive[i].ReleaseDate);
		printf("Budget: %f\n", archive[i].Budget);
		printf("Revenue: %f\n", archive[i].Revenue);
	}

}

void SaveFile(Movie archive[], int count)
{
	FILE *out;
	out = fopen("MovieList.txt", "w");

	for (int i = 0; i < count; i++)
	{
		fprintf(out ,"Title: %s", archive[i].Title);
		fprintf(out, "Genre: %c", archive[i].Genre);
		fprintf(out, "Id: %d", archive[i].Id);
		fprintf(out, "Release Date: %d", archive[i].ReleaseDate);
		fprintf(out, "Budget: %f", archive[i].Budget);
		fprintf(out, "Revenue: %f", archive[i].Revenue);
	}
	fclose(out);
}

void AddMovie(Movie archive[], int count)
{
	printf("Enter Title:");
	scanf(" %s", archive[count].Title);

	printf("Enter Genre:");
	scanf(" %c", archive[count].Genre);

	printf("Enter Id:");
	scanf(" %d", archive[count].Id);

	printf("Enter Release Date:");
	scanf(" %d", archive[count].ReleaseDate);

	printf("Enter Budget:");
	scanf(" %lf", archive[count].Budget);

	printf("Enter Revenue:");
	scanf(" %lf", archive[count].Revenue);
}

int DisplayIds(Movie archive[], int count)
{
	int Id;
	for (int i = 0; i < count; i++)
	{
		printf("Id: %d", archive[i].Id);

	}
	printf("Choose an ID");
	scanf("%d", Id);
	return(Id);
}

int SearchId(Movie archive[], int count, int id)
{
	for (int i = 0; i < count; i++)
	{
		if (id == archive[i].Id)
			return(i);
	}

}
void EditMovie(Movie archive[], int count)
{
	int Decision;
	printf("\nWoud You like to edit the Title?: ");
	scanf("%d", Decision);

	if (Decision == 'Y' || Decision == 'y')
	{
		printf("Edit Title");
		scanf(" %s", archive[count].Title);
	}
	
	printf("\nWoud You like to edit the Genre?: ");
	scanf("%d", Decision);
	if (Decision == 'Y' || Decision == 'y')
	{
		printf("Edit Genre");
		scanf(" %c", archive[count].Genre);
	}
	
	printf("\nWoud You like to edit the Release Date?: ");
	scanf("%d", Decision);
	if (Decision == 'Y' || Decision == 'y')
	{
		printf("Edit Release Date");
		scanf(" %c", archive[count].ReleaseDate);
	}

	printf("\nWoud You like to edit the Budget?: ");
	scanf("%d", Decision);
	if (Decision == 'Y' || Decision == 'y')
	{
		printf("Edit Budget");
		scanf(" %lf", archive[count].Budget);
	}

	printf("\nWoud You like to edit the Revenue?: ");
	scanf("%d", Decision);
	if (Decision == 'Y' || Decision == 'y')
	{
		printf("Edit Revenue");
		scanf(" %lf", archive[count].Revenue);
	}
}
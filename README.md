Activity 4 EEL

Create an employee database using structure and display information. Design C program to display the information of all employees in a company sorted by their salaries from highest to lowest. Each employee’s information including their employee id and salary is sorted in a data base using arrays and structures. The program should read the employee data from the database, organise it based on the salaries and then print the details of each employee in descending order of their salaries. Additionally the program should handle ties in salary and provide a consistent method for sorting the employees.

Research:

A data is a structured collection of data organized for easy access, management and retrieval. It serves as a centralized repository where information can be stored, manipulated and analyzed efficiently. 
Types of Databases:
Hierarchical Databases:
Hierarchical databases organize data in a tree-like structure, where each parent record can have multiple child records. This model works well for scenarios where data is arranged in levels or ranks.
Network Databases:
A network database builds on the hierarchical model but allows child records to be linked to multiple parent records, creating a web-like structure of interconnected data. 
Cloud Databases:
A cloud database operates in a virtual environment hosted on cloud computing platforms. It is designed for storing, managing, and executing data over the internet, providing flexibility and scalability.
Centralized Databases:
A centralized database is a database stored and managed at a single location, such as a central server or data center. It ensures higher security and consistency as all data are maintained in one place, making it easier to control and manage.
Personal Databases
A personal database is a small-scale database designed for a single user, typically used on personal computers or mobile devices. These databases are ideal for managing individual data like contacts, budgets, notes or schedules. 
Operational databases:
An operational database is designed to manage and process real-time data for daily operations within organizations and businesses. It allows user to create, update and delete data efficiently, ensuring that the database reflects current businesses. 

References: 
https://ethans.co.in/blogs/what-is-database-types-example-advantages-disadvantages/
https://www.geeksforgeeks.org/dbms/types-of-databases/
https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm


Analyse:

Advantages of Databases: 
Efficient Data Management
Data Integrity
Scalability
Improved Decision Making
Data Security

Disadvantages of Databases:
Complexity
Cost
Single Point of Failure
Data Redundancy
Performance Issues

Structures:
In C, a structure is a user-defined data type that can be used to group items of possibly different types into a single type. The struct keyword is used to define a structure. The items in the structure are called its members and they can be of any valid data type.
Syntax: 
Initialization: struct structure_name str = {value1, value2, value3 ....};
Operations on a structure: 
To access or modify members of a structure, we use the (.) dot operator. This is applicable when we are using structure variables directly.

Insertion Sort:
Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list.
We start with the second element of the array as the first element is assumed to be sorted.
Compare the second element with the first element if the second element is smaller then swap them.
Move to the third element, compare it with the first two elements, and put it in its correct position
Repeat until the entire array is sorted.


Ideate:

Create a program that creates a database of movies by taking input from the user and displays it. Each movie’s information should include the movie name, its runtime, its imdb rating and its rotten tomatoes rating. The program should read the movie data from the database, organise it in a descending order based on either the runtime, the imdb rating or the rotten tomatoes rating. Additionally the program should handle ties in ratings and provide a consistent method for sorting the employees.
If there is a tie while sorting based on imdb rating, then the rotten tomatoes rating should be taken into consideration. If they also match, then the runtime should be compared. 
If there is a tie while sorting based on rotten tomatoes rating, then the imdb rating should be taken into consideration. If they also match, then the runtime should be compared. 


Build:

#include <stdio.h>


struct movie{
	char name[100];
	float imdb;
	int rottentomatoes, runtime;
};


void input(struct movie list[], int *count);
void sort_runtime(struct movie list[], int count);
void sort_imdb(struct movie list[], int count);
void sort_rottentomatoes(struct movie list[], int count);
void display(struct movie list[], int count);


int main(){
	int count=0, n;
	struct movie list[10];
	input(list, &count);


	printf("Sorting options: ");
	printf("\n 1. Sort by runtime (descending order)");
	printf("\n 2. Sort by imdb rating (descending order)");
	printf("\n 3. Sort by rotten tomatoes rating (descending order)");
	printf("\n Enter the choice: ");
	scanf("%d", &n);
	switch(n){
    	case 1: sort_runtime(list, count);
            	printf("\n The movies sorted according to runtime are: ");
            	break;
    	case 2: sort_imdb(list, count);
            	printf("\n The movies sorted according to imdb are: ");
            	break;
    	case 3: sort_rottentomatoes(list, count);
            	printf("\n The movies sorted according to rotten tomatoes are: ");
            	break;
          	 
	}
	display(list, count);
   
	return 0;
}


void input(struct movie list[], int *count){
	int n;
	for(int i = 0; i < 10; i++){
    	printf("Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): ");
    	scanf("%d", &n);
    	if(n==1){
        	printf("Enter movie name: ");
        	scanf("%s", list[i].name);
        	printf("Enter  the movie runtime in minutes: ");
        	scanf("%d", &list[i].runtime);
        	printf("Enter imdb rating: ");
        	scanf("%f", &list[i].imdb);
        	printf("Enter rotten tomatoes rating: ");
        	scanf("%d", &list[i].rottentomatoes);
        	(*count)++;
        	printf("\n");
    	}
    	else{
        	break;
    	}
	}
}


void display(struct movie list[], int count){
	for(int i = 0; i < count; i++){
    	printf("\n %d: Movie name: %s \n	Runtime: %d minutes \n	Imdb Rating: %.1f \n	Rottentomatoes Rating: %d \n", (i+1), list[i].name, list[i].runtime, list[i].imdb, list[i].rottentomatoes);
	}
}


void sort_runtime(struct movie list[], int count){
	int max;
	for(int i = 0; i < count; i++){
    	max = i;
    	for(int j = i; j < count; j++){
        	if(list[j].runtime > list[max].runtime){
            	max = j;
        	}
    	}
    	if(max != i){
        	struct movie temp = list[i];
        	list[i] = list[max];
        	list[max] = temp;
    	}
	}
}


void sort_imdb(struct movie list[], int count){
	int max;
	for(int i = 0; i < count; i++){
    	max = i;
    	for(int j = i; j < count; j++){
        	if(list[j].imdb > list[max].imdb){
            	max = j;
        	}
        	else if(list[j].imdb == list[max].imdb){
            	if(list[j].rottentomatoes > list[max].rottentomatoes){
                	max = j;
            	}
            	else if(list[j].rottentomatoes == list[max].rottentomatoes){
                	if(list[j].runtime > list[max].runtime){
                    	max = j;
                	}
            	}
        	}
    	}
    	if(max != i){
        	struct movie temp = list[i];
        	list[i] = list[max];
        	list[max] = temp;
    	}
	}
}


void sort_rottentomatoes(struct movie list[], int count){
	int max;
	for(int i = 0; i < count; i++){
    	max = i;
    	for(int j = i; j < count; j++){
        	if(list[j].rottentomatoes > list[max].rottentomatoes){
            	max = j;
        	}
        	else if(list[j].rottentomatoes == list[max].rottentomatoes){
            	if(list[j].imdb > list[max].imdb){
                	max = j;
            	}
            	else if(list[j].imdb == list[max].imdb){
                	if(list[j].runtime > list[max].runtime){
                    	max = j;
                	}
            	}
        	}
    	}
    	if(max != i){
        	struct movie temp = list[i];
        	list[i] = list[max];
        	list[max] = temp;
    	}
	}
}


Test:

Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): 1
Enter movie name: Harry_Potter
Enter  the movie runtime in minutes: 134
Enter imdb rating: 9.5
Enter rotten tomatoes rating: 89

Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): 1
Enter movie name: The_Dark_Knight
Enter  the movie runtime in minutes: 140
Enter imdb rating: 8.6
Enter rotten tomatoes rating: 89

Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): 1
Enter movie name: Joker
Enter  the movie runtime in minutes: 170
Enter imdb rating: 9.5
Enter rotten tomatoes rating: 70

Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): 1
Enter movie name: Frankenstein
Enter  the movie runtime in minutes: 110
Enter imdb rating: 9.2
Enter rotten tomatoes rating: 92

Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): 1
Enter movie name: Dhoom
Enter  the movie runtime in minutes: 210
Enter imdb rating: 8.7
Enter rotten tomatoes rating: 90

Enter 1 to input movie info, enter 0 to exit (maximum 10 entries): 0
Sorting options: 
 1. Sort by runtime (descending order)
 2. Sort by imdb rating (descending order)
 3. Sort by rotten tomatoes rating (descending order)
 Enter the choice: 2

 The movies sorted according to imdb are:
 1: Movie name: Harry_Potter
        Runtime: 134 minutes
        Imdb Rating: 9.5
        Rottentomatoes Rating: 89

 2: Movie name: Joker
        Runtime: 170 minutes
        Imdb Rating: 9.5
        Rottentomatoes Rating: 70

 3: Movie name: Frankenstein
        Runtime: 110 minutes
        Imdb Rating: 9.2
        Rottentomatoes Rating: 92

 4: Movie name: Dhoom
        Runtime: 210 minutes
        Imdb Rating: 8.7
        Rottentomatoes Rating: 90

 5: Movie name: The_Dark_Knight
        Runtime: 140 minutes
        Imdb Rating: 8.6
        Rottentomatoes Rating: 89



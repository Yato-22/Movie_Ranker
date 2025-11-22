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

// create a file x1.txt and write some text in it. 
//create move.c file
//write a program to copy the content of x1.txt to x2.txt and delete x1.txt. 
//ls to check  => move.c  x1.txt
//./a.out
//ls to check => a.out  move.c  x2.txt
# include <stdio.h>
# include <stdlib.h>

int main(){
	char ch; // source_file[20], target_file[20];
	FILE *source, *target;
	char source_file[]="x1.txt";
	char target_file[]="x2.txt";
	source = fopen(source_file,"r");
	if(source == NULL){
		printf("Press any key to exit...");
		exit(EXIT_FAILURE);
	}
	target = fopen(target_file,"w");
	if (target == NULL){
		fclose(source);
		printf("Press any key to exit...");
		exit(EXIT_FAILURE);
	}
	while((ch = fgetc(source)) != EOF)
		fputc(ch, target);
	printf("File moved successfully.");
	fclose(source);
	fclose(target);
	remove(source_file); //removes x1.txt
	return 0;
}
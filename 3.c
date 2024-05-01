// touch copy.c
// nano copy.c
// write code in the copy.c file
// gcc copy.c  //Compile the copy.c file using gcc
// ./a.out  //If no errors, the executable file a.out will be created in same directory.
// ls  //to check if complete

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch; // source_file[20], target_file[20];
    FILE *source, *target;
    char source_file[] = "x1.txt";
    char target_file[] = "x2.txt";
    source = fopen(source_file, "r");
    if (source == NULL)
    {
        printf("Press any key to exit...");
        exit(EXIT_FAILURE);
    }
    target = fopen(target_file, "w");
    if (target == NULL)
    {
        fclose(source);
        printf("Press any key to exit...");
        exit(EXIT_FAILURE);
    }
    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);
    printf("File copied successfully.");
    fclose(source);
    fclose(target);
    return 0;
}
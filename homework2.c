/*
Name: Pranay Kumar Reddy Malladi
Blazer ID: pmalladi
project#: Homework 2
To compile:<gcc -Wall -o homework2 homework2.c>
To run:./<name of executable> <commands and arguments> <directory>
      :<./homework2 /home/UAB/pmalladi/CS532 -t f>
      :<./homework2 /home/UAB/pmalladi/CS532 -t d>
      :<./homework2 /home/UAB/pmalladi/CS532 -S>
      :<./homework2 /home/UAB/pmalladi/CS532 -S 1000>
      :<./homework2 /home/UAB/pmalladi/CS532 -f c>
      :<./homework2 /home/UAB/pmalladi/CS532 -t f> */
      

/* Sample program to illustrate how to use function pointers */
/* Sample program to illustrate how to use function pointers */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile(){
	FILE *fp;
	char ch;
	fp = fopen("a.txt", "r");
	do {
			 ch = fgetc(fp);
			 printf("%c", ch);
	 } while (ch != EOF);
	fclose(fp);
	return;
}

void getDirInfo(char directory[], int fileSize, char pattern[]){
	printf("Getting directory info\n");
	char cmd[] = "ls -l ";
	if(directory == NULL){
		strcat(cmd, "| awk '{Print $10}'");
	}
	else{
		strcat(cmd, directory);
		strcat(cmd, " | awk '{print $10}'");
	}
	if(fileSize > -1){
		strcat(cmd, "| awk '{print $10, $6}'");
	}
	if(pattern){
		strcat(cmd, "| grep ");
		strcat(cmd, pattern);
	}
	strcat(cmd, " > a.txt");
	system(cmd);
	readFile();
	return;
}

char* removeTrailchar(char *str){
	char *end;
	while(isspace((unsigned char)*str)) str++;
	if(*str == 0)
		return str;

	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end)) end--;
	end[1] = '\0';

	return str;
}

int main(int argc, char **argv) {
	printf("%d\n", argc);
	//if no commands are given
	if(argc == 1){
		getDirInfo(NULL, -1, NULL);
	}
	//if atleast one command is given
	
	int i;
	for( i = 1; i < argc; i = i+1){
		printf("%d.%s\n",i, removeTrailchar(argv[i]));
		if(strcmp(argv[i], "-s") == 0){
			printf("Get files with size\n");
			getDirInfo(NULL, argv[i+1], NULL);
			i = i+1;
		}
		else if(strcmp(argv[i], "-S") == 0){
			printf("Getting files in the directory\n");
			//printf(argv[i+1]);
			if(argv[i+1]){
				//printf(argv[i+1]);
				getDirInfo(argv[i+1], -1, NULL);
				i = i+1;
			}
			else{
				printf("current directory\n");
				getDirInfo(NULL, -1, NULL);
			}
		}
		else if(strcmp(argv[i], "-f") == 0){
			printf("Get files with a pattern\n");
			getDirInfo(NULL, -1, argv[i+1]);
			i = i+1;
		}
		else{
			printf("error in pattern\n");
			exit(0);
		}
	}
	return 0;
}

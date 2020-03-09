#include <stdio.h>

#define MAXNAMELEN 50

struct names_and_grades
	{
		char name [MAXNAMELEN];
		float grade;
	};

int main(int argc , char** argv){/*
	// Verify correct usage
	if (argc != 2) {
		printf("usage: %s <file_name>\n" , argv[0]);
		return 1;	
	}

	

	// Open the file
	int file_fd = open(argv[1] , O_WRONLY | O_TRUNC);
	if (file_fd != 0) {
		perror(file_fd);*/
		return 2;
	}
    
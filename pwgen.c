#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define DEF_LENGTH 8

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int length = DEF_LENGTH;
	char password[length + 1];
	char charpool[128];
	int poolsize = 0;
	
	if (argc == 1){
		printf("Usage: pwgen -l <n>, -i, -b, -a\n");
		printf("-l: length of your password, default is 8.");
		printf("-i: includes integers.\n");
		printf("-b: includes basic charactes.\n");
		printf("-a: includes advanced characters.\n");
	} else {
		for (int i = 1; i < argc; i++){
			if (strcmp(argv[i],"-l") == 0){
				length = atoi(argv[++i]);
			}else if(strcmp(argv[i],"-i") == 0){
				for(char c = '0'; c <= '9'; c++) 
					charpool[poolsize++] = c;
			}else if(strcmp(argv[i],"-b") == 0){
				for(char c = 'A'; c <= 'z'; c++) 
					charpool[poolsize++] = c;
			}else if(strcmp(argv[i],"-a") == 0){
				for(char c = '{'; c <= '~'; c++) 
					charpool[poolsize++] = c;
			}else {
				printf("no command found!\n");
			}
		}
	}  
	
	if (poolsize == 0) {
        printf("Error: No character set selected!\n");
        return 1;
    }

	for (int i = 0; i < length; i++){
    	password[i] = charpool[rand() % poolsize];
    }
    
    password[length] = '\0';
    
	printf("%s\n", password);
	return 0;
}
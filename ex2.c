#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	char names[20][15];
	int num = 0, loop = 1, i;

	while(loop){
		fgets(names[num], 15, stdin);

		//remove that pesky newline char
		int len = strlen(names[num]);
		if(names[num][len - 1] == '\n'){
			names[num][len - 1] = '\0';
		}

		if(strcmp(names[num],"END") == 0){ 
			loop = 0;
		}
		else{
			num++;
		}
	}

	bedtimestory(names, 0, num);
}

void bedtimestory(char words[20][15], int current, int number){
	int i;
	if(current < number - 1){
		for(i = 0; i < current; i++){
			printf("  ");
		}
		
		if(current == 0){
			printf("A %s couldn't sleep, so her mother told a story about a little %s,\n", words[current], words[current+1]);
		}
		else{
			printf("who couldn't sleep, so the %s's mother told a story about a little %s,\n", words[current], words[current+1]);
		}		
	}
	
	if(current < number - 1){
		bedtimestory(words, current + 1, number);
	}
	//put some sort of conditional on this for loop
	for(i = 0; i < current; i++){
		printf("  ");
	}
	if(current == number - 1){
		printf("... who fell asleep.\n");
	}
	else if(current == 0){
		printf("... and then the %s fell asleep.\n", words[current]);
	}		
	else if(current < number - 1){
		printf("... and then the little %s fell asleep;\n", words[current]);
	}
}
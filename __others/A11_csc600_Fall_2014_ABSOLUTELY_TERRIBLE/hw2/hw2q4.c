/**Write a program BigInt(n) that displays an arbitrary positive integer n using big
characters of size 7x7, as in the following example for BigInt(170):
  @@   @@@@@@@  @@@@@
 @@@        @@ @@   @@
  @@       @@  @@   @@
  @@      @@   @@   @@
  @@     @@    @@   @@
  @@    @@     @@   @@
@@@@@@ @@       @@@@@
**/

#include <stdio.h>
#include <string.h>

void BigInt(int n);
void printNum(int num, int line);

int main()
{
	BigInt(170);
	return 0;
}

void BigInt(int n)
{
	int count = 0, line, num;
	int arr[100];
	//break n into digits and store in an array
	while(n > 0)
	{
		int digit = n % 10;

		arr[count] = digit;

		n /= 10;
		count++;
	}

	//print numbers by line
	for(line = 1; line <= 7; line++)
	{
		//print number segment
		for(num = count - 1; num >= 0; num--)
		{
			printNum(arr[num],line);
		}
	
		printf("\n");
	}

	return;
}

void printNum(int num, int line)
{
	switch(num)
	{
		case 0:
			if(line == 1){		printf(" *****  ");}
			else if(line == 2){	printf("**   ** ");}
			else if(line == 3){	printf("**   ** ");}
			else if(line == 4){	printf("**   ** ");}
			else if(line == 5){	printf("**   ** ");}
			else if(line == 6){	printf("**   ** ");}
			else if(line == 7){	printf(" *****  ");}
			else{printf("Invalid line\n");}
			break;
		case 1:
			if(line == 1){		printf("  ***   ");}
			else if(line == 2){	printf("*****   ");}
			else if(line == 3){	printf("  ***   ");}
			else if(line == 4){	printf("  ***   ");}
			else if(line == 5){	printf("  ***   ");}
			else if(line == 6){	printf("  ***   ");}
			else if(line == 7){	printf("******* ");}
			else{printf("Invalid line\n");}
			break;
		case 2:
			if(line == 1){		printf(" *****  ");}
			else if(line == 2){	printf("**   ** ");}
			else if(line == 3){	printf("     ** ");}
			else if(line == 4){	printf("    **  ");}
			else if(line == 5){	printf("   **   ");}
			else if(line == 6){	printf(" ***    ");}
			else if(line == 7){	printf("******* ");}
			else{printf("Invalid line\n");}
			break;
		case 3:
			if(line == 1){		printf(" *****  ");}
			else if(line == 2){	printf("*    ** ");}
			else if(line == 3){	printf("    *** ");}
			else if(line == 4){	printf(" ****   ");}
			else if(line == 5){	printf("    *** ");}
			else if(line == 6){	printf("*    ** ");}
			else if(line == 7){	printf(" *****  ");}
			else{printf("Invalid line\n");}
			break;
		case 4:
			if(line == 1){		printf("   **   ");}
			else if(line == 2){	printf("  ***   ");}
			else if(line == 3){	printf(" * **   ");}
			else if(line == 4){	printf("*  **   ");}
			else if(line == 5){	printf("******* ");}
			else if(line == 6){	printf("   **   ");}
			else if(line == 7){	printf("   **   ");}
			else{printf("Invalid line\n");}
			break;
		case 5:
			if(line == 1){		printf("******* ");}
			else if(line == 2){	printf("**      ");}
			else if(line == 3){	printf("**      ");}
			else if(line == 4){	printf("******  ");}
			else if(line == 5){	printf("     ** ");}
			else if(line == 6){	printf("*    ** ");}
			else if(line == 7){	printf(" *****  ");}
			else{printf("Invalid line\n");}
			break;
		case 6:
			if(line == 1){		printf(" *****  ");}
			else if(line == 2){	printf("**   ** ");}
			else if(line == 3){	printf("**      ");}
			else if(line == 4){	printf("******  ");}
			else if(line == 5){	printf("**   ** ");}
			else if(line == 6){	printf("**   ** ");}
			else if(line == 7){	printf(" *****  ");}
			else{printf("Invalid line\n");}
			break;
		case 7:
			if(line == 1){		printf("******* ");}
			else if(line == 2){	printf("**   ** ");}
			else if(line == 3){	printf("     ** ");}
			else if(line == 4){	printf("    **  ");}
			else if(line == 5){	printf("   **   ");}
			else if(line == 6){	printf("  **    ");}
			else if(line == 7){	printf(" **     ");}
			else{printf("Invalid line\n");}
			break;
		case 8:
			if(line == 1){		printf(" *****  ");}
			else if(line == 2){	printf("**   ** ");}
			else if(line == 3){	printf("**   ** ");}
			else if(line == 4){	printf("******* ");}
			else if(line == 5){	printf("**   ** ");}
			else if(line == 6){	printf("**   ** ");}
			else if(line == 7){	printf(" *****  ");}
			else{printf("Invalid line\n");}
			break;
		case 9:
			if(line == 1){		printf(" *****  ");}
			else if(line == 2){	printf("**   ** ");}
			else if(line == 3){	printf("**   ** ");}
			else if(line == 4){	printf(" ****** ");}
			else if(line == 5){	printf("     ** ");}
			else if(line == 6){	printf("**   ** ");}
			else if(line == 7){	printf(" *****  ");}
			else{printf("Invalid line\n");}
			break;
		default:
			printf("Invalid digit\n");
	}
}

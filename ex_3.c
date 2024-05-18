/**********************
 * Nadav Menirav
 * 330845678
 * ex_3
 **********************/

#include <stdio.h>
#define SIZE 30

//Functions
int getTask();
int runProg();
void callFirstTask();
void mergePrint(int a1[], int a2[], int start1, int start2, int end1, int end2);
void callSecondTask();
int paliDistance(char str[], int start, int end);
void callThirdTask();
int checkBalance(char* str, int n);
int checkBalanceHelp(char* str, int n, int countTillN, int countA, int countB);
void callFourthTask();
int escapingTime(int n);
void callFifthTask();
int heistOpt(int maxW, int optVal, int w[], int v[], int start, int len);
void fillArrayChar(char arr[], int length); 

int main() {
	//Calls the runProg function to run Tony's system
	runProg();
	printf("goodbye boss!"); 
	return 0;
}

int getTask() {
	//The function gets an integer from user which represents a task and returns it
	int taskChoice = 0;
	printf("What is your desired task boss?\n");
	printf("1. merge order incomes\n");
	printf("2. find distance from symmetry\n");
	printf("3. check if the gangs are balanced\n");
	printf("4. find optimal time for escaping\n");
	printf("5. check workers efficiency\n");
	printf("6. exit\n");

	scanf(" %d", &taskChoice);

	//Checks if input is valid, if not, starts over
	if (taskChoice > 6 || taskChoice < 1) {
		printf("Sorry Tony, I don't understand...\n");
		return getTask();
	}

	return taskChoice; //Valid task choice
}

int runProg() {
	/*
	The function uses the chosen task number, and calls the requested task.It will call itself and run until the user
	decides to quit
	*/
	int taskChoice = getTask(); //The task Tony Chose

	if (taskChoice == 1) {
		callFirstTask();
		return runProg();
	}

	if (taskChoice == 2) {
		callSecondTask();
		return runProg();
	}
	
	if (taskChoice == 3) {
		callThirdTask();
		return runProg();
	}

	if (taskChoice == 4) {
		callFourthTask();
		return runProg();
	}

	if (taskChoice == 5) {
		callFifthTask();
		return runProg();
	}
	//If it didn't enter any of the conditions, it means user chose 6 and wants to quit
	return 0;
}

void callFirstTask() {
	//The function gets all the preperations for the first task.
	int lengthOfFirstArray = 0, lengthOfSecondArray = 0, arr1[SIZE] = {0}, arr2[SIZE]={0}, start1 = 0, start2 = 0;

	printf("Enter the length of the first worker array:\n");
	scanf(" %d", &lengthOfFirstArray);
	printf("Now enter the first array's elements:\n");

	for (int i = 0;i < lengthOfFirstArray;i++)
		scanf(" %d", &arr1[i]);

	printf("Enter the length of the second worker array:\n");
	scanf(" %d", &lengthOfSecondArray);
	printf("Now enter the second array's elements:\n");

	for (int i = 0;i < lengthOfSecondArray;i++)
		scanf(" %d", &arr2[i]);

	//Calling the first task

	printf("start ");
	mergePrint(arr1, arr2, start1, start2, lengthOfFirstArray - 1, lengthOfSecondArray - 1);
	printf("end\n");
}

void mergePrint(int a1[],int a2[], int start1, int start2, int end1, int end2) {
	/*
	The first task
	Input: 2 sorted arrays, representing incomes of workers, the start and end point of each one of them.
	Output: Prints the numbers in both arrays in a decresing order
	*/
	if (start1 > end1 && start2 > end2) //Ends the function after printed all the numbers
		return;

	//If one array ended, prints the other array elements
	if (start1 > end1 && start2 <= end2) {
		printf("%d ", a2[start2]);
		mergePrint(a1, a2, start1, start2 + 1, end1, end2);
		return;
	}

	if (start1 <= end1 && start2 > end2) {
		printf("%d ", a1[start1]);
		mergePrint(a1, a2, start1 + 1, start2, end1, end2);
		return;
	}

	//If both have numbers left to print, finds the smaller one between the arrays and prints it
	if (a1[start1] <= a2[start2]) { 
		printf("%d ", a1[start1]);
		mergePrint(a1, a2, start1 + 1, start2, end1, end2);
		return;
	}
	else {
		printf("%d ", a2[start2]);
		mergePrint(a1, a2, start1, start2 + 1, end1, end2);
		return;
	}
}

void callSecondTask() {
	//The function gets all the preperations for second task
	int arrayLength = 0, start = 0, result = 0;
	char arr[SIZE] = { '\0' };

	printf("Enter the length of the string:\n");
	scanf(" %d", &arrayLength);
	printf("Now enter the string:\n");
	fillArrayChar(arr, arrayLength);
	//Calling the second task
	result = paliDistance(arr, start, arrayLength - 1);
	printf("The palindrome distance is %d.\n", result);
}

int paliDistance(char str[], int start, int end) {
	/*
	Input: An array of chars (String), starting and end points
	Output: The number of chars needed to be changed in order for the String to be a palyndrome. 
	*/
	if (start > end/2) //Means we went through the entire String
		return 0;
	return (str[start] != str[end - start]) + paliDistance(str, start + 1, end);
}

void callThirdTask() {
	//The function gets all the preperations for the third task and calls it
	int countG = 0; //Number of gang members
	int isBalanced = 0; 
	char typeG[SIZE] = { '\0' };

	printf("Enter the number of gang members:\n");
	scanf(" %d", &countG);
	printf("Enter the gang associations:\n");
	fillArrayChar(typeG, countG);
	//Calls third task
	isBalanced = checkBalance(typeG, countG);
	
	//Balanced
	if (isBalanced)
		printf("The army is balanced.\n");

	//Not balanced
	else
		printf("The army is not balanced.\n");
}

int checkBalance(char* str, int n) {
	//The third task. It uses an auxiliary function that does the main work
	return checkBalanceHelp(str, n, 0, 0, 0);
}

int checkBalanceHelp(char* str, int n, int countTillN, int countA, int countB) {
	//The function checks if a string contains the same amout of 'a' and 'b' and returns 1 it does and 0 otherwise
	if (countTillN >= n) {
		if (countA == countB)
			return 1;
		return 0;
	}

	if (str[countTillN] == 'a')
		return checkBalanceHelp(str, n, countTillN + 1, countA + 1, countB);
	
	if (str[countTillN] == 'b')
		return checkBalanceHelp(str, n, countTillN + 1, countA, countB + 1);
	
}

void callFourthTask() {
	//The function gets all the prepereating for the fourth task
	int n = 0; //Represents current room number
	int escapeT = 0;

	printf("What room are you in boss?\n");
	scanf(" %d", &n);

	escapeT = escapingTime(n);
	printf("Your escaping time is: %d\n", escapeT);
}

int escapingTime(int n) {
	/*
	The function gets an integer which represents the current room number that Tony is in, and returns how long it will
	take for him to get to safety, room number 1
	*/
	if (n == 1)
		return 0;
	//Checks if the current room number is divisible by 2 or 3
	int canDiv3 = !(n % 3);
	int canDiv2 = !(n % 2);
	int leastSteps = 1 + escapingTime(n - 1); //Represents the number of steps it will take for him, should be the lowest
	if (canDiv3) {
		int stepsThree = 1 + escapingTime(n / 3);
		if(stepsThree < leastSteps) //Is going to a room numbered third of current room number better than going 1 room down
			leastSteps = stepsThree;
	}
	if (canDiv2) {
		int stepsTwo = 1 + escapingTime(n / 2);
		if (stepsTwo < leastSteps) //IS Going to a room numbered half, bettere than third, and than going 1 down
			leastSteps = stepsTwo;
	}
	return leastSteps;

}

void callFifthTask() {
	//The function gets all the preperations for the fifth task
	int maxW = 0, numberOfItems = 0, w[SIZE] = { 0 }, v[SIZE] = { 0 }, start = 0, optVal = 0;
	printf("Enter the number of objects and the maximum weight:\n");
	scanf(" %d", &numberOfItems);
	scanf(" %d", &maxW);
	printf("Now enter the objects' values and weights:\n");
	for (int i = 0;i < numberOfItems;i++) {
		scanf(" %d", &v[i]);
		scanf(" %d", &w[i]);
	}

	//Calls the fifth task
	optVal = heistOpt(maxW, optVal, w, v, start, numberOfItems);
	printf("The optimal heist income value is %d\n", optVal);
}

int heistOpt(int maxW, int optVal, int w[], int v[], int start, int len) {
	/*
	The fifth task
	Input: Array of weights, array of values, max weight possible in the bag, start and end points of arrays
	Output: Returns the optimal value of the sum of the items that can be put in the bag
	*/
	if (start >= len)
		return optVal;

	if (w[start] > maxW)
		return heistOpt(maxW, optVal, w, v, start + 1, len);

	int skip = heistOpt(maxW, optVal, w, v, start + 1, len);
	int withCurrent = heistOpt(maxW - w[start], optVal + v[start], w, v, start + 1, len);
	//Is taking the item better than not taking it?
	return (withCurrent > skip) ? withCurrent : skip;
}

void fillArrayChar(char arr[], int length) {
	for (int i = 0;i < length;i ++)
		scanf(" %c", &arr[i]);
	arr[length] = '\0';
}
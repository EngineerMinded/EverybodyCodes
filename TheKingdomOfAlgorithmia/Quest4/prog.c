/**************************
 *  Wayne Mack            *
 *  Everybody Codes       * 
 *  Quest 4               *
 **************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int partOne[] = {19 ,10 ,16 ,12, 16, 12, 7 ,13 ,13, 14, 10};

#define MAX_NUMBERS 501  // Maximum numbers to read from the file
/***********************************************************************
 * Read from file and, put into a number array                         *
 ***********************************************************************/
int* extract_numbers(const char *filename, int *num_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int *numbers = malloc(MAX_NUMBERS * sizeof(int));  // Allocate memory for numbers
    if (numbers == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    int current_num = 0;
    int index = 0;

    // Read through the file character by character
    while ((current_num = fgetc(file)) != EOF) {
        // Skip non-digit characters (space, newline, etc.)
        if (isdigit(current_num)) {
            ungetc(current_num, file);  // Push it back to convert to integer
            int num;
            fscanf(file, "%d", &num);
            numbers[index++] = num;  // Store the number
            if (index >= MAX_NUMBERS) {
                // If the numbers exceed the buffer size, stop reading
                break;
            }
        }
    }

    fclose(file);
    *num_count = index;  // Set the number of extracted numbers
    return numbers;      // Return the array of numbers
}
/****************************************************************
 * Function to get answers for Part 1 and Part 2                *
 ****************************************************************/
int partOneAnswer (int* num, int length) {
	int lowestNumber = -1; int count = -1; int strikes = 0;
	for (int i = 0; i < length; i++) {
        count++;
		if (lowestNumber == -1) {
            strikes = 0;
            lowestNumber = num[i];
        }
        else {
            if (num[i] >= lowestNumber) {
                strikes += num[i] - lowestNumber;
            }
            else {
                strikes = strikes + (count * (lowestNumber - num[i]));
                lowestNumber = num[i];
            }
        
        }
    }
    return strikes;
}
/****************************************************************
 * Function to get answers for Part 3                           *
 ****************************************************************/
int partThreeAnswer (int* num, int length) {
	int lowestNumber = 2147483647; int highestNumber = 0; int count = -1; int strikes = 0;
	for (int i = 0; i < length; i++) {
        if (num[i] > highestNumber) highestNumber = num[i];
        if (num[i] < lowestNumber ) lowestNumber = num[i];
    }
    int leastAmountOfStrikes = 2147483647;
    for (int x = lowestNumber; x <= highestNumber; x++) {
        strikes = 0;
        for (int i = 0; i < length; i++) {
            int difference = num[i] - x;
            if (difference < 0) difference = difference * -1;
            strikes = strikes + difference;
        }
        if (strikes < leastAmountOfStrikes) leastAmountOfStrikes = strikes;
    }

    return leastAmountOfStrikes;
}


/****************************************************************
 * The Main Function                                            *
 ****************************************************************/
int main() {
    // PART ONE
    printf ("Part One : %d !\n", partOneAnswer(partOne, 11));
    
    // PART TWO
    const char *filename = "part2.txt";  
    int num_count = 0;
    // Extract numbers from the file
    int *numbers = extract_numbers(filename, &num_count);

    if (numbers != NULL) {
        printf("Part Two %d !\n", partOneAnswer(numbers, num_count)); 
        free(numbers);  // Free allocated memory
    }
    const char *filename2 = "part3.txt";
    num_count = 0;

    numbers = extract_numbers(filename2, &num_count);

    if (numbers != NULL) {
        printf("Part Three : %d!\n", partThreeAnswer(numbers, num_count));
        free(numbers); 
    }
    return 0;
}

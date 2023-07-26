#include <stdio.h>
#include <stdlib.h>
// Define a constant for the size of the alphabet.
#define ALPHABET_SIZE 26

// Function to check if a character is uppercase.
int is_uppercase(char c)
{
    return c >= 'A' && c <= 'Z';
}
// Function to check if a character is lowercase.
int is_lowercase(char c)
{
    return c >= 'a' && c <= 'z';
}
// Function to convert an uppercase character to lowercase.
char to_lowercase(char c)
{
    return is_uppercase(c) ? (c + 'a' - 'A') : c;
}
// Function to count the frequency of each letter in the alphabet in a given file.
void count_letters(FILE *file, int *count)
{
    int c;
    // Loop through each character in the file.
    while ((c = fgetc(file)) != EOF)
    {
        // Check if the character is a letter.
        if (is_uppercase(c) || is_lowercase(c))
        {
            // Convert the character to lowercase.
            c = to_lowercase(c);
            // Increment the counter for the corresponding letter.
            count[c - 'a']++;
        }
    }
}
// Function to print the frequency of each letter in the alphabet.
void print_letter_count(int *count)
{
    printf("Letter Frequency:\n");
    // Loop through each letter in the alphabet.
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        // Print the letter and its frequency.
        printf("%c: %d\n", 'A' + i, count[i]);
    }
}

int main()
{
    // Declare an array to store the filename.
    char filename[100];
    // Prompt the user to enter the filename.
    printf("Enter the file name: ");
    // Read the filename from the user.
    scanf("%s", filename);
    // Open the file
    FILE *file = fopen(filename, "r");
    // Check if the file was opened successfully.
    if (file == NULL)
    {
        printf("Error opening file.\n");
    }
    // Declare an array to store the frequency of each letter in the alphabet.
    int count[ALPHABET_SIZE] = {0};
    // Count the frequency of each letter in the file.
    count_letters(file, count);
    // Print the frequency of each letter in the alphabet.
    print_letter_count(count);
    // Close the file.
    fclose(file);

    return 0;
}
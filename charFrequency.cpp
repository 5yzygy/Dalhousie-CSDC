/* A C++ Program to find the frequency of Characters in a String */
/* Author: Ahmet Emre Harsa */
/* E-mail: aemre.harsa@dal.ca */
/* = = = = = = = = = = = = = = */
/* Note: For the program to work and compute the frequencies */
/*       successfully, the user input should not include any */
/*       special characters, non-English-alphabetic characters, */
/*       numbers and punctuation marks - meaning only inputs that */
/*       are fully composed of English characters are treated as */
/*       valid inputs. The program will continue to accept more */
/*       inputs from the user and show its frequency results */
/*       unless the user inputs 'q' as an input, in which case */
/*       the program terminates. */

/* Header Files */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;  /* using the standard namespace for code brevity */
namespace CSDC  /* utilizing a CSDC namespace to include structs and functions */
{
    /* The charListNode struct is defined as below. Each node is composed of */
    /* a character (of type char) and its corresponding frequency (of type int). */
    typedef struct charListNode
    {
        char value;
        int frequency;  
    } CHARS;

    /* This function checks whether or not the input parameter string */
    /* contains at least one special character, non-English character */
    /* or punctuation mark. Spaces are excluded from the function logic. */
    /* Input Parameter: A string (containing the user input) */
    /* Return Value: boolean */
    bool includesSpecialChar(string str)
    {
        bool foundSpecialChar = false;
        for (string :: size_type i = 0; i < str.length(); ++i)
        {
            if (isalpha(str[i]) == 0 && str[i] != ' ') { foundSpecialChar = true; }
        }

        return foundSpecialChar;
    }

    /* This function returns lowercased versions */
    /* of all characters of the input parameter string. */
    /* Input Parameter: A string (containing the user input) */
    /* Return Value: string */
    string tolowercase(string str)
    {
        for (string :: size_type i = 0; i < str.length(); ++i) { str[i] = tolower(str[i]); }
        return str;
    }

    /* This function counts up the frequency of each English character appearing */
    /* in the user input first by traversing the input string char by char with */
    /* an outer loop and secondly by traversing the charList with an inner loop */
    /* for incrementing the frequency value according to the current char that */
    /* was encountered by the outer loop. */
    /* Input Parameter: 1) A string */
    /*                  2) An array that contains CHARS structs at its indexes */
    /* Return Value: void */
    void countFrequencies(string str, CHARS charList[])
    {
        for (string :: size_type j = 0; j < str.length(); ++j)
        {
            for (int index = 0; index < 26; ++index)
            {
                if (str[j] == charList[index].value)
                {
                    charList[index].frequency++;
                }
            }
        }
    }

    /* This function prints out the frequency results that are */
    /* computed before for each character in the English alphabet. */
    /* Input Parameter: An array that contains CHARS structs at its indexes */
    /* Return Value: void */
    void printFrequencies(CHARS charList[])
    {
        cout << "\nFrequency of each Character: " << endl;
        cout << "= = = = = = = = = = = = = = =" << endl;
        for (int k = 0; k < 26; ++k)
        {
            cout << charList[k].value << ": " << charList[k].frequency << endl;
        }
        
        cout << endl;
    }
}

int main()
{
    /* Declaring a string which will store the user input */
    string str;

    /* A while loop to run the instructions below over and over again */
    /* until the break condition is reached. This break condition */
    /* will be reached when the user enters 'q' as an input. */
    while (true)
    {
        /* Getting the input string from the user */
        cout << "This program displays the frequency of each character for a given input String." << endl;
        cout << "Please enter your input: ";
        getline(cin, str);

        /* If the user enters 'q' as the input, then break */
        /* out of the loop to end the execution of the program */
        if (str == "q") { break; }

        if (CSDC :: includesSpecialChar(str))
        {   /* When the user input includes at least one special character, */
            /* non-English character or punctuation mark, do the following: */
            try 
            {   /* An "invalid_argument" exception is thrown */
                throw invalid_argument("\nEntered input includes special characters or characters that do not belong to the English alphabet.");
            }

            catch (invalid_argument exception)
            {   /* The "invalid_argument" exception is catched */
                cerr << exception.what() << endl;
                cout << "When you try another input, please enter a valid input consisting only of English characters.\n" << endl;
            }
        }

        else
        {   /* When the user input consists only of characters */
            /* in the English alphabet, do the following: */
            CSDC :: CHARS charList[26] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};

            /* Transforming the string to lowercase for the simplification of the process */
            str = CSDC :: tolowercase(str);

            /* Counting the frequency of each English character */
            CSDC :: countFrequencies(str, charList);
            /* Printing out the results to the screen */
            CSDC :: printFrequencies(charList);
        }
    }

    return 0;
}
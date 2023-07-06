#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_alpha(string s);    // To check if the key has a character that is not aplhabetical
bool repeated_char(string s);   // To check if a character if repeated

int main(int argc, string argv[])
{
    // the user will enter a key in a form of 26 alphabetical characters as a command line argument
    // ask the user for a text
    // the program prints out the result : the input text encrypted

    if (argc != 2)
    {
      printf("Usage: ./substitution key\n");
      return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
      printf("The key must be 26 characters\n");
      return 1;
    }

    else if (!check_alpha(argv[1]))
    {
      printf("The key must contain only alphabetical characters\n");
      return 1;
    }
    else if (!repeated_char(argv[1]))
    {
      printf("Characters must not be repeated\n");
          return 1;
    }

    else
    // if the key is valid
    {
      string text = get_string("plaintext:");
      //string Upalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (int k = 0, n = strlen(text); k < n; k++)
      // To make the substitution
      {
        if (islower(text[k]))
        {
          /*int i = 0;
          while (text[k] != tolower(Upalphabet[i]))
          {
            i++;
          }
          text[k] = tolower(argv[1][i]);*/

          text[k] = tolower(argv[1][text[k] - 'a']);
        }
        else if (isupper(text[k]))
        {
          /*int i = 0;
          while (text[k] != Upalphabet[i])
          {
            i++;
          }
          text[k] = toupper(argv[1][i]);*/

          text[k] = toupper(argv[1][text[k] - 'A']);
        }
        else
        {
          ;
        }
      }
      printf("ciphertext:%s\n", text);
      return 0;
    }
}


bool check_alpha(string s)
{
    for (int k = 0, n = strlen(s); k < n; k++)
    {
      if (!isalpha(s[k]))
      {
        return false;
      }
    }
    return true;
}

bool repeated_char(string s)
{
    int n = strlen(s);
    for (int k = 0; k < n - 1; k++)
    {
      for ( int j = k + 1 ; j < n; j++)
      {
        if ( s[k] == s[j])
        {
          return false;
        }
      }
    }
    return true;
}

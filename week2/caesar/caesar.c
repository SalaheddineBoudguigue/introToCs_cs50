#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string caesar(string s, int k);
bool check_integer(string s); // false if the string is not an integer


int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Enter only one c.l.a\n");
    return 1;
  }
  else if (!check_integer(argv[1])) // we check if argv[1] is an integer
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  else
  {
    int k = atoi(argv[1]);  // the key of encrypting
    string input = get_string("plaintext:  ");
    printf("ciphertext: %s\n", caesar(input,k));
    return 0;
  }
}


string caesar(string s, int k)
{
  k = k % 26; //Just some math to solve the problem when k is higher than 26 ( You can check it)

  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (islower(s[i]))
    {
      s[i] = (s[i] - 'a' + k) % 26 + 'a';
    }
    else if (isupper(s[i]))
    {
      s[i] = (s[i] - 'A' + k) % 26 + 'A';
    }
    else s[i] = s[i];
  }
  return s;
}

bool check_integer(string s)
{
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (!isdigit(s[i]))
    {
      return false;
    }
  }
  return true;
}


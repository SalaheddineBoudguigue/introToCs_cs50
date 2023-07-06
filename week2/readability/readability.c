#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s); // number of letter
int count_words(string s);   // number of words
int count_sentences(string s); //number of sentences
int calculate_index(int a, int b, int c); //the grade number

int main(void)
{
  string text = get_string("Text: ");

  int a = count_letters(text);
  int b = count_words(text);
  int c = count_sentences(text);
  int index = calculate_index(a, b, c);
  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", index);
  }
  return 0;
}


int calculate_index(int a, int b, int c)
{
  float L = (a/(float)b) * 100;
  float S = (c/(float)b) * 100;
  return round(0.0588 * L - 0.296 * S - 15.8);
}

int count_letters(string s)
{
  int letters = 0;
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (isalpha(s[i]))
    {
      letters += 1;
    }
  }
  return letters;
}

int count_words(string s)
{
  int words = 1;
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (isspace(s[i]))
    {
      words += 1;
    }
  }
  return words;
}

int count_sentences(string s)
{
  int sentences = 0;
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (s[i] == '.' || s[i] == '!' || s[i] == '?')
    {
      sentences += 1;
    }
  }
  return sentences;
}


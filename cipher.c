#include "cipher.h"
#include <string.h>
#define MODULO 26
#define LOWER_CASE_LOW 97
#define LOWER_CASE_TOP 122
#define UPPER_CASE_LOW 65
#define UPPER_CASE_TOP 90

/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.

char get_char (int top, int low, char letter, int k){
  int ascii_number = (int)letter;
  int remainder = 0;

  if ((ascii_number + k) > top){
    remainder = (ascii_number + k) - top - 1;
    return (char)(low + remainder);

  } else if ((ascii_number + k < low)){
    remainder = low - (ascii_number + k + 1);
    return (char)(top - remainder);
  }

  return (char)(ascii_number + k);
}

// See full documentation in header file
void encode (char s[], int k)
{
  for (size_t i = 0; i < strlen(s); ++i)
  {
    char letter = s[i];
    if ((int)letter >= LOWER_CASE_LOW && (int)letter <= LOWER_CASE_TOP){
      s[i] = get_char (LOWER_CASE_TOP, LOWER_CASE_LOW, letter, k % MODULO);
    }
    else if ((int)letter >= UPPER_CASE_LOW && (int)letter <= UPPER_CASE_TOP){
      s[i] = get_char (UPPER_CASE_TOP, UPPER_CASE_LOW, letter, k % MODULO);
    }
    else{ continue;}
  }
}

// See full documentation in header file
void decode (char s[], int k)
{
  for (size_t i = 0; i < strlen (s); ++i)
  {
    char letter = s[i];
    if ((int)letter >= LOWER_CASE_LOW && (int)letter <= LOWER_CASE_TOP){
      s[i] = get_char (LOWER_CASE_TOP, LOWER_CASE_LOW, letter, k % MODULO);
    }
    else if ((int)letter >= UPPER_CASE_LOW && (int)letter <= UPPER_CASE_TOP){
      s[i] = get_char (UPPER_CASE_TOP, UPPER_CASE_LOW, letter, k % MODULO);
    }
    else{ continue;}
  }
}

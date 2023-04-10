#include "cipher.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE 1025
#define OPTION_ONE 2
#define OPTION_TWO 5

int run_tests (char command[])
{
  /**
   * Output: Type int.
   * Input: Type string.
   * This function check if the command that the user give is the correct one.
   * Also, the function run all the test from the test.c file,
   * and return value int.
   */

  if (strcmp (command, "test") != 0)
  {
    return 0;
  }

  int arr[] = {test_encode_non_cyclic_lower_case_positive_k (),
               test_encode_cyclic_lower_case_special_char_positive_k (),
               test_encode_non_cyclic_lower_case_special_char_negative_k (),
               test_encode_cyclic_lower_case_negative_k (),
               test_encode_cyclic_upper_case_positive_k (),
               test_decode_non_cyclic_lower_case_positive_k (),
               test_decode_cyclic_lower_case_special_char_positive_k (),
               test_decode_non_cyclic_lower_case_special_char_negative_k (),
               test_decode_cyclic_lower_case_negative_k (),
               test_decode_cyclic_upper_case_positive_k ()};
  for (size_t i = 0; i < sizeof (arr) / sizeof (arr[0]); ++i)
  {
    if (arr[i] != 0)
    {
      return 2;
    }
  }
  return 1;
}

int input_integrity (char **argv)
{
  /**
   * Output: Type int.
   * Input: Type string.
   * This function check if the command that the user give is the correct one.
   * Meaning check the input integrity.
   * The function relate to 4 arguments that that user give,
   * and return value int.
   */

  if ((strcmp (argv[1], "decode") != 0) && (strcmp (argv[1], "encode") != 0))
  {
    return 0;
  }

  for (size_t i = 0; i < strlen (argv[2]); ++i)
  {
    if ((i == 0) && (argv[2][i] == '-'))
    {
      continue;
    }
    if (!isdigit (argv[2][i]))
    {
      return 1;
    }
  }

  FILE *f;
  if (!(f = fopen (argv[3], "r")))
  {
    return 2;
  }
  fclose (f);

  return 3;
}

void start_running (char command[], int k, char src[], char dst[])
{
  /**
 * Output: Void.
 * Input: Type string, type int, type string, type string.
 * This function run the user request encode \ decode.
 */

  FILE *r = fopen (src, "r");
  FILE *w = fopen (dst, "w");
  char line[MAX_LINE];

  if (!strcmp (command, "encode"))
  {
    while (fgets (line, MAX_LINE, r))
    {
      encode (line, k);
      fputs (line, w);
    }[]
  }
  else if (!strcmp (command, "decode"))
  {
    while (fgets (line, MAX_LINE, r))
    {
      decode (line, -k);
      fputs (line, w);
    }
  }
  fclose (r);
  fclose (w);
}

int main (int argc, char *argv[])
{

  if (argc != OPTION_ONE && argc != OPTION_TWO)
  {
    fprintf (stderr, "The program receives 1 or 4 arguments only.\n");
    return EXIT_FAILURE;
  }

  if (argc == OPTION_ONE)
  {
    switch (run_tests (argv[1]))
    {
      case 0:
        fprintf (stderr, "Usage: cipher test\n");
        return EXIT_FAILURE;
        break;
      case 1:
        return EXIT_SUCCESS;
        break;
      case 2:
        return EXIT_FAILURE;
        break;
    }
  }

  if (argc == OPTION_TWO)
  {
    switch (input_integrity (argv))
    {
      case 0:
        fprintf (stderr, "The given command is invalid.\n");
        return EXIT_FAILURE;
        break;
      case 1:
        fprintf (stderr, "The given shift value is invalid.\n");
        return EXIT_FAILURE;
        break;
      case 2:
        fprintf (stderr, "The given file is invalid.\n");
        return EXIT_FAILURE;
        break;
    }

    long k = strtol (argv[2], NULL, 10);
    start_running (argv[1], k, argv[3], argv[4]);
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}

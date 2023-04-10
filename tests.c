#include "tests.h"
#include <string.h>

#define K_1 3
#define K_2 2
#define K_3 (-1)
#define K_4 (-3)
#define K_5 29

// See full documentation in header file
int test_encode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abc";
  char out[] = "def";
  encode (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "zick!";
  char out[] = "bkem!";
  encode (in, K_2);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "hey.";
  char out[] = "gdx.";
  encode (in, K_3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_cyclic_lower_case_negative_k ()
{
  char in[] = "dad";
  char out[] = "axa";
  encode (in, K_4);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_cyclic_upper_case_positive_k ()
{
  char in[] = "GOODBYE";
  char out[] = "JRRGEBH";
  encode (in, K_5);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "def";
  char out[] = "abc";
  decode (in, -K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "zoom.";
  char out[] = "bqqo.";
  decode (in, K_2);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "stop!";
  char out[] = "rsno!";
  decode (in, K_3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_cyclic_lower_case_negative_k ()
{
  char in[] = "booking";
  char out[] = "yllhfkd";
  decode (in, K_4);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_cyclic_upper_case_positive_k ()
{
  char in[] = "DOWNLOAD";
  char out[] = "GRZQORDG";
  decode (in, K_5);
  return strcmp (in, out) != 0;
}

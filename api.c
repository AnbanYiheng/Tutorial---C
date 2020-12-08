#include "api.h"

int check(const char *data, int len)
{
  char buf[1024];
  memset(buf, 0, 1024);
  strncpy(buf, data, len); // BUG - This incorrectly uses length of src, not dst

  // do something to ensure this isn't optimized away
  int buflen = strlen(buf);
  for (int i = 0; i <= ((buflen % 2 == 1) ? buflen - 1 : buflen) / 2; i++)
  {
    if (buf[i] != buf[buflen - 1 - i])
    {
      printf("not palindrome\n");
      return 0;
    }
  }
  printf("congrats!!palindrome!!\n");
  return 0;
}
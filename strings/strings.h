#ifndef strings_h
#define strings_h

int string_length(char s[])
{
  int i = 0;
  for (; s[i]; i++)
  {
    // printf("%c\n", s[i]);
    // continue;
    // break;
  }
  return i;
}

char *reverse_string(char rv[], char s[])
{
  int length = string_length(s) - 1;
  int i = 0;

  for (; i <= length; i++)
  {
    rv[i] = s[length - i];
    // printf("%p\n", &rv[i]);
    if (i == length)
    {
      rv[i + 1] = '\0';
    }
  }
  return rv;
}

#endif
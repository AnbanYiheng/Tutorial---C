#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
 
#include "api.h" 


#define SIZE 8192 
#define BUF_SIZE 32 
 
int check(const char* data, int len); 
 
int from_stdin() //从标准输入读取 
{ 
  char input[SIZE] = {0}; 
  int size = read(STDIN_FILENO, input, SIZE) - 1; 
  return check(input, size); 
} 
 
int from_file(char *filename) //从文件读取 
{ 
  FILE *infile; 
  char *buffer; 
  long length; 
  int result; 
 
  infile = fopen(filename, "r"); 
 
  if (infile == NULL) 
    return 1; 
 
  fseek(infile, 0L, SEEK_END); 
  length = ftell(infile); 
 
  fseek(infile, 0L, SEEK_SET); 
  buffer = calloc(length, sizeof(char)); 
  if (buffer == NULL) 
    return 1; 
 
  length = fread(buffer, sizeof(char), length, infile); 
  fclose(infile); 
 
  result = check(buffer, length); 
  free(buffer); 
  return result; 
} 
 
int main(int argc, char **argv) 
{ 
 
  if (argc == 1) 
  { 
    return from_stdin(); 
  } 
  else if (argc > 1) 
  { 
    return from_file(argv[1]); 
  } 
}

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */

void get_dir(char *dir_name);

int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name = malloc(100);
  get_dir(dir_name);
  printf("dir_name in main set as %s\n", dir_name);

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}

void get_dir(char *dir_name)
{
  /* accepts a pointer to a character string, reads input until 
     \n or EOF is encountered and updates dir_name */
  int i = 0;
  char c;
  while((c = getc(stdin)) != EOF && c != '\n') {
    *(dir_name + i) = c;
    i++;
  }
  printf("dir name set to %s\n", dir_name);
}

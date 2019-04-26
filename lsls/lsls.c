#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */

void get_dir(char *dir_name);

int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name = malloc(100);
  printf("%d args supplied\n", argc);
  if (argc == 1) {
    dir_name = ".";
  } else if (argc == 2) {
    dir_name = argv[1];
  } else {
    printf("Too many arguments specified: Usage: ./lsls [directory]\n");
    exit(1);
  }
  /*
   // input function not needed as we're parsing the command line
  char *dir_name = malloc(100);
  get_dir(dir_name);
  printf("dir_name in main set as %s\n", dir_name);
  */

  // Open directory
  DIR *dir = opendir(dir_name);
  if (dir == NULL) {
    printf("that directory does not exist\n");
    exit(1);
  }

  struct dirent *file;

  // Repeatly read and print entries
  while ((file = readdir(dir)) != NULL) {
    printf("%s\n", file->d_name);
  }

  // Close directory
  closedir(dir);

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

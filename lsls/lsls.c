#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Main
 */


int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name = malloc(100);
  if (argc == 1) {
    // if there are no arguments, set dir_name to current path
    getcwd(dir_name, 100);
  } else if (argc == 2) {
    // otherwise, use the provided path
    dir_name = argv[1];
  } else {
    // improper usage
    printf("Too many arguments specified: Usage: ./lsls [directory]\n");
    exit(1);
  }


  // Open directory
  DIR *dir = opendir(dir_name);
  if (dir == NULL) {
    // directory not found, print error and exit
    printf("that directory does not exist\n");
    exit(1);
  }

  struct dirent *file;

  // Repeatly read and print entries
  file = readdir(dir);
  while (file) {
    struct stat statbuf;
    char full_path[512];
    int is_dir; // to keep track of whether this is a directory

    // construct full path
    if (argc == 1) {
      sprintf(full_path, "%s/%s", dir_name, file->d_name);
    }
    else {
      sprintf(full_path, "%s/%s", argv[1], file->d_name);
    }

    stat(full_path, &statbuf);

    // use the bitwise AND op to check if this is a directory
    is_dir = statbuf.st_mode&S_IFDIR;
    if (is_dir) {
      printf("%-10s%s\n", "<DIR>", file->d_name);
    } else {
      printf("%-10ld%s\n",  statbuf.st_size, file->d_name);
    }

    // update file for next loop
    file = readdir(dir);
  }

  // Close directory
  closedir(dir);

  return 0;
}

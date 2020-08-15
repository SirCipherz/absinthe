#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void pkg_install(const char *pkg_name){
  char command[128] = "/bin/bash /var/db/absinthe/"; // Command's base
  int system(const char *command); // Init the "shell caller"
  
  strcat(command, pkg_name);   // Creating the
  strcat(command, "/install"); // command line
  
  system(command);
}

void pkg_desc(const char *pkg_name){
  char path[128] = "/var/db/absinthe/"; // Base path
  char desc[128] = "";
  FILE *desc_file;
  
  strcat(path, pkg_name);
  strcat(path, "/desc");

  printf("%s\n", path);
  desc_file = fopen(path, "r");

  fgets(desc, 128, desc_file);
  fclose(desc_file);
  
  printf("%s\n", desc);
}

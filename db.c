#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "pkg.h"

void db_search(const char *keyword){
  FILE *file;
  file = fopen("/var/db/absinthe/pkg.list", "r");
  char pkg_name[64] = "";
  
  while (fgets(pkg_name, 64, file) != NULL){
    if (strcmp(pkg_name, keyword) > strlen(keyword)){ // Check if the begining is the same
      //bold_green();
      printf("%s", pkg_name); // Print the package name
      pkg_desc("neofetch"); // Print the description
    }
  }
  
  fclose(file); // Closing the packages list
}

void db_download(void){
  int system(const char *command); // Init the "shell caller"
  system("/usr/bin/curl https://sircipherz.com/absinthe-db.tar.xz");
}

void db_install(void){
  int system(const char *command); // Init the "shell caller"
  system("/bin/tar -Jxf /tmp/absinthe-db.tar.xz -C /var/db/absinthe/"); // Extracting the database
}

void db_init(void){
  printf("Creation of the database\n");
  mkdir("/var/db/absinthe", 0770); // Create the database directory
  
  //db_download();
  db_install();
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "db.h"
#include "utils.h"
#include "pkg.h"

static void usage(void){
  printf("Usage : absinthe [i|r|s|u|U|v] package\n");
}

static void root_warning(void){
  printf("Absinthe can't be run as a normal user, please run it as root\n");
}

int main (int argc, char *argv[]){
  if (getuid() != 0){
    root_warning();
    exit(1);
  }
  
  if (argc == 1){
    usage();
    exit(0);
  }

  check_presence(); // Check if the database exist, otherwise it will create it
  char *y = "y";
  
  switch (argv[1][0]){
  case 'i': // Install
    pkg_install(argv[2]);
    break;
  case 'r':
    printf("Removing ...\n");
    break;
  case 's': // Search
    db_search(argv[2]);
    break;
  case 'u':
    printf("Updating package database ...\n");
    break;
  case 'U':
    printf("Updating the database and upgrading all the packages ...\n");
    break;
  default:
    usage();
  }
}

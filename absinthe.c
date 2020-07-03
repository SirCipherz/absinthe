#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void usage(void){
  printf("Usage : absinthe [i|r|s|u|U|v] package\n");
}

int main (int argc, char *argv[]){
  if (argc == 1){
    usage();
    exit(0);
  }

  for (int i=2; i < argc; i++){
    printf("%s", argv[i]);
  }
  
  switch (argv[1][0]){
  case 'i':
    printf("Installing ...\n");
    break;
  case 'r':
    printf("Removing ...\n");
    break;
  case 's':
    printf("Searching ...\n");
    break;
  case 'u':
    printf("Updating package database ...\n");
    break;
  case 'U':
    printf("Updating the database and upgrading all the packages ...\n");
    break;
  }
  default:
    usage();
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "db.h"

void bold_green(void){
  printf("\033[1;32m");
}

void yellow(void){
  printf("\033[0;33m");
}

void check_presence(void){
  struct stat st = {0};
  if (stat("/var/db/absinthe/", &st) == -1){
    db_init();
  }
}

int count_lines(const char *file_name){
  int lines = 0;
  FILE *file;
  char string[64] = "";
  file = fopen(file_name, "r");

  while (fgets(string, 64, file) != NULL){
    lines++;
  }
  
  return lines;
}

void progress(int current, int max){
  printf("\r\e[?25l"); // Flush the line and make the cursor disapears
  printf("["); // Start on the bar
  
  for (int i = 0; i < max; i++){
    if (i <= current){
      printf("█"); // Completed
    }
    else{
      printf(" "); // Uncompleted
    }
  }
  printf("]"); // End of the bar
  printf("\e[?25h"); // Show back the cursor
}

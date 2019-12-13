#include <stdio.h>

#include <string.h>

#include <stdlib.h>     /* atoi */

#define NODES 50
int main() {

  // Declare the file pointer 
  FILE * filePointer;

  // Declare the variable for the data to be read from file 
  char dataToBeRead[50];

  // Open the existing file GfgTest.c using fopen() 
  // in read mode using "r" attribute 
  filePointer = fopen("e.csv", "r");
  int k = 10;
  int array[k][k];
  // Check if this filePointer is null 
  // which maybe if the file does not exist 
  if (filePointer == NULL) {
    printf("test.csv file failed to open.");
  } else {

    printf("The file is now opened.\n");
    int count = 0;

    while (fgets(dataToBeRead, 50, filePointer) != NULL) {
      if (count == 0) {
        // First line of csv contains total number of nodes
        k = atoi(dataToBeRead);
      } else {
        int j = 0;
        int length = (int) strlen(dataToBeRead);
        int kk = 0;

        for (int i = 0; i < length - 1; i++) {
          if (dataToBeRead[i] != ',') {
            kk = kk * 10 + (dataToBeRead[i] - '0');

          } else {
            array[count - 1][j] = kk;
            printf("%d \n", kk);
            kk = 0;
            j++;

          }
        }
        array[count - 1][j] = kk;
        printf("%d \n", kk);
        printf("\n");

      }
      count++;
    }

    // Closing the file using fclose() 
    fclose(filePointer);

    printf("Data successfully read from file GfgTest.c\n");
    printf("The file is now closed.\n");

    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        printf("%d ", array[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}

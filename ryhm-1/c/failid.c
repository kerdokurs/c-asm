#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // Try to open file
  FILE *fp = fopen("test.txt", "r");
  long size = 0;
  
  // Check if file was opened
  if (fp != NULL)
  {
    // Go to end of file
    fseek(fp, 0, SEEK_END);
    // Get current position (it's the length of the file)
    size = ftell(fp);
    // Go back to start of file
    fseek(fp, 0, SEEK_SET); // alternatiiv: rewind(fp);

    // Allocate buffer to read file contents to
    char *buffer = malloc(size * sizeof(char));

    if (buffer != NULL)
    {
      // Read to buffer
      size_t amt_read = fread(buffer, sizeof(char), size, fp);

      // Check whether we read the same amount of elements
      if (amt_read != size)
      {
        printf("Read wrong amount of elements.\n");
      }

      printf("%s\n", buffer);

      // Free buffer
      free(buffer);
    }

    // Close file
    fclose(fp);
  }
  else
  {
    // File does not exist or was not opened
    printf("File not opened.\n");
  }
}

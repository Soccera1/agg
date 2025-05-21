// Made with GNU/Linux
#include <stdio.h>
#include <stdbool.h>
int main(void) {
  printf ("Hello World!\nThis is a game written for AgnoxGD.\nWould you like to see a tutorial\nType 1 for no, or 0 for yes.\n");
  int tempInput;
  bool tutorial;
  if (scanf ("%d", &tempInput) == 1) {
    tutorial = tempInput; }
  if (tutorial) {
    printf ("OK! Lets continue.\n");
  } else {
    printf ("TODO\n"); }
  return 0;
}

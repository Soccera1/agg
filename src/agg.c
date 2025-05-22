// Made with GNU/Linux
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
int main(void) {
  srand(time(NULL));
  printf ("Hello World!\nThis is a game written for AgnoxGD.\nWould you like to see a tutorial\nType 1 for no, or 0 for yes.\n");
  int tempInput;
  bool tutorial;
  if (scanf ("%d", &tempInput) == 1) {
    tutorial = tempInput; }
  if (tutorial) {
    printf ("OK! Lets continue.\n");
  } else {
    printf ("Welcome to Agg! This game tests your math skills against the clock.\n\nHow to Play:\n\n1.  Set Your Playtime: First, you'll decide how long you want to play by entering a duration in seconds.\n2.  Solve Math Problems: Once the game starts, you'll be presented with a series of random math problems: addition, division, subtraction, and multiplication. Your goal is to solve as many as you can before time runs out.\n3.  Enter Your Answer: After each problem, type your answer and press Enter. The game will immediately tell you if you're correct or incorrect.\n4.  Rack Up Points: For every correct answer, you'll earn a point. Your score will be tallied at the end.\n5.  Time's Up! The game ends automatically when your chosen playtime runs out. Good luck, and have fun!\n"); }

  int playtime;
  printf ("\nHow long would you like to play for? Answer in seconds.\n");
  scanf ("%d", &playtime);

  time_t unix_time;
  unix_time = time(NULL);
  int end_time = unix_time + playtime;

  int score = 0;
//  int qa;
//  int tl;
//  int st;
// I can't remember what the fuck these are for

  while (unix_time < end_time) {
    float num1 = rand() % 10 + 1;
    float num2 = rand() % 10 + 1;
    int type = rand() % 4 + 1;
    float result;
    float answer;

    // DEBUG
    printf("%g, %g and %d\n", num1, num2, type);

    if (type == 1) {
      printf ("Add %g and %g\n", num1, num2);
      result = num1 + num2;
      scanf ("%g", &answer);
      unix_time = time(NULL);
    } else if (type == 2) {
      printf ("Divide %g by %g\n", num1, num2);
      result = num1 / num2;
      scanf ("%g", &answer);
      unix_time = time(NULL);
    } else if (type == 3) {
      printf ("Subtract %g from %g\n", num2, num1);
      result = num1 - num2;
      scanf ("%g", &answer);
      unix_time = time(NULL);
    } else if (type == 4) {
      printf ("Multiply %g by %g\n", num1, num2);
      result = num1 * num2;
      scanf ("%g", &answer);
      unix_time = time(NULL);
    }

    if (result == answer) {
      printf ("Correct!\n");
      score++;
    } else {
      printf ("Incorrect!\n");
    }

    // DEBUG
    printf ("Result is %g\n", result);
  }

  printf ("Your score is %d!\n", score);

  return 0;
}

// Made with GNU/Linux
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isvalidnumber(char entered []) {
    int valid = 1;
    for (int i = 0; i < strlen(entered); i++) {
        switch (entered[i]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
        case '-':
            break;
        default:
            valid = 0;
            break;
        }
    }
    return valid;
}

int main(void) {

  srand(time(NULL));
  char input[2];
  int tempInput;
  char *username = getenv("USER");
  bool tutorial;
  printf ("Hello %s!\nThis is a game written for AgnoxGD.\nWould you like to see a tutorial\nType 1 for no, or 0 for yes.\n", username);
  scanf("%s", input);
  if (isvalidnumber(input)) {
    sscanf(input, "%d", &tempInput);
    tutorial = tempInput;
  } else {
    printf ("Error! An invalid character was entered.\n");
    exit(1);
  }
  if (tutorial) {
    printf ("OK! Lets continue.\n");
  } else {
    printf ("Welcome to Agg! This game tests your math skills against the clock.\n\nHow to Play:\n\n1.  Set Your Playtime: First, you'll decide how long you want to play by entering a duration in seconds.\n2.  Solve Math Problems: Once the game starts, you'll be presented with a series of random math problems: addition, division, subtraction, and multiplication. Your goal is to solve as many as you can before time runs out.\n3.  Enter Your Answer: After each problem, type your answer and press Enter. The game will immediately tell you if you're correct or incorrect.\n4.  Rack Up Points: For every correct answer, you'll earn a point. Your score will be tallied at the end.\n5.  Time's Up! The game ends automatically when your chosen playtime runs out. Good luck, and have fun!\n"); }

  int accuracytype;
  printf ("Would you like your accuracy as a float or as an int? Type 0 for float or 1 for int.\n");
  scanf ("%s", input);

  if (isvalidnumber(input)) {
    sscanf(input, "%d", &accuracytype);
    } else {
    printf ("Error! An invalid character was entered.\n");
    exit(1);
  }

  int playtime;
  printf ("\nHow long would you like to play for? Answer in seconds.\n");
  scanf ("%d", &playtime);

  int number_length;
  printf ("Please enter maximum possible number\n");
  scanf ("%d", & number_length);

  time_t unix_time;
  unix_time = time(NULL);
  int end_time = unix_time + playtime;

  int score = 0;
  int questioncount = 0;

  while (unix_time < end_time) {
    float num1 = rand() % number_length + 1;
    float num2 = rand() % number_length + 1;
    int type = rand() % 4 + 1;
    float result;
    float answer;
    char entered[20];

    // DEBUG
    //printf("%g, %g and %d\n", num1, num2, type);

    if (type == 1) {
      printf ("Add %g and %g\n", num1, num2);
      result = num1 + num2;
    } else if (type == 2) {
      printf ("Divide %g by %g\n", num1, num2);
      result = num1 / num2;
    } else if (type == 3) {
      printf ("Subtract %g from %g\n", num1, num2);
      result = num1 - num2;
    } else if (type == 4) {
      printf ("Multiply %g by %g\n", num1, num2);
      result = num1 * num2;
    }
    unix_time = time(NULL);
    questioncount++;

    scanf ("%s", entered);

    if (isvalidnumber(entered)) {
      sscanf (entered, "%g", &answer);
    } else {
      printf ("Error! An invalid character was entered.\n");
      exit (1);
    }

    if (result == answer) {
      printf ("Correct!\n");
      score++;
    } else {
      printf ("Incorrect! The correct answer is %g.\n", result);
    }

    // DEBUG
   // printf ("Result is %g\n", result);
  }

  float accuracy;

  accuracy = (float)score / questioncount * 100;

  printf ("Your score is %d!\n", score);
  if (score >= 1) {
    printf ("Great job, %s!\n", username);
  } else {
    printf ("Try again!, %s.\n", username);
  }
  if (accuracytype == 1) {
    printf ("You got an accuracy of %d%%!\n", (int)accuracy);
  } else {
    printf ("You got an accuracy of %g%%!\n", accuracy);
  }
  return 0;
}

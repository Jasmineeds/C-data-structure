#include <stdio.h>
#define SUBJECT 3
#define STUDENT 5

int main()
{
  int score[STUDENT][SUBJECT] = {{76, 73, 85}, {88, 84, 76}, {92, 82, 92}, {82, 91, 85}, {72, 74, 73}};
  int i, j;
  int sum = 0;
  int highest_student_index;
  double avg = 0, highest_avg = 0;

  // each student
  for (i = 0; i < STUDENT; i++)
  {
    printf("student %d\n", i + 1);

    // sum
    sum = 0;
    for (j = 0; j < SUBJECT; j++)
    {
      printf(" %d: %d\n", j + 1, score[i][j]);
      sum += score[i][j];
    }

    // avg
    avg = (double)sum / SUBJECT;
    if (highest_avg < avg)
    {
      highest_avg = avg;
      highest_student_index = i + 1;
    }

    // output
    printf(" sum: %d\n", sum);
    printf(" avg: %.2f\n", avg);
  }

  // total
  sum = 0;
  for (i = 0; i < STUDENT; i++)
  {
    for (j = 0; j < SUBJECT; j++)
    {
      sum += score[i][j];
    }
  }
  printf("total: %d, avg: %.2f\n", sum, (double)sum / (SUBJECT * STUDENT));
  printf("highest avg: student %d: %.2f\n", highest_student_index, highest_avg);

  return 0;
}
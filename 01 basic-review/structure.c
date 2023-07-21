#include <stdio.h>
#include <stdlib.h>
#define N 5

struct _student
{
  int math;
  int english;
  int computer;
};

typedef struct _student student;

int main()
{
  int i, j;
  double avg[3] = {0.0};
  student st[N];

  for (i = 0; i < N; i++)
  {
    scanf("%d", &st[i].math);
    scanf("%d", &st[i].english);
    scanf("%d", &st[i].computer);

    avg[0] += st[i].math;
    avg[1] += st[i].english;
    avg[2] += st[i].computer;
  }

  for (j = 0; j < 3; j++)
  {
    avg[j] /= N;
  }

  printf("%.2lf\n", avg[0]);
  printf("%.2lf\n", avg[1]);
  printf("%.2lf\n", avg[2]);

  return 0;
}

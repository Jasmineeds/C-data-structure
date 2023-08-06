#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void print(int n, int *p)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", p[i]);
  }
}

int main()
{
  int data[5] = {34, 12, 5, 66, 1};
  int i, j;
  int *min, *pos; // min 紀錄目前最小值的位置
  int n = 5;

  for (i = 0; i < n - 1; i++)
  {
    min = data + i; // min = data + i; 的寫法等同於 min = &data[i];，它表示 min 指標指向 data 數組中的第 i 個元素
    for (j = i + 1; j < n; j++)
    {
      pos = &data[j];
      if (*pos < *min)
        min = pos;
    }
    swap(&data[i], min);
  }
  print(n, data);
  return 0;
}

// 以下用數值來做，以上為用指標來做
// for(i=0; i<n-1; i++){
//   pos = i;
//   for(j=i+1; j<n; j++){
//     if(data[j] < data[pos])
//       pos = j;
//   }
//   swap(&data[i],&data[pos]);
// }
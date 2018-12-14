#include <ctime>
#include <iostream>

class InsertionSort
{
  public:
    InsertionSort(double* a, int size);
    ~InsertionSort();
    void sort(double* a, int size);

    int time;
    int timeStart;
};

InsertionSort::InsertionSort(double* a, int size)
{
  int timeStart = clock();
  sort(a, size);
}

InsertionSort::~InsertionSort()
{
  int timeEnd = clock();
  time = timeEnd - timeStart;
  time = ((float)time) / CLOCKS_PER_SEC;
  cout << "InsertionSort" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "It took " << time << endl << endl;
}

void InsertionSort::sort(double* a, int size)
{
  for(int i = 0; i < size; i++)
  {
    int x = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > x)
    {
      a[j+1] = a[j];
      j = j-1;
    }
    a[j+1] = x;
  }
}

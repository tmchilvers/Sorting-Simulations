#include <ctime>
#include <iostream>

class BubbleSort
{
  public:
    BubbleSort(double* a, int size);
    ~BubbleSort();
    void sort(double* a, int size);

    int time;
    int timeStart;
};

BubbleSort::BubbleSort(double* a, int size)
{
  int timeStart = clock();
  sort(a, size);
}

BubbleSort::~BubbleSort()
{
  int timeEnd = clock();
  time = timeEnd - timeStart;
  time = ((float)time) / CLOCKS_PER_SEC;
  cout << "BubbleSort" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "It took " << time << endl << endl;
}

void BubbleSort::sort(double* a, int size)
{
  for(int i = 0; i < size - 1; i++)
  {
    for(int j = 0; j < size - i - 1; j++)
    {
      if(a[j] > a[j+1])
      {
        double temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}

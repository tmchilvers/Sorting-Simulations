#include <ctime>
#include <iostream>

class SelectionSort
{
  public:
    SelectionSort(double* a, int size);
    ~SelectionSort();
    void sort(double* a, int size);

    int time;
    int timeStart;
};

SelectionSort::SelectionSort(double* a, int size)
{
  int timeStart = clock();
  sort(a, size);
}

SelectionSort::~SelectionSort()
{
  int timeEnd = clock();
  time = timeEnd - timeStart;
  time = ((float)time) / CLOCKS_PER_SEC;
  cout << "SelectionSort" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "It took " << time << endl << endl;
}

void SelectionSort::sort(double* a, int size)
{
  for(int i = 0; i < size - 1; i++)
  {
    int min = i;
    for(int j = i+1; j < size; j++)
    {
      if(a[j] < a[min])
      {
        min = j;
      }
    }
    double temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
}

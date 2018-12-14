#include <ctime>
#include <iostream>

using namespace std;

class QuickSort
{
  public:
    QuickSort(double* a, int l, int h);
    ~QuickSort();
    void sort(double* a, int l, int h);
    int partition(double* a, int l, int h);

    int time;
    int timeStart;
};

QuickSort::QuickSort(double* a, int l, int h)
{

  int timeStart = clock();
  sort(a, l, h);
}

QuickSort::~QuickSort()
{
  int timeEnd = clock();
  time = timeEnd - timeStart;
  double timeFinal = ((float)time) / CLOCKS_PER_SEC;
  cout << "QuickSort" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "It took " << time << endl << endl;
}

void QuickSort::sort(double* a, int l, int h)
{
  if(l < h)
  {
    int p = partition(a, l, h);

    sort(a, l, p - 1);
    sort(a, p + 1, h);
  }
}

int QuickSort::partition(double* a, int l, int h)
{
  double pivot = a[h];
  int i = (l - 1);

  for(int j = l; j <= h-1; j++)
  {
    if(a[j] <= pivot)
    {
      i++;
      double temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  double temp = a[i+1];
  a[i+1] = a[h];
  a[h] = temp;

  return i + 1;
}

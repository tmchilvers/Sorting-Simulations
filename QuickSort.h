#include <chrono>
#include <ratio>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

class QuickSort
{
  public:
    QuickSort(double* a, int l, int h);
    ~QuickSort();
    void sort(double* a, int l, int h);
    int partition(double* a, int l, int h);

};

QuickSort::QuickSort(double* a, int l, int h)
{
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  sort(a, l, h);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "QuickSort\nTime: " << time_span.count() << " seconds.\n" << endl;
}

QuickSort::~QuickSort()
{

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

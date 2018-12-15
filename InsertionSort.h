#include <chrono>
#include <ratio>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

class InsertionSort
{
  public:
    InsertionSort(double* a, int size);
    ~InsertionSort();
    void sort(double* a, int size);

};

InsertionSort::InsertionSort(double* a, int size)
{
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  sort(a, size);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "InsertionSort\nTime: " << time_span.count() << " seconds.\n" << endl;
}

InsertionSort::~InsertionSort()
{

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

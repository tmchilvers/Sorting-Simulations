#include <chrono>
#include <ratio>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

class SelectionSort
{
  public:
    SelectionSort(double* a, int size);
    ~SelectionSort();
    void sort(double* a, int size);

};

SelectionSort::SelectionSort(double* a, int size)
{
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  sort(a, size);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "SelectionSort\nTime: " << time_span.count() << " seconds.\n" << endl;
}

SelectionSort::~SelectionSort()
{

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

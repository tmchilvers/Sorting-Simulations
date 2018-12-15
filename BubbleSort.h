#include <chrono>
#include <ratio>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

class BubbleSort
{
  public:
    BubbleSort(double* a, int size);
    ~BubbleSort();
    void sort(double* a, int size);

};

BubbleSort::BubbleSort(double* a, int size)
{
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  sort(a, size);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "BubbleSort\nTime:  " << time_span.count() << " seconds.\n" << endl;
}

BubbleSort::~BubbleSort()
{

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

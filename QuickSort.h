#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <ctime>
using namespace std;

//template class================================================================
template <class T>
class QuickSort
{
  public:
    QuickSort(T array[]);
    ~QuickSort();

    void sort();
    double getDuration();

  private:
    double duration;
};

//template functions============================================================
template <class T>
QuickSort<T>::QuickSort(T array[])
{
  sort();
}

template <class T>
QuickSort<T>::~QuickSort()
{

}

template <class T>
void QuickSort<T>::sort()
{

}

template <class T>
double QuickSort<T>::getDuration()
{
  return duration;
}

#endif

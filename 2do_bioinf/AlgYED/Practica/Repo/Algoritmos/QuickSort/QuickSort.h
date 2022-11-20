#ifndef QUICKSORT_H
#define QUICKSORT_H

template <class Contenedor>void quickSortRecursivo(Contenedor &c,int low, int high)
{
    int i = low;
    int j = high;
    int pivot = c[(i + j) / 2];
    Contenedor temp;
    temp.resize(1);

    while (i <= j)
    {
        while (c[i] < pivot)
            i++;
        while (c[j] > pivot)
            j--;
        if (i <= j)
        {
            temp[0] = c[i];
            c[i] = c[j];
            c[j] = temp[0];
            i++;
            j--;
        }
    }
    if (j > low)
        quickSortRecursivo(c, low, j);
    if (i < high)
        quickSortRecursivo(c, i, high);
}

template <class Contenedor>void quickSort(Contenedor &c)
{
    int i = 0;
    int j = c.size();
    int pivot = c[(i + j) / 2];
    Contenedor temp;
    temp.resize(1);

    while (i <= j)
    {
        while (c[i] < pivot)
            i++;
        while (c[j] > pivot)
            j--;
        if (i <= j)
        {
            temp[0] = c[i];
            c[i] = c[j];
            c[j] = temp[0];
            i++;
            j--;
        }
    }
    if (j > 0)
        quickSortRecursivo(c, 0, j);
    if (i < (int)c.size())
        quickSortRecursivo(c, i, c.size());
}

#endif // QUICKSORT_H

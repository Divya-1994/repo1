#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void bubbleSort(int a[]);
void insertSort(int a[]);
void mergeSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void mySort(int a[]);
void fillRandom(int a[]);
void check(int a[]);

int N = 0; // Global for array size

int main(int argc, char *argv[])
{
    int a[N];                                     // array to sort , N < a million
    struct timeval t;                             // for timing the sorts
    int starttime, endtime, starttime1, endtime1; // for timing the sorts
    float timesec, timeusec, totaltime;

    N = atoi(argv[1]); // set size of array

    // Time a bubble sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    starttime1 = t.tv_usec;
    bubbleSort(a);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    endtime1 = t.tv_usec;
    timesec = endtime - starttime;
    timeusec = endtime1 - starttime1;
    totaltime = timesec + (timeusec * 0.000001);
    printf("Bubble Sort time = %f", totaltime);
    check(a);

    // Time an insertion sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    starttime1 = t.tv_usec;
    insertSort(a);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    endtime1 = t.tv_usec;
    timesec = endtime - starttime;
    timeusec = endtime1 - starttime1;
    totaltime = timesec + (timeusec * 0.000001);
    printf("Insertion Sort time = %f", totaltime);
    check(a);

    // Time a merge sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    starttime1 = t.tv_usec;
    mergeSort(a, 0, N - 1);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    endtime1 = t.tv_usec;
    timesec = endtime - starttime;
    timeusec = endtime1 - starttime1;
    totaltime = timesec + (timeusec * 0.000001);
    printf("Merge Sort time = %f", totaltime);
    check(a);

    // Time a "my" sort
    fillRandom(a);
    gettimeofday(&t, NULL);
    starttime = t.tv_sec;
    starttime1 = t.tv_usec;
    mySort(a);
    gettimeofday(&t, NULL);
    endtime = t.tv_sec;
    endtime1 = t.tv_usec;
    timesec = endtime - starttime;
    timeusec = endtime1 - starttime1;
    totaltime = timesec + (timeusec * 0.000001);
    printf("MySort time = %f", totaltime);
    check(a);

    return 0;
}

void bubbleSort(int a[])
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    /*
		for(int i=0; i<N; i++)
		{
			printf("%d\n",a[i]);
		}
		*/
    return;
}

void insertSort(int a[])
{
    int key, j;
    for (int i = 1; i < N; i++)
    {
        key = a[i]; //take value
        j = i;
        while (j > 0 && a[j - 1] > key)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = key; //insert in right place
    }
    /*
   		for(int i=0; i<N; i++)
		{
			printf("%d\n",a[i]);
		}
		*/
    return;
}

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }

    return;
}

void mySort(int a[])
{
}

void fillRandom(int a[])
{
    for (int i = 0; i < N; i++)
    {
        a[i] = rand();
        //	printf("%d\n",a[i]);
    }
    //	printf("\n");
    return;
}

void check(int a[])
{
    for (int i = 0; i < N - 1; i++)
        if (a[i] > a[i + 1])
        {
            printf("Failed to sort. See item : %d \n\n", i);
            return;
        }
    printf("Check passed \n\n");
}

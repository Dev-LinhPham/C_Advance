#include <stdio.h>
#include <stdlib.h>

/*
    Sắp xếp phần tử trong mảng theo thử tự tăng dần, giảm dần
*/

/*
    Ứng dụng thuật toán sắp xếp chèn
*/

void nhapMang(int *lenght, int **pptr)
{
    *pptr = (int *)malloc(*lenght * sizeof(int));
    do
    {
        printf("Nhap so phan tu: ");
        scanf("%d", lenght);
    } while (*lenght < 1);
    for (int i = 0; i < *lenght; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", (*pptr + i));
    }
}

void xuatMang(int length, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        printf("\t%d", arr[i]);
    }
}

void tangDan(int length, int arr[])
{
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("\nMang sau khi sap xep: ");
    xuatMang(length,arr);
}

void giamDan(int length, int arr[])
{
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("\nMang sau khi sap xep: ");
    xuatMang(length,arr);
}


int main(int argc, char const *argv[])
{
    int *arr;
    int length;
    nhapMang(&length, &arr);
    printf("\nMang: ");
    xuatMang(length, arr);
    tangDan(length,arr);
    giamDan(length,arr);
    return 0;
}

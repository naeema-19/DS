#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);
void mergesort(int[],int,int);
void merge(int[],int,int,int,int);
void create (int[]);
void down_adjust(int[],int);
void heapSort();
void quick_sort(int a[100],int l,int u)
{
int j;
if(l<u)
{
j=partition(a,l,u);
quick_sort(a,l,j-1);
quick_sort(a,j+1,u);
}
}
int partition(int a[100],int l,int u)
{
int v,i,j,temp;
v=a[l];
i=l;
j=u+1;
do
{
do
{
i++;
}while(a[i]<v&&i<=u);
do
{
j--;
}while(a[j]>v);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l]=a[j];
a[j]=v;
return(j);
}

void mergesort(int a[100],int i, int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
mergesort(a,i,mid);
mergesort(a,mid+1,j);
merge(a,i,mid,mid+1,j);
}
}
void merge(int a[100],int i1,int j1, int i2,int j2)
{
int temp[100];
int i,j,k;
i=i1;
j=i2;
k=0;
while(i<=j1&&j<=j2)
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=j1)
temp[k++]=a[i++];
while(j<=j2)
temp[k++]=a[j++];
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}
void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}    
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  
/* function to print the array elements */  
void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }  
          
}  

void main()
{
int a[100],n,i,op;
printf("Enter no of elements\n");
       scanf("%d",&n);
       printf("Enter the nos\n");
       for(i=0;i<=n-1;i++)
       scanf("%d",&a[i]);
do
{
printf("\n1.Quick sort\n2.Merge sort\n3.Heap sort\n4.Exit\n");
scanf("%d",&op);
switch(op)
{
case 1:
       quick_sort(a,0,n-1);
       printf("sorted array is\n");
       for(i=0;i<=n-1;i++)
       printf("%d ",a[i]);
       break;
case 2:
       mergesort(a,0,n-1);
       printf("sorted array is\n");
       for(i=0;i<=n-1;i++)
       printf("%d ",a[i]);
       break;
case 3:
       heapSort(a,n);
       printf("sorted array is\n");
       printArr(a, n);
       break;
case 4:exit(0);
default:printf("Invalid Choice\n");
}
}while(op !=4 );
}

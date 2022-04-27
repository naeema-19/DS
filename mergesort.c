#include <stdio.h>

merge(int a[25], int beg,int mid, int end)
{
    int i,j,k;

    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int la[n1],ra[n2];
    for(i=0;i<n1;i++)
    {
        la[i]=a[beg+i];
    }
    for(j=0;j<n2;j++)
    {
        ra[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=beg;
    while(i<n1 && j<n2)
    {
        if(la[i]<=ra[j])
        {
           a[k] = la[i];
           i++;
        }
        else
        {
            a[k] = ra[j];
            j++;
        }
        k++;

    }
    while(i<n1)
    {
       a[k]=la[i];
       i++;
       k++;
    }
    while(j<n2)
    {
        a[k]=ra[j];
        j++;
        k++;
    }

}

mergesort(int a[25], int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid = (beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

int main()
{
    int a[25],n;
    printf("Enter the count of numbers  :  ");
    scanf("%i",&n);

    printf("\nEnter the %i numbers : ",n);
    for(int k=0;k<n;k++)
    {
        scanf("%i",&a[k]);
    }
    mergesort(a,0,n-1);
    printf("\nSorted Elements : ");
    for(int k=0;k<n;k++)
    {
        printf("%i ",a[k]);
    }
}

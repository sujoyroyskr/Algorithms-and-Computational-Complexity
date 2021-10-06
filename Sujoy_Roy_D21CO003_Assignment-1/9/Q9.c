#include <stdio.h>
#include<time.h>

struct timeval{
    long tvsec;
    long tvusec;
};


void bubbleSort (int a[]);
void insertSort(int a[]);
void mergeSort(int a[],int l,int r);
void mySort(int a[]);
void fillRandom(int a[]);
void check(int a[]);

int N;

int main()
{
    scanf("%d",&N);
	int a[N]; 
    struct timeval t; 
    int starttime,endtime; 
    //N=atoi(argv[1]);

    //printf("%d",1);
    fillRandom(a);
    gettimeofday(&t,NULL);
    starttime=t.tvsec;
    bubbleSort(a);
    gettimeofday(&t,NULL);
    endtime=t.tvsec;
    printf("Bubble Sort time = %f%d%d" , ( endtime-starttime)) ;
    check(a);

    fillRandom(a);
    gettimeofday(&t,NULL);
    starttime = t.tvsec;
    insertSort(a);
    gettimeofday(&t,NULL);
    endtime = t.tvsec;
    printf("Insertion Sort time = %f%d%d" , ( endtime-starttime));
    check(a);

    fillRandom(a);
    gettimeofday(&t,NULL);
    starttime = t.tvsec;
    mergeSort(a,0,N);
    gettimeofday(&t,NULL) ;
    endtime = t.tvsec;
    printf("Merge Sort time = %f%d%d" , (endtime-starttime)) ;
    check(a) ;

    fillRandom(a);
    gettimeofday(&t,NULL);
    starttime = t.tvsec;
    mySort(a);
    gettimeofday(&t,NULL);
    endtime = t.tvsec;
    printf("MySort time = %f%d%d" , (endtime-starttime)) ;
    check(a);
    
    return 0;
}

void bubbleSort(int a[])
{
for(int i = 0 ; i <= N; i++)
    {
    for(int j = 0 ; j < N-1; j++)
    {
    if(a[j] > a[j+1])
    {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
    }
    }
    }
    return ;
}

void insertSort(int arr[]) 
{ 
    int i, key, j; 
    for (i = 1; i < N; i++) { 
        key = arr[i]; 
        j = i - 1; 
        
        while(j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void mergeSort(int a[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        
        mergeSort(a, l, m); 
        mergeSort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 
}

void merge(int a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
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

void mySort(int a[])
{
    int i, j, min_idx,tmp; 
  
     
    for (i = 0; i < N-1; i++) 
    { 
         
        min_idx = i; 
        for (j = i+1; j < N; j++) {
          if (a[j] < a[min_idx]) 
            min_idx = j; 
        }
  
        tmp=a[min_idx];
        a[min_idx]=a[i];
        a[i]=tmp;
    } 
}



void fillRandom(int a[])
{
    for(int i = 0 ; i < N; i++)
    {
    a[i]=rand();
    }
    return ;
}

void check(int a[])
{
for(int i = 0 ; i < N-1; i++)
    if(a[i] > a[i+1])
    {
    printf("Failed to sort. See item : %d \n\n",i);
    return;
    }
printf("\nCheck passed \n\n");
}
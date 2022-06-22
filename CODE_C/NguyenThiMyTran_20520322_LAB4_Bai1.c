#include <stdio.h>

 

// Ham swap hai gia tri a va b

void swap (int *a ,int *b)

{

       int temp = *a;

       *a = *b;

       *b = temp;

}

 

// Xoa a[cu] va them vao vi tri moi trong mang a[moi]

void deleteThenInsert(int a[], int n, int cu, int moi)

{

       int temp = a[cu];

       if(cu < 0 || moi < 0 || cu >=n || moi >= n || moi == cu)

              return;

       else if(moi < cu)

       {            

              for(int i = cu; i > moi; i--)

                     a[i] = a[i-1];

              a[moi] = temp;

       }

       else

       {

              for(int i = cu; i < moi; i++)

                     a[i] = a[i+1];

              a[moi] = temp;

       }

}

 

// Vi tri i dau tien trong mang a ma a[i] nho nhat (start <= i <= end)

int minAtIndex(int a[], int n, int start, int end)

{

       if( start > end || start < 0 || end >= n)

              return -1;

       int index = start;

       for(int i = start + 1; i <= end; i++)

              if(a[i] < a[index])

                     index = i;

       return index;

}

 

void main(){

       /* arr for arrival time, bur for burst time, star for start time, finish for finish time, tat for turnaround time, wt for waiting time, average wating time and average turnaround time*/

       int pn[20], arr[20], bur[20], star[20], finish[20], tat[20], wt[20], i, j, k, n;

       int totwt = 0, tottat = 0;

       float awt, atat;

 

       // Nhap so process, ten process, arrival time, burst time

       printf("Enter the number of processes: ");

       scanf("%d", &n);

 

       for(i = 0; i < n; i++) {

              printf("Enter the Process Name, Arrival Time & Burst Time: ");

              scanf("%d%d%d", &pn[i], &arr[i], &bur[i]);

       }

 

       // Sap xep lai cac process theo arrival time tang dan

       for(i = 0; i < n - 1; i++)

              for(j = i + 1; j < n; j++)

                     if(arr[i] > arr[j])

                     {

                            swap(&arr[i], &arr[j]);

                            swap(&bur[i], &bur[j]);

                            swap(&pn[i], &pn[j]);

                     }

      

       // Tim process co burst time va arrival time nho nhat

       // Tim vi tri i sao cho arr[i] > arr[0]

       i = 1;

       while(i < n  && arr[i] == arr[0])

                     i++;

 

       // vi tri cua pn thoa bur be nhat trong [0, i]

       j = minAtIndex(bur, n, 0, i - 1);

      

       // Đưa process thứ j lên chạy đầu tiên

       if(j != 0)

       {

              deleteThenInsert(arr, n, j, 0);

              deleteThenInsert(bur, n, j, 0);

              deleteThenInsert(pn, n, j, 0);

       }

       /* Calculate start time, waiting time, finish time, turnaround time cua moi process */

       // Process chay dau tien

       star[0] = arr[0];

       wt[0] = 0;

       finish[0] = star[0] + bur[0];

       tat[0] = finish[0] - arr[0];

      

       // Process chay tu thu 2 tro di

       for(k = 1; k < n; k++) {

              if(arr[k] > finish[k - 1])

              {

                     i = k + 1;

                     while(i < n && arr[i] == arr[k])

                            i++;

 

       // vi tri cua pn thoa bur be nhat

                     j = minAtIndex(bur, n, k, i - 1);

 

                     if(j != k)

                     {

                            deleteThenInsert(arr, n, j, k);

                            deleteThenInsert(bur, n, j, k);

                            deleteThenInsert(pn, n, j, k);

                     }

                     star[k] = arr[k];          

              }

              else

              {

                     i = k + 1;

                     while(i < n && arr[i] <= finish[k - 1])

                            i++;

                     j = minAtIndex(bur, n, k, i - 1);

                     if(j != k)

                     {

                            deleteThenInsert(arr, n, j, k);

                            deleteThenInsert(bur, n, j, k);

                            deleteThenInsert(pn, n, j, k);

                     }

                     star[k] = finish[k-1];

              }

              finish[k] = star[k] + bur[k];

              wt[k] = star[k] - arr[k];

              tat[k] = finish[k] - star[k];

       }

 

       // In ra man hinh

      printf("\nPName\tArrtime\tBurtime\tStart\tFinish\tTAT\tWT");

       for(i = 0; i < n; i++) {

              printf("\n%5d\t%7d\t%7d\t%5d\t%6d\t%3d\t%2d", pn[i], arr[i], bur[i], star[i], finish[i], tat[i], wt[i]);

       // total waiting time va total turnaround time

              totwt += wt[i];

              tottat += tat[i];

       }

      

       // Calculate and Print average wating time va average turnaround time

       awt = (float)totwt / n;

       atat = (float)tottat / n;

 

       printf("\n\nAverage waiting time la: %f\n", awt);

       printf("Average turnaround time la: %f\n", atat);

}


	
	
	


#include<stdio.h>

int OTP(int a[50], int frames[5], int pos, int frame, int n)

{

 

     int flag[5] = { 0,0,0,0,0 };

     int i = pos + 1;

     for (i; i < n; i++)

     {

          int t = 0;

          for (t = 0; t < frame; t++)

 

               if (frames[t] == a[i])

                    flag[t] = 1;

 

          int count = 0;

          for (t = 0; t < frame; t++)

               if (flag[t] == 1)

                    count++;

 

          if (count == frame)

          {

               int f = 0;

               for (f; f < frame; f++)

                    if (frames[f] == a[i])

                         return f;

          }

          if (i == n - 1)

          {

               int i = 0;

               for (i; i < frame; i++)

                    if (flag[i] == 0)

                         return i;

          }

         

 

     }

}

int IsExist(int a, int temp[50], int index)

{

     int i = 0;

     for (i; i < index; i++)

          if (a == temp[i])

               return 1; //true 1

     return 0;//false 0

}

 

int LRU(int a[50], int frames[5], int pos, int frame, int n)

{

     int temp[50];

     int j = 0;

     int i = pos - 1;

     for (i; i >= 0; i--)

     {

          if (j == 0)

          {

               temp[j] = a[i];

               j++;

          }

          else

          {

               if (IsExist(a[i], temp, j) == 0)

               {

                    temp[j] = a[i];

                    j++;

               }

               if (j == frame)

               {

                    int t = 0;

                    for (t; t < frame; t++)

                         if (frames[t] == a[i])

                              return t;

               }

 

          }

     }

}

int ChuoiMacDinh(int a[50])

{

     int n;

     n = 20;

     int b[20] = { 1,7,5,2,0,8,6,7,0,0,7 };

     int i = 0;

     for (i; i < n; i++)

          a[i] = b[i];

     return n;

}

 

int ChuoiThamChieuNhapBangTay(int a[50])

{

     int n;

     printf(" \nNhập số phần tử chuỗi tham chiếu: \n");

     scanf("%d", &n);

     printf(" \nNhập vào chuỗi tham chiếu: \n");

     int i = 0;

     for (i; i < n; i++)

          scanf("%d", &a[i]);

     return n;

 

}

int main()

{

     int i, j, n, a[50], frames[5], frame, k, available, count = 0;

 

 

     int input;

     printf("---- - Page Replacement algorithm---- -\n");

     printf("1. Chuỗi tham chiếu mặc định.\n");

     printf("2. Nhập chuỗi tham chiếu bằng tay.\n");

     scanf("%d", &input);

 

     if (input == 1)

          n = ChuoiMacDinh(a);

     if (input == 2)

          n = ChuoiThamChieuNhapBangTay(a);

 

     printf("\nNhập vào số khung trang :\n");

     scanf("%d", &frame);

     int y = 0;

     for (y; y < frame; y++)

          frames[y] = -1; // Giả sử ban đầu các frame trống

     printf("------Page Replacement algorithm-----\n");

     printf("1. Giải thuật FIFO\n");

     printf("2. Giải thuật OPT(optimal)\n");

     printf("3. Giải thuật LRU\n");

     int choose;

     scanf("%d", &choose);

     if (choose == 1)

          printf("---FIFO Page Replacement algorithm---\n");

     if (choose == 2)

          printf("------OTP Page Replacement algorithm-----\n");

     if (choose == 3)

          printf("------LRU Page Replacement algorithm-----\n");

 

 

     j = 0;

     printf("\t|Chuỗi|\t|Khung trang");

     for (k = 0; k < frame - 1; k++)

          printf("\t");

     printf("|\n");

 

     for (i = 0; i < n; i++)

     {

          printf("\t|  %d  |\t", a[i]);

          available = 0; // trang không có sẵn

          for (k = 0; k < frame; k++)

               if (frames[k] == a[i]) // kiểm tra trang có sẵn

                    available = 1; // trang có sẵn

          if (available == 0) // thay thế trang nếu không có sẵn

          {

               if (choose == 1)

               {

                    frames[j] = a[i];

                    j = (j + 1) % frame;

 

               }

               else if (choose == 2)

               {

                    if (i < frame)

                    {

                         frames[j] = a[i];

                         j++;

                    }

                    else

                         frames[OTP(a, frames, i, frame, n)] = a[i];

               }

               else if (choose == 3)

               {

                    if (i < frame)

                    {

                         frames[j] = a[i];

                         j++;

                    }

                    else

                         frames[LRU(a, frames, i, frame, n)] = a[i];

               }

 

 

               count++;

               printf("|");

               for (k = 0; k < frame; k++)

                    printf("%d\t", frames[k]);

               printf("| F"); // Dấu hiệu nhận biết xảy ra lỗi trang

          }

          else

          {

               printf("|");

               for (k = 0; k < frame; k++)

                    printf("%d\t", frames[k]);

               printf("|");

          }

          printf("\n");

     }

     printf("Số trang lỗi là: %d\n", count);

    

     return 0;

}

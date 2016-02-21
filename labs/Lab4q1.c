#include <stdio.h>
int main()
{
   int row, col, c, d, matrix1[10][10], matrix2[10][10], sum[10][10];
   printf("Enter the number of rows and columns of the matrix\n");
   scanf("%d%d", &row, &col);
   printf("Enter the first matrix\n");
   for ( c = 0 ; c < row ; c++ )
      for ( d = 0 ; d < col ; d++ )
         scanf("%d", &matrix1[c][d]);
   printf("Enter the second matrix\n");
   for ( c = 0 ; c < row ; c++ )
      for ( d = 0 ; d < col ; d++ )
            scanf("%d", &matrix2[c][d]);
   for ( c = 0 ; c < row ; c++ )
      for ( d = 0 ; d < col ; d++ )
         sum[c][d] = matrix1[c][d] + matrix2[c][d];
   printf("Sum :\n");
   for ( c = 0 ; c < row ; c++ )
   {
      for ( d = 0 ; d < col ; d++ )
         printf("%d\t", sum[c][d]);
      printf("\n");
   }
   return 0;
}
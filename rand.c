   #include <stdio.h>
   main()
   {
   int i;
   for (i=0; i<5; i++)
     {
     printf("i=%d  ",i);
     fflush(stdout);
     sleep(1);
     }
}
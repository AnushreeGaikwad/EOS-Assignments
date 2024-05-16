#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
   int arr1[2], arr2[2], ret, s;
   int num[2];
   int res, sum, n1, n2;
   printf("Parent started:.....\n");
   ret = pipe(arr1);
   ret = pipe(arr2);
   if(ret < 0)
   {
     perror("pipe() failed");
	 _exit(1);
   }
   ret = fork();
   if(ret == 0)
   {
     close(arr1[0]);
	 close(arr2[1]);
	 printf("child: enter two numbers: ");
	 scanf("%d %d", &num[0], &num[1]);
	 ret = write(arr1[1], &num[0], sizeof(num[1]));
	 printf("child: data written in pipe: %d bytes\n", ret);
	 ret = write(arr1[1], &num[1], sizeof(num[1]));
	 printf("data written in pipe: %d bytes\n", ret);
	 read(arr2[0], &res, sizeof(res));
	 printf("result: %d\n", res);
	 close(arr2[0]);
	 close(arr1[1]);
  }
  else
  {
    close(arr1[1]);
	close(arr2[0]);
	printf("parent : waiting for data...\n");
	read(arr1[0], &n1, sizeof(n1));
	read(arr1[0], &n2, sizeof(n2));
	sum = n1 + n2;
	write(arr2[1], &sum, sizeof(sum));
	close(arr1[0]);
	close(arr2[1]);
	waitpid(-1, &s, 0);
	printf("Parent completed!\n");
  }
  return 0;
}








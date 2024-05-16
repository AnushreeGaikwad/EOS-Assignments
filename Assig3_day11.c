#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void sigint_handler(int sig)
{
  printf("signal caught: %d\n",sig);
  close(arr[1]);
  close(arr[0]);
  _exit(0);
 }
int main()
{
  int ret;
  char ch;
  char ch ='A';
  ret = pipe(arr);
  ret = sigaction(SIGINT, &sa, NULL);
  if(ret < 0)
  {
    perror("sigaction() failed");
	_exit(1);
  }
  int count = 0;
  while(1)
  {
    write(arr[1], &ch, 1);
	count++;
	print("bytes written : %d\n", count);
	}
	}

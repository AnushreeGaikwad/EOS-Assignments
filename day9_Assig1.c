#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  int ret, pid, sig;
  printf("Enter pid: ");
  scanf("%d", &pid);
  printf("Enter sig: ");
  scanf("%d",&sig);
  ret = kill(pid, sig);
  if(ret == 0)
  {
    printf("Signal is sent successfully");
  }
  else
  {
    printf("Signal is not sent successfully");
	}
	}

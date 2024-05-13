#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main()
{

int ret1,ret2,ret3,ret4,ret5 ,s, child_pid;
int i;
ret1 = fork();


if (ret1 == 0)
{
for(i=1 ; i<=10 ; i++)
{
printf("Child Process 1:%d\n",i);
}
exit(0);
}
ret2 = fork();
if (ret2 == 0)
  {
  for(i=1 ; i<=10 ; i++)
  {
  printf("Child Process 2:%d\n",i);
  }
  exit(0);
  }

  ret3 = fork();
  if (ret3 == 0)
    {
    for(i=1 ; i<=10 ; i++)
    {
    printf("Child Process 3:%d\n",i);
    }
    exit(0);
    }

ret4 = fork();
  if (ret4 == 0)
    {
    for(i=1 ; i<=10 ; i++)
    {
    printf("Child Process 4:%d\n",i);
    }
    exit(0);
    }
ret5 = fork();
  if (ret5 == 0)
    {
    for(i=1 ; i<=10 ; i++)
    {
    printf("Child Process 5:%d\n",i);
    }
    exit(0);
    }
for(i=1; i<=10; i++)
{
printf("parent: %d\n", i);
}

for(i=1; i<=5; i++)
{
child_pid = wait(&s);
printf("Child_Pid :%d\n",child_pid);
}
return 0;
}


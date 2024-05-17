#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
  int fd, n1, n2, ret;
  char str[32];
  fd = open("/home/anushree/Desktop/git/EOS-Assignments/temp/demo_fifo", O_WRONLY);
  if(fd < 0)
  {
    perror("open() failed");
	_exit(1);
  }
  printf("client: enter two numbers: ");
  scanf("%d %d", &n1, &n2);

  ret = write(fd,n1,sizeof(n1));
  printf("written in fifo: %d bytes\n", ret);
  ret = write(fd,n2,sizeof(n2));
  printf("written in fifo: %d bytes\n", ret);
  

  close(fd);
  return 0;
  }

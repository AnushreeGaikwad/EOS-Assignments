#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
  int fd, ret, n1, n2, sum;
  char str[32];
  fd = open("/home/anushree/Desktop/git/EOS-Assignments/temp/demo_fifo", O_RDONLY);
  if(fd < 0)
  {
    perror("open() failed");
	_exit(1);
  }

  printf("waiting for data...\n");
  ret = read(fd, n1 , sizeof(n1));
  printf("read from fifo: %d bytes --\n", ret);
  ret = read(fd, n2 , sizeof(n2));
  printf("read from fifo: %d bytes --\n", ret);
  sum = n1 + n2;
  ret = read(fd, sum, sizeof(sum));

  close(fd);
  return 0;
}

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void child()
{
  printf("I'm child. My pid is %d.\n", getpid());
  exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{
  printf("I'm child. My pid is %d, and my child's is %d.\n", getpid(), pid_c);
  exit(EXIT_SUCCESS);
}

int main(void)
{
  pid_t ret;
  ret = fork();
  if (ret == -1)
  {
    err(EXIT_FAILURE, "fork() failed.");
  }
  if (ret == 0)
  {
    child();
  }
  else
  {
    parent(ret);
  }
  err(EXIT_FAILURE, "Error occurred.");
}

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void child()
{
  char *args[] = {"/bin/echo", "hello", NULL};
  printf("I'm child. My pid is %d.\n", getpid());
  fflush(stdout);
  execve("/bin/echo", args, NULL);
  err(EXIT_FAILURE, "exec() failed.");
}

static void parent(pid_t pid_c)
{
  printf("I'm parent. My pid is %d, and my child's is %d.\n", getpid(), pid_c);
  exit(EXIT_SUCCESS);
}

int main(void)
{
  pid_t ret;
  ret = fork();
  if (ret == -1)
    err(EXIT_FAILURE, "fork() failed.");
  if (ret == 0)
  {
    child();
  }
  else
  {
    parent(ret);
  }
  err(EXIT_FAILURE, "shouldn't reach here.");
}

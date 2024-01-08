#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char buf[100];
  char* arg[32];
  char c;
  int i=0;
  int j=0;
  if (argc<2||argc>31)
  {
    fprintf(1,"xargs wrong arg count\n");
    exit(0);
  }
  for (j = 0; j < argc-1; j++)
  {
    arg[j]=argv[j+1];
  }
  arg[j]=buf;
  while (read(0,&c,1))
  {
    

    if (c=='\n')
    {
        buf[i]=0;

        i=0;
        if (fork()==0)
        {
            exec(argv[1],arg);
        }
        else
        {
            wait(0);
        }
        
        
    }
    else{
        buf[i++]=c;
    }
    
    
  }
  

  exit(0);
}

// int
//    main(int argc, char *argv[])
//    {
//     char buf[100];
//     char * arg[3];
//     arg[0]="echo";
//     arg[1]=buf;
//     arg[2] = 0;
//     buf[0]='1';
//     buf[1]='\n';
//     buf[2]='\0';
//     exec("echo",arg);
//     exit(0);
//    }
   
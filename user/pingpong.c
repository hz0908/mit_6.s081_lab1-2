// Simple ping pong

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
    int p[2];
    char buf[10];
    pipe(p);
    
    if (fork()==0)
    {
        int n;
        write(p[1],"ping",5);
        close(p[1]);

        n=read(p[0],buf,5);
        
        fprintf(1,"%d: received %s\n",getpid(),buf);
       
        if (n<0)
        {
            printf("wc: read error\n");
            exit(1);
        }
        
        

    }
    else
    {
        
        write(p[1],"pong",5);
        close(p[1]);
        read(p[0],buf,5);
        wait(0);
        fprintf(1,"%d: received %s\n",getpid(),buf);
    }
    
    exit(0);
}



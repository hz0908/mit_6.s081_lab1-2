// Simple ping pong

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


// void prime_mid(int send_num,int*pip,int fork_flag)
// {
    
//     if (fork_flag==0)
//     {
//         if(pipe(pip) < 0)
//         {
//             fprintf(2, "%s\n", "pipe error");
//             exit(1);
//         }
//         fprintf(1,"pipe:%d %d %d %d %d %d %d %d\n",pip[0],pip[1],pip[2],pip[3],pip[4],pip[5],pip[6],pip[7]);
//         fprintf(1,"pipeptr:%p\n",pip);
//         if(fork() == 0){
//             int p;
//             int n;
//             //close(0);
//             close(pip[1]);
//             read(pip[0],&p,4);
//             fprintf(1,"prime %d\n",p);
//             //close(1);
//             int fork_count=0;
//             while (read(pip[0],&n,4))
//             {
                
//                 if (n%p)
//                 {
//                     fprintf(1,"n:%d p:%d fork_count:%d\n",n,p,fork_count);
//                     prime_mid(n,pip+2,fork_count);
//                     fork_count=1;
//                 }
//                 //fprintf(1,"n:%d\n",n);
                
//             }
//             //fprintf(1,"exit:%d\n",n);
//             close(pip[0]);
//             close((pip+2)[1]);
//             fprintf(1,"closepipe:%d %d %d %d %d %d %d %d\n",pip[0],pip[1],pip[2],pip[3],pip[4],pip[5],pip[6],pip[7]);
//             wait(0);
//             exit(0);
            
//         }
//         else
//         {

//             close(pip[0]);
//             prime_mid(send_num,pip,1);
//             //wait(0);

//         }
//     }
//     else//if (fork_flag==0)
//     {
        
//         write(pip[1],&send_num,4);
//         close(pip[1]);
        
//         // if (send_num==35)
//         // {
//         //     close(pip[1]);
//         // }
//         // prime_mid(send_num+1,pip,1);
//     }
// }

void prime_mid(int send_num,int*pip,int fork_flag)
{
    
    if (fork_flag==0)
    {
        if(pipe(pip) < 0)
        {
            fprintf(2, "%s\n", "pipe error");
            exit(1);
        }
        
        if(fork() == 0){
            int p;
            int n;
            //close(0);
            close(pip[1]);
            read(pip[0],&p,4);
            fprintf(1,"prime %d\n",p);
            //close(1);
            int fork_count=0;
            //fprintf(1,"read%d\n",read(pip[0],&n,4));
            while (read(pip[0],&n,4))
            {
                
                if (n%p)
                {
                    //fprintf(1,"n:%d p:%d fork_count:%d\n",n,p,fork_count);
                    prime_mid(n,pip+2,fork_count);
                    fork_count=1;
                }
                
                
            }
            close(pip[0]);
            close((pip+2)[1]);
            wait(0);
            exit(0);
            
        }
        else
        {

            close(pip[0]);
            prime_mid(send_num,pip,1);
            //wait(0);

        }
    }
    else//if (fork_flag==0)
    {
        
        write(pip[1],&send_num,4);
        //close(pip[1]);
    
    }
}

int
main(int argc, char *argv[])
{   
    int p[70];
    prime_mid(2,p,0);
    for (int i = 3; i <= 35; i++)
    {
       prime_mid(i,p,1);
    }
    sleep(10);
    close(p[1]);
    wait(0);
    exit(0);
}



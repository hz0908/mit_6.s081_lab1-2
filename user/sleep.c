// Simple sleep

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{

  if(argc <= 1){
    fprintf(2, "usage: sleep pattern [tick_num]\n");
    exit(1);
  }
  sleep(atoi(argv[1]));
  exit(0);
}

// int
// main(int argc, char *argv[])
// {
//   int p[4];
//   if(argc <= 1){
//     fprintf(2, "usage: sleep pattern [tick_num]\n");
//     exit(1);
//   }
//   sleep(atoi(argv[1]));
//   pipe(p);
//   fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   pipe(p+2);
//   fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   exit(0);
// }

// void main(void)
// {
//   int p[4];
//   pipe(p);
//   fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   pipe(p);
//   fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   if (fork()==0)
//   {  
//      char buf[5];
//      pipe(p+2);
//      fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//      read(3,buf,5);
//      fprintf(1,"receive :%s\n",buf);
//   }
//   else
//   {
//     write(4,"ping",5);
//     close(4);
//     wait(0);
//   }
//   exit(0);
// }

// void main(void)
// {
//   int p[4];
//   pipe(p);
//   close(p[0]);
//   fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   pipe(p);
//   close(p[1]);
//   fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   // if (fork()==0)
//   // {  
//   //    char buf[5];
//   //    pipe(p+2);
//   //    fprintf(1,"%d %d %d %d\n",p[0],p[1],p[2],p[3]);
//   //    read(3,buf,5);
//   //    fprintf(1,"receive :%s\n",buf);
//   // }
//   // else
//   // {
//   //   write(4,"ping",5);
//   //   close(4);
//   //   wait(0);
//   // }
//   wait(0);
//   exit(0);
// }


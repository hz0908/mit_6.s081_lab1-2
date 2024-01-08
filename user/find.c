#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"


void
find(char *path,char *name)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;
  int offset=0;

  if((fd = open(path, 0)) < 0){
    fprintf(2, "find: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    fprintf(2, "find: cannot stat %s\n", path);
    close(fd);
    return;
  }

  switch(st.type){
  case T_FILE:
    fprintf(1,"the path should be a dir but not a file");
    break;

  case T_DIR:
    if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
      printf("find: path too long\n");
      break;
    }

    strcpy(buf, path);
    p = buf+strlen(buf);
    *p++ = '/';
 
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
      if(de.inum == 0||strcmp(".",de.name)==0||strcmp("..",de.name)==0)
        continue;
    
      memmove(p, de.name, strlen(de.name));
      offset=strlen(de.name);
      *(p+offset)=0;
      if (strcmp(de.name,name)==0)
      {
        fprintf(1,"%s\n",buf);
        continue;
      }
      
      
    
      if(stat(buf, &st) < 0){
        printf("find: cannot stat %s\n", buf);
        continue;
      }
      if (st.type==1)
      {
        find(buf,name);
      }
      
    }
    break;
  }
  close(fd);
}

int
main(int argc, char *argv[])
{


  if(argc < 3){
    fprintf(1,"wrong use of find, Format: find [path] [file name]\n");
    exit(0);
  }
  
    find(argv[1],argv[2]);
  exit(0);
}

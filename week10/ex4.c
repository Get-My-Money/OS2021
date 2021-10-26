#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>



char ls[200][200][200];
int lu[200];
int ino[200];

int main() 
{

  char path[100];
  DIR *td = opendir("tmp");
  int i = 0;
  while (i != 200){
    lu[i] = 0;
    ino[i] = -1;
  }



  struct dirent *m;
  while ((m = readdir(td)) != 0) {
    path[0] = '\0';
    strcat(path, "tmp/");
    strcat(path, m->d_name);    
    struct stat st;
     stat(path, &st);

    int inode = st.st_ino;
    int ind = -1;
    int i;
    for (i = 0; i < 200; i++) {
      if (ino[i] == inode) {
        ind = i;
        break;
      }

      if(ino[i] == -1)
        break;
    }

    if (i >= 200)
      break; 

    if (ind == -1) {
      ino[i] = inode;
      ind = ino[i];
	}	

    strcpy(ls[i][lu[i]], path);
    lu[i] += 1;

  }
  
  for (int i = 0; i < 200; i++) {
    if (lu[i] > 3) {
      for(int j = 0; j < lu[i]; j++){
        printf("%s\n", ls[i][j]);
      }
    }
  }
}
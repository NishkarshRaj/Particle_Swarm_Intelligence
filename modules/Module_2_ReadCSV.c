#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

   /* when return 1, scandir will put this dirent to the list */
   static int parse_ext(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) { /* only deal with regular file */
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           return 0;
         else {
           if(strcmp(ext, ".csv") == 0)
             return 1;
         }
     }

     return 0;
   }

   int main(void)
   {
       struct dirent **namelist;
       int n;

       n = scandir(".", &namelist, parse_ext, alphasort);
       if (n < 0) {
           perror("scandir");
           return 1;
       }
       else {
           while (n--) {
               printf("%s\n", namelist[n]->d_name);
               free(namelist[n]);
           }
           free(namelist);
       }

       return 0;
   }

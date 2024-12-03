#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
int main() { 
DIR *dir; 
struct dirent *x; 
dir = opendir("."); 
printf("Contents of directory:\n"); 
while ((x = readdir(dir)) != NULL) 
    printf("%s\n", x->d_name);  
closedir(dir); 
return 0; 
}

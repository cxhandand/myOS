#include<dirent.h>
#include<stdio.h>
#include<string.h>
#define MAX_BUFFER_SIZE 1024
struct file_struct
{
    char* name;
    char*ppid;
    char*pid;
    struct file_struct *next;
};

char* get_file(char *s)
{
    struct file_struct return_file_str;

char *path = s;
DIR *dir;
struct dirent *entry;
dir = opendir(path);
if (dir==NULL)
{
    printf("no such a file or cant open file\n");
}
else{
    
    struct file_struct* arr_str[400]=NULL;
    int i = 0;
    while ((entry=readdir(dir))!=NULL)
    {
        if (verify_number(entry->d_name))
        {   struct file_struct new_str;
            char* path_tmp = strcat(path,entry->d_name);
            path_tmp = strcat(path_tmp,"/status");
            FILE *file;
            char *line;
            file = fopen("path_tmp","r");
            for(int j = 1;j<8;j++)
            {   fgets(line,sizeof("1111111111"),file);
                if(j==1)
                {   
                    new_str.name = line;
                    continue;
                }
                else if (j==6)
                {
                    new_str.pid = line;
                    continue;
                }
                else if (j==7)
                {
                    new_str.ppid = line;
                    break;
                }
                j++;
                
            }
            arr_str[i] = &new_str;

        }
        
    }
    for(int i=0;i<400;i++)
    {   if(arr_str[i]!=NULL)

        printf("name=%s  pid=%s  ppid=%s",arr_str[i]->name,arr_str[i]->pid,arr_str[i]->ppid);
    }
    
}
closedir(dir);
return "ss";
}


int verify_number(char *s)
{
    if (s[0]>='0'||s[0]<='9')
        return 0;
    return 1;
}

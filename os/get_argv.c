#include<stdio.h>
#include<assert.h>
extern char* get_file();
int main(int argc,char *argv[])
{   int  mode =0;
    for (int i = 1;i<argc;i++){
        assert(argv[i]);
        if (argv[i][0]=='-')
        {
            switch (argv[i][1])
            {
            case  'h':
                mode = 1;
                break;
            
            default:
                break;
            }
        }
        
else
{
    printf("error\n");
}

    }
    assert(!argv[argc]);
    char *s = "/proc";
    get_file(s);
    return 0;
}

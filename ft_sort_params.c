#include <unistd.h>
int ft_strcmp(char *s1, char *s2) {
    int i = 0;
    while ((*s1 && *s2) && s1[i] == s2[i]) {
        i++;
    }
    
    return s1[i] - s2[i];
}

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    write(1, str,i);
    write(1, "\n",1);
}

int main(int arc,char *str[])
{
    int i , j; 
    char* tmp;
    if(arc < 2)
        return 0;

    i = 1;
    while(i < arc - 1)
    {  
        j = i + 1;
        while( j < arc)
        {
            if(ft_strcmp(str[i],str[j]) > 0)
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 1;
    while (i < arc) {
        ft_putstr(str[i]);
        i++;
    }

}    

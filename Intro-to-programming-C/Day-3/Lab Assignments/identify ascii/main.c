#include <stdio.h>
#include <stdlib.h>

int main()
{
 char ch;
    printf("Enter Key\n");
    ch=getche();

    if(ch==-32)
    {

        ch=getche();
        printf("Extended key with ascii = %i \n",ch);
    }
    else
    {

        printf("normal key with ascii = %i \n",ch);

    }


    return 0;
}

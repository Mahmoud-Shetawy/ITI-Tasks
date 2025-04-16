///getch(),getche(),getchar()
///Read character in runtime

///int x;
//scanf("%d",&x)?? No
///Running  23
//Temp Memory [Buffer]
//Read stream from user
//Enter =>take datafrom Buffer => Address of x
//scanf("%d",&x)   22
//buffer 4 Byte
//buffer 4Byte contains rubbish
//_Flushall();
//scanf("%c",&ch)
//Buffer temp memory 1 Byte
//take from rubbish and assign to ch
//read printed key
//read stream of character


///Program to know ascii decimal in PC
#include<stdio.h>
int main()
{
    ///Normal Key  Done !!!
    char ch;
    ch=getch();     //|M|
    printf("%c",ch); //M
    printf("%d",ch), //77
    return 0;
}

//////
///ASCII 
///Normal Key
///1 Byte
///8 bit
///0  => 127

////Keyboard Extended
///Extended ASCII Table
/// 2 Byte   ??? 1 byte   77 M   UpArrow   XXX
/// First Byte Always NULL
///Second Byte 0=>127
///  ===>  77   M
///  ===>  NULL 77  Up arrow

#include<stdio.h>

int main(){

    char ch;   //Stack   ch    1 byte
    ch=getch();    ///Up Arrow    Extended   NULL 77
    ///Buffer   2byte    |-32|77|     =>assign -32 into ch
    ///Buffer   |77|
    ///printf("%d",ch);   //NULL  => 0    -32  NULL
    ///Codeblocks 13.00   17.0   -32 ->NULL
    if(ch !=-32) //!=null  //Normal Key    ch=-32 NULL
    {
        printf("Normal Key =>%d \n",ch);
    }
    else
    {

        ch=getch();  //Pull 77 from second byte
        ///Discover Buffer |77|
        //Pull 77 from second byte  into ch
        //Read Again ???? NOOOOO
        ///Buffer already Contains 79
        printf("Extended Key =>%d \n",ch);
    }
    

    ///Run   Press M
    ///  Up Arrow  -32 79

    return 0;
}

////////////////////////////////////////////

///String
///Standard C there is no datatype names string
///regardless external libraries/Header Contain string data type
///   |A|H|M|E|D|
///Array of characters
///for(int ) modern C

char carr[20];   //Stack in memory 10* 1 Byte=10 Bytes


for(int i=0;i<5;i++)
{
    carr[i]=getche();
}

///output
///AHMEDBBBBB
///AHMED 

///For Loop In not suitable

//Loop Undefines Times
///Do while  , while
///ch=getch();   ///Enter  => normal key   13
///printf("%d",ch);//13
char carr[10];
char ch;
int x=0;   //1 2
//
while ((ch=getch())!=13)   //mohamed Enter
{
    carr[x]=ch;
    x++;
}//
carr[x]='\0';

// for(int j=0;j<10;j++)
// {
//     printf("%c",carr[j]);
// }

printf("%s",carr);
///Compiler will print untill it find '\0'

///   |m|o|h|a|m|e|d|\0|#|#|

///When to end Enter your string
///We put Null Terminator /Delimiter  '\0' to last index of written array


///O/P
//Mohamed
///Ahmed


char carr[7+1]={'m','s','s','s','s','s','s'};'\0'
char carr[8]="mohamed";

//String functions
//gets(array of char)
//puts(array of char)

char carr[10];
gets(carr);
//O/P  READ=> MOHAMEnter\0

puts(carr);
//Print Untill '\0'

///Function in 
//#include<string.h>


strcat(array of char,array of char);
strcpy(array of char,array of char);
strcmp(array of char,array of char);
strcmpi(array of char,array of char);

///Best Practice Concat in new size array of character size=
/// tottal of two sizes of char[]
strcat(left,right)  ,//Concatenate right into left
char fn[10]="AliALIALI";    |A|L|i|A|L|I|A|L|I|\0|
char ln[10]="OsamaOSMA";  |O|s|a|m|a|\0||||||
char full[21];
strcat(fn," "); |A|L|i|" "|||||||
strcat(fn,ln);  |A|L|i|" "|O|s|a|m|a|\0|
puts(fn);

strcat(full,fn); |A|L|i|" "|||||||
strcat(full," ");
strcat(full,ln);


strcpy(left,right)  //Overwrite right to left
char fn[10]="Ali";    |A|L|i|\0|||||||
char ln[10]="Osama";  |O|s|a|m|a|\0||||||
strcpy(fn,ln);

puts(fn); |O|s|a|m|a|\0||||||


int x=ctrcmp(left,right);   //Compare to strings

//
//Ali   Ali   =>return 0 ==
//Ahmed  Mohamed => -1  left<right   ASCII
//65      77

//Mohamed Ahmed  => 1  left>right
// 77     65

//Mohamed  mohamed  =>-1  
//77       109


//Ali  Aya    => Not 0   -1 

char fn[10]="Ahmed";
char ln[10] = "Mohamed";

printf("%d",strcmp(fn,ln));    ///-1

if (strcmp(fn,ln)==-1)
{
    Printf("Smaller")
}

strcmpi(fn,ln)   //I ignore case


char fn[10]=  "Ahmed";
char ln[10] = "ahmed";

printf("%d",strcmpi(fn,ln));    ///0 ==
printf("%d",strcmp(fn,ln));    ///-1 


//////////////////////////////////////////////////////////
//Highlighted menu


textattr(int colornum);  //1=>16 

int main()
{
    //Default pen color => White
    //printf("HELLOOOOOOOOOOOOO");
    textattr(9);//green
    textattr(10);//green
    textattr(11);//green
    printf("HELLOOOOOOOOOOOOO");
    //White
    textattr(12);//yellow
    _cprintf("HELLOOOOOOOOOOOOO");
    cprintf();
}





char menu[3][10]={"New","Display","Exit"};
//{{},{},{}}
int cursor=0;
|n|e|w||||||||         as "" index 0
|d|i|s|p|l|a|y||||           index 1
|e|x|i|t|||||||              index 2

printf("%s",menu[i])


#include<stdio.h>
//gotoxy
//textattr

#define up 77
#define down 80
#define enter 13
#define Extended -32
//up down home end extended
//enter esc tab normal
int main()
{
    char menu[3][10]={"New","Display","Exit"};
    int cursor=0;
    char ch;
    int flag=1;
//o/p  rednew   whiteDisplay  whiteExit
    do
    {
        system("cls");
        for(int i=0;i<3;i++)
        {
            if(i==cursor)
            {
                textattr(4);//red
            }
            else
            {
                textattr(15);//white
            }
            gotoxy(15,15+i*2);
            _cprintf("%s",menu[i]);
        }

        _flushall();
        ch=getch();  //up   |-32|77|   down#   Enter#
        switch (ch)
        {
            case Extended:
            //_flushall(); XXXXXX
                ch=getch();
                switch (ch)
                {
                    //case enter13:
                    //break;
                    case up:
                        cursor--;
                        if(cursor<0)
                        {
                            cursor=2;
                        }
                    break;
                    case down:
                        cursor++;  //1
                        if(cursor>2)
                        {
                            cursor=0;
                        }
                    break;
                    case home:
                        cursor=0;
                    break;
                    case end:
                        cursor=2;
                    break;
                }
            break;
            case enter:
                switch(cursor)  //0
                {
                    case 0:
                        system("cls");
                        printf("New Page");
                        getch(); //Wait until i press any key
                    break;
                    case 1:
                        system("cls");
                        printf("Display Page");
                        getch();
                    break;
                    case 2:
                        flag=2;
                    break;
                }
            break;
            case esc:
                flag=34;
            break;
            case tab:
                cursor++;
                if(cursor>2)
                {
                    cursor=0;   
                }
            break;
        }



    }while(flag==1);

    return 0;
}



///////////////////////////////////

///1-Read first name ,last name
///// then fill in container full name 
/////  and print it
//////strcat ,strcpy    fn[10]   ln[10]      fulln[21]
////// gets() puts()

///2- read string from user   array[50]
///   then print it reversly

    ///Enter message
        /// my name is alaa

        /// aala si eman ym

        ///same array


///3- program to identify key ASCII  normal/extended  + ASCII # 
///4- Highlighted menu


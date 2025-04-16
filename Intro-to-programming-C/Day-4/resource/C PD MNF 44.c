///getch() ,getche()   => getchar()
///extended keys
///string
///Highlighted Menu
/////////////////////////////////////////////////////////
//program to identify ascii for any key in keyboard
#include<stdio.h>
int main()
{
    char ch;

    printf("Enter any Key\n");
    scanf("%c",&ch);

    printf("Ascii is %i",ch);
    return 0;
}

//o/p
//enter key
//M  [Enter]
//Ascii is 77

//o/p 
//enter key
//[ENTER] nothing will be happened
//[ESC][Tab][Backspace] nothing will be happened

//with scanf ->
//you can get ascii for any printed key
//scanf is working after press [ENTER]

//is there any way to identify ascii for ANY KEY?
//  char getch(){}

//read one key from keyboard -printed or non printed-
//then it will return it automatically without press enter
//getch() doesnt print any key on o/p screen 
int main()
{
    char ch;

    printf("Enter any Key\n");
    ch=getch();

    printf("Ascii is %i",ch);
    return 0;
}

//o/p
//enter key
//ascii is 77

/////////////////////////////
//char getche() -> echo   -> [use with printed keys]
int main()
{
    char ch;

    printf("Enter any Key\n");
    ch=getche();

    printf("Ascii is %i",ch);
    return 0;
}

//o/p
//enter key
//m
//ascii is 109


///////////////////////////////////////////////////
//normal ascii   1B

//extended keys
//up down left right home end fn's insert delete

//extended ascii  so that normal ascii is FULL
//2 bytes  ALWAYS first byte is NULL

//Normal ASCII      |77|  M
//Extended ASCII    |NULL|88|

//When press [J]  -> Cpu recieve |71|
//when press [up] -> Cpu recieve |NULL|71|

////////////////////////////////////////////////
//use this program to identify ascii for extended keys also
int main()
{
    char ch;  //1B

    printf("Enter any Key\n");
    ch=getch();

    ch=getch();
    printf("Ascii is %i",ch);
    return 0;
}

//o/p
//enter key
//ascii is -32[NULL]


///////////////////////////////////////////
//program to identify ascii for any key normal or extended

int main()
{
    char ch;

    printf("Enter Key\n");
    ch=getch(); //Up Arrow

    if(ch==-32)
    {
        ch=getch(); //compiler will take another byte from buffer
        printf("Extended Ascii %i",ch);
    }
    else
    {
        printf("Normal Ascii %i",ch);
    }

    /////////////////////
    printf("Enter Key\n");
    ch=getch(); //Up Arrow
    switch(ch)
    {
        case -32:
        ch=getch();
        printf("Extended Ascii %i",ch);
        break;
        default:
        printf("Normal Ascii %i",ch);
        break;
    }

    return 0;
}
///////////////////////////////////////////////////////
//string
//there is no data type called string in c
//despite there are libraries that help with string <string.h>

//we can identify string by create array of characters


//Program to recieve name from user
#include<stdio.h>
int main()
{
    char carr[15];  //15*1B

    printf("Plz Enter Name\n");
    scanf("%c",carr);   

    printf("name is %c",carr[0]);
    printf("name is %c",carr[1]);
    printf("name is %c",carr[2]);

    return 0;
}
//o/p
//enter name
//Mohamed [ENTER]
//name is m
//name is #
//name is #

int main()
{
    char carr[15];
    printf("plz enter name\n");
    for(int i=0;i<15;i++)
    {
        scanf("%c",&carr[i]);
    }
    printf("name is\n");
    for(int i=0;i<15;i++)
    {
        printf("%c",carr[i]);
    }
    return 0;
}
//o/p
//plz enter name
//M[Enter]o[Enter]h[Enter]a[Enter]m[Enter]d[Enter][ENTER]
//name is
//mohamed###############


int main()
{
    char carr[15];
    char ch;
    printf("plz enter name\n");
    for(int i=0;i<15;i++)
    {
        ch=getch();
        carr[i]=ch;
    }
    printf("name is\n");
    for(int i=0;i<15;i++)
    {
        printf("%c",carr[i]);
    }
    return 0;
}

//o/p
//enter name
//mohamed[spaces]             
//name is 
//mohamed###########


/////////////////////////////////////////
//loop unspecific # of times [do while] [while]
//|'k'|'h'|'a'|'l'|'i'|'d'|'\0'|||||||||
//|a|l|i|'\0'||||||||||||
//|s|a|r|a|'\0'|||||||||||
//|g|e|h|a|d|'\0'||||||||||

//we need some how to know end of my string
//special character
//Delimeter [Null Terminator]
//'\0'
//you can put it at end of your string

/////////////////////////////////////////////////
int main()
{
    char carr[15];
    char ch;
    int i=0;
    printf("Enter name\n");
    do
    {
        ch=getch(); 
        carr[i]=ch;
        i++;
    }
    while(ch!=13);
    arr[i]='\0';


    return 0;
}


int main()
{
    char carr[15];
    char ch;
    int i=0;
    printf("Enter name\n");
   
    while((ch=getch())!=13)
    {
        carr[i]=ch;
        i++;
    }
    arr[i]='\0';


    //print name
    i=0;
    while (carr[i]!='\0')
    {
        printf("%c",carr[i]);
        i++;
    }

    //print v2
    printf("%s",carr); //print char by char untill \0
    
    return 0;
}


int main()
{
    char carr[15];

    printf("Enter name");
    scanf("%s",carr); //read characters untill press enter
    //when press enter compiler will put \0

    //o/p ????[ENTER]
    //|m|o|h|a|m|e|d|\0|||||||||
}

//////////////////////////////////////

#include<string.h>
int main()
{
    char carr[15];

    //gets(array of character);
    //read stream of character till press enter then it will put \0
    gets(carr);

    //puts(array of character)
    //print characters till \0
    puts(carr);
}
////////////////////////////////////////////////
//when declare array of character
//Always consider '\0' in declaration
//char fname[11+1];
//char lname[10+1]; 
///////////////////////////////////////////////
//default values of array of characters
int main()
{  
    char fname[11]={'a','l','i','\0'};
    char lname[12]={'a','b','d','e','l'...};
    char fullName[20]="AbdelRahman";
    //compiler will put char by char and put \0 at last

    //BIG COMPILE ERROR
    char name[10];
    name="Sara";
    //name itself always address fst element in array

    ///////////////////////////

    return 0;
}


int main()
{
    char names[3][20]={{'','','',''},{'','',''},{'','',''}};
    char names[3][20]={"Ali","Sara","Ahmed"};
    //names[0] //array of characters
    //names[0][0] //character

    scanf("%s",names);  //??? XXX
    scanf("%s",names[0]);  //T
    scanf("%c",&names[0][0]);  //T

    scanf("%s",names[0]);  //T
    gets(names[1]);
    gets(names[2]);

    puts(names[0]);
    puts(names[1]);
    puts(names[2]);
}

///////////////////////////////////////////////
//strcpy,strcat
#include<string.h>
int main()
{
    char fname[10]="Ali";
    char lname[10]="Ahmed"
    char fullName[21];

    //fullname=fname; //Address
    fullName[0]=fname[0];
    fullName[1]=fname[1];
    fullName[2]=fname[2];
    fullName[3]=' ';
    fullName[3]=lname[0];

    //strcpy(LArrayofChar,RArrayofChar);
    //strcat(LArrayofChar,RArrayofChar);
    strcpy(fullName,fname);
    strcat(fullName," ");
    strcat(fullName,lname);

    puts(fullName);

    return 0;
}

///////////////////////////////////////////////
//string.h Functions  -> srarch
{
    char arr[10]="33";
    ///string.h Functions
    //int strcmp(Array of Char,Array of Char);
    //int strcmpi(Array of Char,Array of Char);
    //int strlen(array of character); //till \0
    //int atoi(Array Of Char)
    //float atof(Array Of Char)
    //int x=atoi(arr);
}

////////////////////////////////////////////////
//Hilighted menu
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Extended -32
#define Enter 13
#define Esc 27
#define Home ??
#define end ??
#define up ??
#define down ??
void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
int main()
{
    char menu[4][10]={"File","New","Display","Exit"};
    int cursor=0;
    int flag=100;
    char ch;
    do
    {
        system("cls");//clear screen
        for(int i=0;i<4;i++)
        {
            if(cursor==i){textattr(3);}
            else{textattr(7);}
            gotoxy(10,10+i);
            _cprintf("%s",menu[i]);
        }
        //
        ch=getch();  //Enter   cursor 0
        switch(ch)
        {
            case Extended:
            ch=getch();
            switch(ch)
            {
                case up:
                cursor--;
                if(cursor<0){cursor=3;}
                break;
                case down:
                cursor++;
                if(cursor>3){cursor=0;}
                break;
                case Home:
                cursor=0;
                break;
                case end:
                cursor=3;
                break;
            }
            break;
            case Enter:
            switch(cursor)
            {
                case 0:
                system("cls");
                printf("File Page");
                getch(); //to make program wait [delay till enter]
                break;
                case 1:
                system("cls");
                printf("New Page");
                getch();
                break;
                case 2:
                system("cls");
                printf("Display Page");
                getch();
                break;
                case 3:
                flag=0;
                break;
            }
            break;
            case Esc:
            flag=0;
            break;
        }

    }
    while(flag==100);

    return 0;
}

//////////////////////////
//Skeleton

int main()
{
    do
    {
        //for
        //ch=getch();
        switch(ch)
        {
            case NULL:
            ch=getch();
            switch(ch)
            {
                case up:
                break;
            }
            break;
            case Enter:
            break;
            case esc:
            break;

        }
    }
    while();
}

//////////////////////////////////////////////////



///1-Read first name ,last name
///// then fill in container full name 
/////  and print it
//////strcat ,strcpy    fn[10]   ln[10]      fulln[21]
////// gets() puts()

///2- read string from user   char array[50]
///   then print it reversly
    //while(ch=getch()!=13){}  Do it with while and read character by character
    ///Enter message
        /// my name is Mohamed
        ///demahoM si eman ym


        ///same array
        ///do it ya Moustafa
        //afatsuoM ay ti od


///3- program to identify key ASCII  normal/extended  + ASCII # 

//up ex 71
//tab nr 44

///4- Highlighted menu
#define up 71

//write code fst time from your brain





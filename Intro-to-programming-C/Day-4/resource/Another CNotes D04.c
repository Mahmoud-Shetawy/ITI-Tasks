///getch() ,getche()   => getchar()
///extended keys
///string
///Highlighted Menu

///////////////////////////////////////////////////
#include<stdio.h>
int main()
{
    char ch;
    
    printf("Enter a character");
    scanf("%c",&ch);
    //get stream of printed character untill i press enter
    printf("You entered %c %d",ch,ch);

    return 0;
}
//o/p
//Enter a character
//Mvnfovjvsljsnvfdnvsjvnvs  Enter
//You entered M 77

///getch()  => get key from keyboard and returns character or ascii
///getch() get key you pressed automatically without press enter


#include<stdio.h>
int main()
{
    char ch;
    
    printf("Enter a character");
    ch=getch();
    
    printf("You entered %c %d",ch,ch);

    return 0;
}
//o/p
//Enter a character
//[press on M] [it will not be printed]

//Real o/p
//Enter Character  
//You Entered M 77


//
//getche() ==getch()
//echo
#include<stdio.h>
int main()
{
    char ch;
    
    printf("Enter a character");
    ch=getche();
    
    printf("You entered %c %d",ch,ch);

    return 0;
}
//Real o/p
//Enter Character 
//M 
//You Entered M 77


//////////////////////////////
//getch()==> take any key from keyboard  normal or extended
//////there are many keys in keyboard not printed  
/////Enter , Esc , tab ,backspace
////thery have ascii code only


///keyboard  => printed + nonprinted keys
///keyboard  => ascii

/////////////////////////////////////////////////////////
///ASCII table
/// 1 Byte

////before up,down,home,end ,f1,insert,delete

///revolution for keyboard
///Extended keys
//normal ascii if full !!!




///Ascii table => normal Ascii
//1 Byte
///Ascii table => Extended Ascii
//2 Byte
////     |NULL||

//if you press Enter   => 1 Byte   13  
//if you press Esc   => 1 Byte   27  
//if you press M   => 1 Byte   77  

////BUT

//if you press up   =>2bytes |NULL|72|
//if you press down   =>2bytes |NULL|80|

////////////////////////////////////////////////////////

//program key from keyboard and print ascii

//When Press Up Arrow
//Enter a character Press up    
//2byte  borlandc|NULL|77|  codeblocks|-32|72| 
//buffer store 2bytes |-32| + |72|

//Remain in buffer |72|


#include<stdio.h>
int main()
{
    char ch;
    
    printf("Enter a character");
    ch=getch();
    
    printf("You entered %d",ch);

    return 0;
}
//o/p
//Enter a character Press up    //2byte  borlandc|NULL|77|  codeblocks|-32|77| 
//You entered  -32

//Enter a character Press Esc
//You entered  27

//Enter a character Press Enter
//You entered  13

//Enter a character Press M
//You entered M 77



///////////////////////
///How to get asccii for extended key
#include<stdio.h>
int main()
{
    char ch;
    
    printf("Enter a character");
    _flushall();
    ch=getch();  //M => 1byte    //Up |-32|72| => ch=-32  => 72 remains in buffer
    
    if(ch!=-32)  //ch!=NULL
    {
        printf("Normal Key %d",ch);
    }
    else 
    {
        //_flushall(); //WRONG
        ch=getch(); //=> do nothing
        ///compiler will discover some number in buffer
        ///it will assign it automatically    72
        printf("Extended %d",ch);
    }
    return 0;
}

///////////////////////////////////////////////////////
//String
///in C => there is no data type called string
///despite there are many libraries [headers] deal with string

///we can create string
//by create array of characters

#include<stdio.h>
int main()
{
    char name[15];  //15Bytes

    for(int i=0;i<15;i++)
    {
        scanf("%c",&name[i]);
    }
    for(int i=0;i<15;i++)
    {
        printf("%c",name[i]);
    }
    return 0;
}
//o/p
//m enter o enter h enter

#include<stdio.h>
int main()
{
    char name[30];  //15Bytes  |m|o|h|a|m|e|d|||||||||

    for(int i=0;i<15;i++)
    {
        name[i]=getch();
    }
    for(int i=0;i<15;i++)
    {
        printf("%c",name[i]);
    }
    return 0;
}

//o/p
//mohamed Enter

//Mohamed


///////////////////////////////////////////////
///Array is a Fixed size
///when you declare[allocate] array in memory
//you cannot modify,add,delete any cell from it
//int arr[10]  => XXX  arr[9]   arr[11] 
///////////////////////////////////////////////



#include<stdio.h>
int main()
{
    char name[15];  //15Bytes  |A|L|I|\0|I|S|O|T|M|O||||||
    char ch;
    int x=0;  //indexer   0 1 2 3 4
    
    
    //////////////////ALI Enter   |A|L|I|||||||
    while ((ch=getch())!=13)
    {
        name[x]=ch;
        x++;
    }
    name[x]='\0';
    //////////////////

    //////////////////
    do
    {
        ch=getch();  //ALI Enter
        name[x]=ch;
        x++;

    }
    while (ch!=13);
    //Delimeter here
    name[x]='\0';
    ////////////////////   


    //soln 3 more effective
    printf("%s",name);
    //Will print untill \0


    //soln 2  effective
    x=0;
    while (name[x]!='\0')
    {
        printf("%c",name[x]);
        x++;
    }
    

    //soln 1  not effective
    for(int i=0;i<15;i++)
    {
        if(name[i]!='\0')
        {
            printf("%c",name[i]);
        }
    }
    return 0;
}
//o/p
//MO%#################

///When you enter string inside array of character
///and wanna stop
///we use  delimeter / Null terminator   \0


///////////////////////////////////////////////////////////

#include<stdio.h>


int main()
{

    char name[30];
    //string rules
    //mohamd
    //mariem
    char fname[5]; //Big WRONG
    //ALWAYS Consider null terminator for your array
    char name[6];

    printf("%s",fname);   |||||||#########\0

    x=0;
    while (name[x]!='\0')
    {
        printf("%c",name[x]);
        x++;
    }

    return 0;
}


//////////////////////////////////////////

//Functions in string

#include<stdio.h>
#include<string.h>
int main()
{
    char fname[16];
    char lname[16];
    char fullname[32];

    printf("Enter First Name");
    gets(fname);    //mohamed Enter  |m|o|h|a|m|e|d|\0|||||||||

    printf("Enter Last Name");
    gets(lname);    //Ali Enter

    printf("Your name is\n");
    puts(fname);   //untill \0
    puts(lname);

    //strcat(arrayof character,arrayof character)
    //strcpy(arrayof character,arrayof character)
    //strcmp(arrayof character,arrayof character)
    //strlen(array of character)   => \0

    ///full name ==> rubbish   |O|G|S|\0|||||||||||
    // |m|o|h|a|m|e|d| |a|l|i|\0|||||||||
    strcpy(fullname,fname);  //replace
    strcat(fullname," ");
    strcat(fullname,lname);


    puts(fullname);
    return 0;
}

////////////////////////////////////////////

///default values in array of character

int main()
{
    char name[10]={'m','a','r','i','e','m','\0'};
    char lname[10]="mariem";
    gets(lname); //no need to write \0 compiler do it 
    //int arr[]; //error
    char names[3][10]={{'a','b','c'},{},{}};
    char names[3][10]={"Ali","Sara","Ahmed"};

    char lname[10]; // |s|a|r|a|\0||||||

    scanf("%s",lname);//sara Enter  ///take string untill i press enter 


    //while ch=getch     must \0 written

}


//getchar()
//strcmp(,)
//strlen();


/////////////////////////////////////////////////////////


int main()
{

    char menu[4][10]= {"File","New","Display","Exit"};
    char ch;
    int cursor=0;
    int flag=1;
    do
    {
        //always clear before print
        system("cls");
        //
        for(int i=0; i<4; i++)
        {
            if(cursor==i)
            {
                textattr(5);
            }
            else
            {
                textattr(7);
            }
            gotoxy(15,10+i*2);
            _cprintf("%s",menu[i]);
        }//end of for loop

        //read key from user
        ch=getch();

        switch(ch)
        {
        case Null:
            ch=getch();
            switch(ch)
            {
            case Up:
                cursor--;
                if(cursor<0)
                    cursor=3;
                break;
            case Down:
                cursor++;
                if(cursor>3)
                    cursor=0;
                break;
            case Home:
                cursor=0;
                break;
            case End:
                cursor=3;
                break;
            }
            break;
        case Enter:
            switch(cursor)
            {
            case 0:
                system("cls");
                printf("FILEEEEEEEEEEEEEEE");
                getch(); //waiting untill i press any key
                break;
            case 1:
                system("cls");
                printf("NEWWWWWWWWW");
                getch(); //waiting untill i press any key
                break;

            case 2:
                system("cls");
                printf("DISP");
                getch(); //waiting untill i press any key
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
    while(flag==1);

    return 0;
}


/////////////////////////////////////

ch=getch()

switch (ch)
{
    case -32:
    ch=getch();
    switch (ch)
    {
        case up:
        break;
        case end:
        break;
    }
    break;
    case Enter:
    break;
    case esc:
    break;
}



//////////////////////////

///1-Read first name ,last name
///// then fill in container full name 
/////  and print it
//////strcat ,strcpy    fn[10]   ln[10]      fulln[21]
////// gets() puts()

///2- read string from user   array[50]
///   then print it reversly
    //while();
    ///Enter message
        /// my name is alaa

        /// aala si eman ym

        ///same array
        ///do it ya ali
        //ila ay ti od

///3- program to identify key ASCII  normal/extended  + ASCII # 

///4- Highlighted menu


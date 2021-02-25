#include<stdio.h>
#include<stdlib.h>

        FILE *fp,*fp1;
	char in,choice,m,fm;
        char file_name[30];

void read(char file_name[30])
 {
                int chcount=0,lcount=1;
               fp=fopen(file_name,"r");
                if(fp==NULL)
                   {
                   printf("File isn't exist/n");
                    exit(0);
  		   }
                else
 		   {
                printf("\n\t\t\t...Read...\n");
                printf("\n-----------------------------------------------------------------------\n"); 
		        while((in=getc(fp))!=EOF)
                       	{
                           printf("%c",in);
                           chcount++;
                           if(in==' ')
                           lcount++;
		        }
                printf("\n______________________________________________________________________\n");
                
                printf("\nStatus:- character:%d",chcount);
                printf(" Words:%d",lcount);
                printf("\n______________________________________________________________________\n");
                fclose(fp);
                   }
 } 

void write(char file_name[30])
 {
   fp=fopen(file_name,"w");
                    printf("\n\t\t\tFor Linux... \n");
                    printf("->press Enter and  ctrl+d for save\n");
                    printf("\n\t\t\tFor Window... \n");
               	    printf("->press enter and press ctrl+z and then press enter\n");
                    printf("->Add text at the end");
                    printf("\n\t\t\t...write... \n");
                    printf("\n-----------------------------------------------------------------------\n"); 
                    while((in=getchar())!=EOF)
                       	{
                           putc(in,fp);
		        }
                     printf("\n______________________________________________________________________\n");
                     fclose(fp);
 }

void append(char file_name[30])
 {
    fp=fopen(file_name,"a");
                printf("\n\t\t\tFor Linux... \n");
                printf("->press Enter and  ctrl+d for save\n");
                printf("\n\t\t\tFor Window... \n");
                printf("->press enter and press ctrl+z and then press enter\n");
                printf("->Add text at the end");
                printf("\n\t\t\t...ADD... \n");
                printf("\n-----------------------------------------------------------------------\n\n"); 
                while((in=getchar())!=EOF)
                       	{
                           putc(in,fp);
                
                         }
                printf("\n______________________________________________________________________\n");
		fclose(fp);
}
void create()
{
 printf("\n______________________________________________________________________\n");
 printf("\n->\t\tEnter the file name to create>>> ");
 scanf("%s",&file_name);
 printf("\n______________________________________________________________________\n");
 mode:
 printf("\n->\t\t1.Write ------------press w");
 printf("\n->\t\t2.Append------------press a");
 printf("\n->\t\tEnter the file mode >>> ");
 scanf("%s",&fm);
 printf("\n______________________________________________________________________\n");
 switch(fm)
 {
  case 'w':
           {
             fp=fopen(file_name,"w");
             fclose(fp);
              break;
           }
 case 'a':
           {
             fp=fopen(file_name,"a");
             fclose(fp);
              break;
           }
 default:
          { 
              printf("\n->\t\tEnter valid mode\n");
              goto mode;
          }
 }
 
 printf("\n->\t\tFile Created successfully\n");
}
void del(char file_name[30])
{
 remove(file_name);
 printf("\n->\t\tfile is deleted Succesfully\n");
}
void removef(char file_name[30])
{
 remove(file_name);
 fp=fopen(file_name,"w");
 fclose(fp);
 printf("\n->\t\tContents of file is deleted Succesfully\n");
}
int main()
{
        char filename[30];
	printf("\n");
        printf("\n______________________________________________________________________\n\n");
        printf("\t\t\tTEXT EDITOR");
        printf("\n______________________________________________________________________\n\n\n");
        printf("->\t\t1. Enter the file name\n");
        printf("->\t\t2. If file exist then file opened in read mode \n"); 
        printf("->\t\t3. If file doesn't exist then its create new file and\n  \t\t   opened in given mode \n");
        printf("->\t\t4. After it you can edit your file like write , add\n  \t\t   and then read what you do\n"); 
        printf("\n______________________________________________________________________\n");  
        printf("\n->\t\tEnter the file name >>> ");
        scanf("%s",&filename);
        printf("\n______________________________________________________________________\n");
        fp=fopen(filename,"r");
                if(fp==NULL)
                   {
                    printf("\n->\t\tFile not exist!\n");
                    create();
                    }
                else
 		   { 
                    read(filename);
                   }
        fclose(fp);
        again:
        printf("\n______________________________________________________________________\n");
        printf("\n->\t\t you want to do editing(y/n):");
        scanf("%s",&m);
        printf("\n______________________________________________________________________\n");
        if(m=='y' || m=='Y')
        {
        valid:
        printf("\n______________________________________________________________________");
	printf("\n->\t\tWhat you want to do:");
        printf("\n->\t\t1.Read      ------------press r");
        printf("\n->\t\t2.Write     ------------press w");
        printf("\n->\t\t3.Add       ------------press a");
        printf("\n->\t\t4.Create    ------------press c");
        printf("\n->\t\t5.Erase data------------press x");
        printf("\n->\t\t6.Delete    ------------press d");
        printf("\n->\t\t7.Exit      ------------press e");
        printf("\n\n->\t\t Enter your choice:");
        scanf("%s",&choice);
	switch (choice)
        {
          case 'r':
	     {
               read(filename);
                break;
	      }
          case'w':
             {
  	  	write(filename);
                break;
             }
          case 'a':
             {   
                read(filename);
  	  	append(filename);
                break;
               }
          case 'd':
             {   
                del(filename);
                break;
               }
          case 'x':
             {   
                removef(filename);
                break;
               }
          case 'c':
             {   
                create();
                break;
               }
          case 'e':
               {
                 goto exit;
                 break;
               }
        default: 
               {
               printf("->\n\t\tSelect valid option plz..\n");
                goto valid;
                 } 
        } 
        }
        else if(m=='n')
            {
              exit:
              printf("\n-----------------------------------------------------------------------\n");   
              printf("\t\t\tThanks");
              goto end;
             }   
        goto again;
        end: 
        printf("\n-----------------------------------------------------------------------\n");      
        return 0;
}

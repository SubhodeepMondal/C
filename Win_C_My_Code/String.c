        #include <stdio.h>
        #include <stdlib.h>
        
   void stringlen (char str [ ]) ;
   void stringcopy (char str1 [ ],char str2 [ ] ) ;
   void stringcmp (char str1 [ ],char str2 [ ] ) ;
   void search (char str  [ ]) ;
   void stringcat (char str1 [ ],char str2 [ ] ) ;
   void main ( )
   {
      int ch;
      char str [50], str1 [50], str2 [50];
     do
     {
         printf ("\n ******Menu*****\n");
         printf ("\n 1.length of string\n2.copy two strings\n3.compare two strings\n");
         printf ("4.concatinate two strings\n5.search word\n6.exit");
         printf ("\nEnter your choice\n");
         scanf ("%d",&ch);
         switch (ch)
         {
           case 1 : 
                          printf("\n enter string\n");
                          fflush (stdin);
                          scanf ("%[^\n]s",str);
                          stringlen (str);
                          break;
           case 2 :
                        printf("\n enter  1st string\n");
                        fflush (stdin);
                        scanf ("%[^\n]s",str1);
                        printf("\n enter 2nd string\n");
                        fflush (stdin);
                        scanf ("%[^\n]s",str2);
                        stringcopy (str1,str2);
                        printf ("\nthe string is\n %s",str1);
                        break;
          case 3 :
                        printf("\n enter  1st string\n");
                        fflush (stdin);
                        scanf ("%[^\n]s",str1);
                        printf("\n enter 2nd string\n");
                        fflush (stdin);
                        scanf ("%[^\n]s",str2);
                        stringcmp (str1,str2);
                        break;
         case 4 :
                        printf("\n enter  1st string\n");
                        fflush (stdin);
                        scanf ("%[^\n]s",str1);
                        printf("\n enter 2nd string\n");
                        fflush (stdin);
                        scanf ("%[^\n]s",str2);
                        stringcat (str1,str2);
                        printf ("\nthe string is\n %s",str1);
                        break;
          case 5 :
                          printf("\n enter string\n");
                          fflush (stdin);
                          scanf ("%[^\n]s",str);
                          search (str);
                          break;
          case 6 : 
                          exit (0);break;
          default:
                          printf ("\n wrong input passing\n");
        }
       }while (1);
    }

    void stringlen (char str [ ])
   {
     int i=0;
     while (str [i]!='\0')
        i++;
      printf("\n the length of string is %d",i);
	}
     void stringcopy (char str1 [ ],char str2 [ ] )
     {
       int i=0 , j ;
       while (str2 [i]!='\0' )
       {
         str1 [i]=str2 [i];
         i++;
       }
        str1 [i]='\0';
      }                         
      void stringcmp (char str1 [ ],char str2 [ ] )
      {
        int i=0 , c;
        while (str1[i]!='\0'&&str2[i]!='\0'&&str1 [i]==str2 [i])
          i++;
        c=str1 [i]-str2 [i];
        if (c==0)
         printf ("\n string are equal\n");
        else   
         printf ("\n string are not equal\n");
       }
      void search (char str  [ ])
      {
         char pat[20];
         int i,j=0;
         printf("\n Enter pattern \n");
         fflush (stdin); 
         scanf ("%[^\n]s",pat);
         for(i=0;str[i]!='\0';i++)
         {
           if(str[i]==pat[j])
          {
	 while(pat[j]!='\0'&&str[i]==pat[j])
	 {
	  i++;
	  j++;
	 }
	 if(pat[j]=='\0')
	 {
	  printf("\n pattern exists\n");
	  return;
	 }
	 else
	 {
	  while(str[i]!=' ')
	   i++;
	 }
	 j=0;
           }
         }
         printf("\n pattern does not exists\n");
      }
    void stringcat (char str1 [ ],char str2 [ ] )       
    {
      int  i = 0 , j ;
      while (str1 [i]!='\0')
          i++;
      j=0;
      while (str2 [j]!='\0')
      str1 [i++]=str2 [j++];
      str1 [i]='\0';
     }


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXCHAR 1000
struct assign{
    char id[50];
    int num;
    int flag;
};
struct assign a[100];
int cnt=0;
char res[100];
int r;
char b[100];
char cpy[100]="\0";
int count=1;
int check_flag=0;
int is_id=0;
int main(void) {
  FILE *fp;
    char str[MAXCHAR];
    char* filename = "icg.txt";
    int flag;
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    char first_string[100];
    char second_string[100];
    char third_string[100];
    char fourth_string[100];
    char fifth_string[100];
    while (fgets(str, MAXCHAR, fp) != NULL)
     { 
        //printf("%s", str);
        count=1;
        check_flag=0;
        r=0;
        is_id=0;
        strcpy(first_string,"");
        strcpy(second_string,"");
        strcpy(third_string,"");
        strcpy(fourth_string,"");
        strcpy(fifth_string,"");

        for(int i=0;i<strlen(str);i++)
        {   
            if(count==1)
            {
            while(!isspace(str[i]))
            {
                if(str[i]!=':')
                {
                cpy[0]=str[i];
                strncat(first_string, cpy, 1);
                i++;
                }
                else
                {
                    check_flag=1;
                    break;
                }
            }
            if(check_flag==1)
            {
                break;
                //printf("\nfirst:%s\n",first_string);
            }
            }
            if(count==2)
            {
             if(str[i]=='=')
             {
                cpy[0]=str[i];
                strncat(second_string, cpy, 1);
                //printf("\nsecond:%s\n",second_string);
                i++;
             }
             else
             {
                check_flag=1;
                break;
             }
            }
            if(count==3)
            {
                 while(!isspace(str[i]))
                {
                    if(!isalpha(str[i]))
                    {
                    cpy[0]=str[i];
                    strncat(third_string, cpy, 1);
                    i++;
                    }
                    else if(isalpha(str[i]))
                    {
                        cpy[0]=str[i];
                        strncat(third_string, cpy, 1);
                        i++;
                        is_id=1;

                    }                
                    else
                    {
                        check_flag=1;
                        break;
                    }
                }
                if(strcmp(third_string,"true")==0 || strcmp(third_string,"false")==0)
                {
                    check_flag=1;
                    break;
                }
                if(is_id==1)
                {
                for(int j=1;j<cnt+1;j++)
                {
                if(!strcmp(third_string,a[j].id))
                {
                    sprintf(third_string, "%d", a[j].num);
                    break;
                }
                }
                }
                if(check_flag==1)
                {
                    break;
                }
                //printf("\nthird:%s\n",third_string);
            }
            if(count==4)
            {   
                if(isspace(str[i]) || str[i]=='\n' || str[i]=='\0')
                {
                    continue;
                }
                else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%')
                {

                    cpy[0]=str[i];
                    
                strncat(fourth_string, cpy, 1);
                    i++;
                }
                else
                {   
                    
                    check_flag=1;
                    break;
                }
                //printf("\nfourth:%s\n",fourth_string);
            }
            if(count==5)
            {
                 while(!isspace(str[i]))
                {
                    if(!isalpha(str[i]))
                    {
                    cpy[0]=str[i];
                    strncat(fifth_string, cpy, 1);
                    i++;
                    }
                    else if(isalpha(str[i]))
                    {
                        cpy[0]=str[i];
                        strncat(fifth_string, cpy, 1);
                        i++;
                        is_id=1;

                    }                
                    else
                    {
                        check_flag=1;
                        break;
                    }
                }
                if(is_id==1)
                {
                for(int j=1;j<cnt+1;j++)
                {
                if(!strcmp(fifth_string,a[j].id))
                {
                    sprintf(fifth_string, "%d", a[j].num);
                    break;
                }
                }
                }
                if(check_flag==1)
                {
                    break;
                }
                //printf("\nfifth:%s\n",fifth_string);
            }
            count++;
            if (count==6)
            {
                int result;
                strcpy(res,"");
                if(fourth_string[0]=='+')
                {
                    result=atoi(third_string)+atoi(fifth_string);
                }
                if(fourth_string[0]=='-')
                {
                    result=atoi(third_string)-atoi(fifth_string);
                }
                if(fourth_string[0]=='*')
                {
                    result=atoi(third_string)*atoi(fifth_string);
                }
                if(fourth_string[0]=='/')
                {
                    result=atoi(third_string)/atoi(fifth_string);
                }
                if(fourth_string[0]=='%')
                {
                    result=atoi(third_string)%atoi(fifth_string);
                }
                sprintf(res, "%d", result);
                printf("%s %s %s \n",first_string,second_string,res);
                for(int j=1;j<cnt+1;j++)
                {
                if(!strcmp(first_string,a[j].id))
                {
                    a[j].num=atoi(res);
                    r=1;
                    break;
                }
                }
                if(r!=1)
                {
                    cnt++;
                    strcpy(a[cnt].id,first_string);
                    a[cnt].num=atoi(res);

                }
            }
        }
            
        if(check_flag==1)
            {
               printf("%s", str);
            }
        if(count==4 && check_flag!=1)
        {
            for(int j=1;j<cnt+1;j++)
            {
                if(!strcmp(first_string,a[j].id))
                {
                    a[j].num=atoi(third_string);
                    r=1;
                    break;
                }
            }
            if(r!=1)
            {
                cnt++;
                strcpy(a[cnt].id,first_string);
                a[cnt].num=atoi(third_string);

            }
            printf("%s = ", first_string);
            printf("%d\n", atoi(third_string));
        }
    
    }
    fclose(fp);
    return 0;

}





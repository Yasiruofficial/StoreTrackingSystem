#include <stdio.h>
#include <stdlib.h>
int select(int C_size,int S_size,int C_array[C_size][S_size])
{
    int a,b,choice,cno,sno;
    choice:
    printf("I want to search the category of a stole..(Press 1)\n");
    printf("I want to search all the stoles in a category..(Press 2) \n : ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        printf("Enter Stole Number ");
        scanf("%d",&sno);

        for(a=0;a<C_size;a++){
            for(b=0;b<S_size;b++){

                if(C_array[a][b] == sno){
                    printf("Category Number is %d And Stole Location is %d\n\n",a+1,b+1);
                    goto choice;
                }
            }
        }
        printf("\nNo Stole Found\n\n");
        goto choice;
    }
    else if(choice == 2){

        printf("Enter Category Number ");
        scanf("%d",&cno);

        for(a=0;a<C_size;a++){
            for(b=0;b<S_size;b++){

                if(a+1 == cno){
                    printf("Stole Number %d , ",C_array[a][b]);
                    goto choice;
                }
            }
        }
        printf("\n");
        printf("No Category found");
        printf("\n\n");
        goto choice;

    }
    else{
            printf("\nInvalid Input!!\n\n");
            goto choice;
    }
}

int main()
{
    printf("\n\n\n                        ****WELCOME TO LIMASHA'S STORE TRACKING SYSTEM****\n\n\n");
    int cno,sno,a,b,C_size=5,S_size=3,first,temp;//User gen Sizes gannath puluwan
    int C_array[C_size][S_size];
    int DuplicateChecker[100];
    int count = 0;

    for(a=0;a<C_size;a++){

        for(b=0;b<S_size;b++){
            stolenumber:

            printf("Enter %d category %d Stole Number : ",a+1,b+1);
            scanf("%d",&temp);

            for(first=0;first<count;first++){

                if(DuplicateChecker[first] == temp){

                    printf("\nDuplicated stole Number!! Try again\n\n");
                    goto stolenumber;
                }
            }

            C_array[a][b] = temp;
            DuplicateChecker[count] = temp;
            count++;
        }
    }
    printf("\n");

    select(C_size,S_size,C_array);


}

/*

            BERKANT TUÐBERK DEMÝRTAÞ
                    2315232


*/



#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "avltree.h"

void most_popular_year_movies(AVLTree);
void display_movies_keyword(AVLTree,char*);
void display_index(AVLTree);
AVLTree read_data(char **);



int main(int argc, char *argv[]){

    AVLTree myTree; // my Tree
    myTree=read_data(argv); // Process the file and calls the insert function
   // DisplayTreeStructure(myTree,0);
    char search[50]; // it's for specific keyword answer
    int ans,valid=1; //ans for operation and valid for loop

    printf(">>>Welcome to Movie Analysis at IMDB<<<\n");
    printf("--Menu--\n1. Display the full index of movies\n2. Display the movies where their title contains a specific keyword\n3. Display the year with maximum number of movies\n4. Exit");

    //Main Menu

    while(valid){
        printf("\nOperation:");
        scanf("%d",&ans);
        fflush(stdin);
        if(ans==4)
            valid=0;
        else{
            if(ans==1)
                display_index(myTree);
            else if(ans==2){

                printf("\nEnter the Keyword:");
                gets(search);
                display_movies_keyword(myTree,search);
            }
            else if(ans==3);
                //most_popular_year_movies(myTree);



            else{
                fflush(stdin);
                printf("Invalid operation! Try Again.\n");
                printf("Operation:");
                scanf("%d",&ans);
            }



        }

         printf("--Menu--\n1. Display the full index of movies\n2. Display the movies where their title contains a specific keyword\n3. Display the year with maximum number of movies\n4. Exit");


    }

    return 0;
}

void display_index(AVLTree t)
{
    // It shows the titles alphabetically.

	if (t != NULL)
	{
	    display_index(t->left);
	    printf("%s\n", t->title);
		display_index(t->right);
	}
}

AVLTree read_data(char ** argv){


    char line_size[256],first_line=0; //line_size for reading the txt line by line; first_line variable for not reading the first line which includes nothing.

    // Variables for reading line;
    char title[100];
	int year;
	char ID[100];
	char link[500];
//-------------------------------------------------

    AVLTree root=NULL;

    FILE *infile = fopen(argv[1], "r");
    if(infile == NULL)//Checks if the file exists.
    {
        printf("File called movies.txt doesn't exist.");

    }

    else{

        while(fgets(line_size, sizeof(line_size), infile)!=NULL){ //Reads txt line by line


            if(first_line==0) //Condition for not reading first line
                first_line+=1;

            else{


            // Reads up to ',';

           strcpy(title,strtok(line_size,","));
           year=atoi(strtok(NULL,","));
           strcpy(ID,strtok(NULL,","));
           strcpy(link,strtok(NULL,"\n"));

           root=insert_movie(title,year,ID,link,root); //calls the insert function

            }
        }


    }

    return root;

}
AVLTree insert_movie(char title[100],int year,char ID[100],char link[500] , AVLTree root){

    AVLTree t=(AVLTree) malloc(sizeof(struct Node));


    if(root==NULL){

        strcpy(t->title,title);
        t->year=year;
        strcpy(t->ID,ID);
        strcpy(t->link,link);
        t->right=NULL;
        t->left=NULL;
        t->height=1;
        return t;
    }


else{

    if(strcmp(root->title,title)>0)
        root->left = insert_movie(title,year,ID,link,root->left);
    else if(strcmp(root->title,title)<0)
        root->right = insert_movie(title,year,ID,link,root->right);
    else
        return root;
}


    // After inserting, balancing begins here;

    int balance= getbalance(root);

    if(balance<-1 && strcmp(root->title,root->left->title)>0)
        return SingleRotateWithRight(root);

    else if(balance>1 && strcmp(root->title,root->right->title)<0)
        return SingleRotateWithLeft(root);

    if(balance<-1 && strcmp(root->title,root->left->title)<0){
        root->right = SingleRotateWithLeft(root->right);
        return SingleRotateWithRight(root);
    }
    else if(balance>1 && strcmp(root->title,root->right->title)>0){
        root->left = SingleRotateWithRight(root->left);
        return SingleRotateWithLeft(root);
    }

	return root;


}
void display_movies_keyword(AVLTree myTree ,char search[50]){

    int i,j,match=0,begin=0; //"Match" for checking matched letters, "begin" for beginning the place when a letter matched instead of begin of the first letter again.
    if (myTree!=NULL){

        if(strcmp(myTree->title,search)==0) // When the key matched the title print it;
            printf("\n\n%s %d %s %s\n\n",myTree->title,myTree->year, myTree->ID,myTree->link);
        else{



        /*

        Checks character by character of the title and key.
        If match variable equals the search key that means they're matched.
        To handle some bug problems i wrote breaking points

       */
            for(i=0;i<strlen(search);i++){ //Checks the characters of title and key
                for(j=begin; j<strlen(myTree->title); j++){
                    if(myTree->title[j]==search[i] ){
                        begin=j+1;
                        match+=1;
                        break;

                    }
                    else if(match>1 && match == strlen(search)-1) //To be able to handle bug problem. Checking char by char may lead some problems.
                        break;


                }
            }

            }
            if(match==strlen(search) ) // If match variable equals the length of key. They're matched.
                printf("\n\n%s %d %s %s\n\n",myTree->title,myTree->year, myTree->ID,myTree->link);


            display_movies_keyword(myTree->right,search);
            display_movies_keyword(myTree->left,search);

    }

    }

void most_popular_year_movies(AVLTree root){

    if(root == NULL)
        return;

    int maxValue = root->year;
    int counting = 1;
    int currentVal = root->year;
    int currentCount = 1;

}







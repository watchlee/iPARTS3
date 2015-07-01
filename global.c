/*************************************************************************
	> File Name: global.c
	> Author: LeePoHan
	> Mail: windvergil@gmail.com
	> Created Time: Wed Jul  1 13:34:18 2015
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * function: semiglobal alignment
 * Input : Working Path
 * Output: result.php
 *
*/

/*
 * Input:
 * $seq1 $seq2: sequence with structural alphabet
 * $matfile: Substitution matrix file
 * $opp: open gap penelty
 * $exp: extended gap penalty
 * $suboptimal: # of output solution
*/

/*-------------------------Setting Variable-------------------------------*/
static int input_length;
FILE *input_file;
char* seq1;
char* seq2;
char* matfile;
int gap_opp;
int gap_exp;
int gap_suboptimal;

/************************************************************************/

/*-------------------------Setting function-------------------------------*/
void input_function(char*);
void print_result(char*,int);

/************************************************************************/
int main(int argv,char* argc[])
{
    char *file = argc[1];
    input_function(file); 
 
    fclose(input_file);
    return 0;
}

void input_function(char *path)
{
    input_file = fopen(path,"r");
    if(input_file==NULL)
    {
        printf("where is input file?\n");
        exit(-1);
    }
    char *temp;

    int data_size = 0;
    while(!feof(input_file))
    {
        fscanf(input_file,"%s",temp);
        data_size++;   
    }
    fclose(input_file);

    input_file = fopen(path,"r");
    
    /*We have to get data from php */
    /*Input 
     *1 line = $seq1
     *2 line = $seq2
     *3 line = $matfile
     *4 line = $opp
     *5 line = $exp
     *6 line = $suboptimal
     */
    int loop  = 0;
    while(!feof(input_file))
    {
        fscanf(input_file,"%s",temp);
        temp = strtok(temp,"\"");
        if(strncmp(temp,"=",1)!=0&&strncmp(temp,"$",1)!=0&&strncmp(temp,"?>",1)!=0&&strncmp(temp,"<?",1)!=0)
        {
            printf("%s\n",temp);
        }
        loop++;
    }
    

}

void print_result(char* array,int length)
{
    int loop;
    printf("print result\n");
    for(loop =0;loop<length;loop++)
        printf("%s\n",&array[loop]);
    
}
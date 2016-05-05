// Nicholas Beaudoin
// Assignment 4
// 4 - 16 - 16


#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 50

typedef struct{
    int id;
    int year;
    double salePrice;
    double cost;
    char make[SIZE];
    char model[SIZE];  
}bike;

// Function prototypes

// shows user options 
void menu(bike array[], int *num);

// add a new bike record
void add(bike array[], int *num);

// display all records on screen
void print(bike array[], int *num);

// save all records to a file
void save(bike array[], int *num);

// delete all records
void clear(bike array[], int *num);

// delete record of choice by id #
void delete(bike array[], int *num);

// welcome user to program
void welcome();

// set initial bike inventory
void initiateRecords(bike array[], int *num);

// change information in record of choice
void update(bike array[], int *num);

// fill record information
void fill(bike array[], int *num);


int main() {
    
    int numBikes; 
    bike records[SIZE];   
    
   
    // set initial bike inventory
    initiateRecords(records, &numBikes);
    
    
    
    // welcome user to program
    welcome();
    
    // display menu
    menu(records, &numBikes);
    
    printf("\n\n** HOT POTATO **\n\n");
    
    
    
    return 0;
}


// function definitions

            
// set initial bike inventory
void initiateRecords(bike array[], int *num){
    *num = 5;
    
    // initial array index 0
    array[0].id = 101;
    array[0].year = 2003;
    array[0].salePrice = 3500;
    array[0].cost = 1000;
    strcpy(array[0].make, "Honda");
    strcpy(array[0].model, "Shadow"); 
    
    
    // initial array index 1
    array[1].id = 102;
    array[1].year = 2009;
    array[1].salePrice = 7000;
    array[1].cost = 5000;
    strcpy(array[1].make, "Harley-Davidson");
    strcpy(array[1].model, "Sportster");
    
    // initial array index 2
    array[2].id = 103;
    array[2].year = 1978;
    array[2].salePrice = 4000;
    array[2].cost = 500;
    strcpy(array[2].make, "Kawasaki");
    strcpy(array[2].model, "KZ1000");
    
    
    // initial array index 3
    array[3].id = 104;
    array[3].year = 1986;
    array[3].salePrice = 3000;
    array[3].cost = 700;
    strcpy(array[3].make, "Honda");
    strcpy(array[3].model, "Magna");
    
    
    // initial array index 4
    array[4].id = 105;
    array[4].year = 1995;
    array[4].salePrice = 2300;
    array[4].cost = 1000;
    strcpy(array[4].make, "Yamaha");
    strcpy(array[4].model, "Virago");
}

// welcome user to program
void welcome(){    
    printf("\nHello and welcome. This program helps you create an inventory for motorcycles.\n");
    printf("To get you started, 5 motorcycles have already been entered.\n");
}


// shows user options
void menu(bike array[], int *num){
    
    char choice;
    
    printf("\n\n******************************************\n");
    printf("Please select from the options below:\n");
    printf("A - ADD a new entry\n"); // add a new bike record
    printf("D - DELETE an entry\n"); // delete record of choice
    printf("P - PRINT entire catalog\n"); // display all records on screen
    printf("S - SAVE the current catalog\n"); // save all records to a file
    printf("C - CLEAR entire catalog\n"); // delete all records
    printf("U - Update an entry\n"); // change information in record of choice 
    printf("Q - QUIT\n\n"); // quits program
    printf("What would you like to do: ");
    scanf(" %c", &choice);
    
    choice = tolower(choice);
    switch(choice){
        case 'a':
            add(array, num);
            break;
        case 'd':
            delete(array, num);
            break;
        case 'p':
            print(array, num);
            break;
        case 's':
            save(array, num);
            break;
        case 'c':
            clear(array, num);
            break;
        case 'u':
            update(array, num);
            break;
        case 'q':
            break;
        default:
            printf("\n\n******** INVALID SELECTION ********\n\n");
            menu(array, num);

    }   
}

// add a new bike record
void add(bike array[], int *num){
    
    
    // fill new bike information
    if(*num > 0){
        array[*num].id = array[*num-1].id+1;
    }else {
        array[*num].id = 101;
    }
    fill(array, num);
    
    // increment number of elements in records array
    (*num)++;
    
    printf("\n-- Your entry has been added to the catalog --\n");
    
    
    
    menu(array, num);
}


// fill record information
void fill(bike array[], int *num){
    
    printf("\nPlease enter year of motorcycle: ");
    scanf(" %d", &array[*num].year);
        
    printf("\nPlease enter make of motorcycle: ");
    scanf(" %s", array[*num].make);
    
    printf("\nPlease enter model of motorcycle: ");
    scanf(" %s", array[*num].model);
    
    printf("\nPlease enter purchase cost of motorcycle: ");
    scanf(" %lf", &array[*num].cost);
    
    printf("\nPlease enter sale price of motorcycle: ");
    scanf(" %lf", &array[*num].salePrice);
    
}

// display all records on screen
void print(bike array[], int *num){
    
    int i;
    
    if(*num > 0){
        // print information of each individual bike
        for(i=0; i<*num; i++){
            printf("\n\n-------- CATALOG ENTRY %d --------", i+1);
            printf("\nI.D. #: %d \n", array[i].id);
            printf("YEAR: %d \n", array[i].year);
            printf("MAKE: %s \n", array[i].make);
            printf("MODEL: %s \n", array[i].model);
            printf("PURCHASE COST: %.2f \n", array[i].cost);
            printf("SALE PRICE: %.2f \n", array[i].salePrice);
        }
    }else {
        // Tell user if no bikes in inventory
        printf("\n\n******** CATALOG IS EMPTY ********\n\n");
    }
    
    menu(array, num);
}



// save all records to a file
void save(bike array[], int *num){
    FILE *fp;
    int i;
    
    // open catalog output file for inventory information to be saved into.
    fp = fopen("catalog.txt", "w");
    
    fprintf(fp, "\n**** INVENTORY REPORT ****\n");
    if(*num > 0){
        // Save information of each individual bike
        for(i=0; i<*num; i++){
            fprintf(fp, "\n\n-------- CATALOG ENTRY %d --------", i+1);
            fprintf(fp, "\nI.D. #: %d \n", array[i].id);
            fprintf(fp, "YEAR: %d \n", array[i].year);
            fprintf(fp, "MAKE: %s \n", array[i].make);
            fprintf(fp, "MODEL: %s \n", array[i].model);
            fprintf(fp, "PURCHASE COST: %.2f \n", array[i].cost);
            fprintf(fp, "SALE PRICE: %.2f \n", array[i].salePrice);
        }
    }else {
        // Save alert in file if catalog is empty
        fprintf(fp, "\n\n******** CATALOG IS EMPTY ********\n\n");
    }
    
    printf("\n******** CATALOG HAS BEEN SAVED ********\n");
    
    // close output file
    fclose(fp);
    menu(array, num);
}


// delete all records
void clear(bike array[], int *num){
    
    *num = 0;
    
    printf("\n\n******** CATALOG HAS BEEN CLEARED ********\n\n");
    
    menu(array, num);
}


// delete record of choice by id #
void delete(bike array[], int *num){
   int i, j, choice;
   printf("\nPlease enter the I.D. # of the motorcycle you would like to remove: ");
   scanf(" %d", &choice);
   
   // loop through array until id of choice is found
   for(i = 0; i < *num; i++){
       if(array[i].id == choice){
           
           array[i] = array[*num-1];
           (*num)--;
           
           printf("\n\n******** ITEM DELETED FROM INVENTORY ********\n\n");
           
           menu(array, num);
       }
   }
   if(i == *num){
           printf("\n\n******** THERE IS NO MOTORCYCLE WITH THIS I.D. # ********\n\n");
   }
   menu(array, num);
}


// change information in record of choice
void update(bike array[], int *num){
    int i, j, choice;
    printf("\nPlease enter the I.D. # of the motorcycle you would like to update: ");
    scanf(" %d", &choice);
    
    // loop through array until id of choice is found
    for(i = 0; i < *num; i++){
        
        // when id of choice is found, fill it with new info
        if(array[i].id == choice){
           
            fill(array, &i);
            
            printf("\n\n******** ITEM HAS BEEN UPDATED ********\n\n");
            
            menu(array, num);
        }
    }
    if(i == *num){
           printf("\n\n******** THERE IS NO MOTORCYCLE WITH THIS I.D. # ********\n\n");
   }
   menu(array, num);
}
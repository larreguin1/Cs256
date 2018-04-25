/******************************************************************************
Leobardo Arreguin
Project #1: Theater seating
https://github.com/larreguin1/Cs256/tree/master/Desktop/cs%20256/Homework

*******************************************************************************/

#include<stdio.h>
int main()
{
    int rowPrices[15];
    char grid[15][30];
    int totalTicketsAvailable;
    int totalTicketsSold;
    int i,j;
    int row,column;
    int numberOftickets;
    int totalPrice;
    
    //Initialize total prices
    totalPrice=0;
    
    //Initialize total tickets sold
    totalTicketsSold=0;
    
    //Initialize total Tickets available
    totalTicketsAvailable=30;
    
    //Ask the user to enter the seat prices for each row
    for(i=0;i<15;i++){
        printf("Enter price for row : %d\n",i+1);
        scanf("%d",(rowPrices+i));
    }
    
    //Initialize seating chart
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 30; j++) {
            grid[i][j] = '#';
        }
    }
    
    //Print seating chart
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 30; j++) {
            printf("%c", grid[i][j]);
        }
        printf(" Row:%d",i+1);
        printf("\n");
    }
    
    
    //Let user decide what to do
    int choice;
    do{
        printf("Menu\n\n");
        printf("1. Sell a ticket\n");
        printf("2. Display Total Number of seats sold\n");
        printf("3. Display Total Number of seats available\n");
        printf("4. Display Seating Chart\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
    
        switch(choice){
            case 1: 
                //Sell A ticket:
                printf("Enter number of tickets being sold:\n");
                scanf("%d",&numberOftickets);
                
                for(i=0;i<numberOftickets;i++){
                    printf("Enter row of seat being sold : \n");
                    scanf("%d",&row);
                    
                    printf("Enter column of seat being sold : \n");
                    scanf("%d",&column);
                    
                    if(grid[row-1][column-1]=="#"){
                        totalTicketsAvailable=totalTicketsAvailable-1;
                        totalTicketsSold=totalTicketsSold+1;
                        grid[row-1][column-1]='*';
                        totalPrice=totalPrice+rowPrices[row];
                    }else{
                        printf("Seat is already sold");
                    }
                }
                
                //Print Total Price
                printf("**************************************************\n");
                printf("Total Price:%d\n",totalPrice);
                
                //Print seating chart
                printf("**************************************************\n");
                for (i = 0; i < 15; i++) {
                    for (j = 0; j < 30; j++) {
                        printf("%c", grid[i][j]);
                    }
                    printf(" Row:%d",i+1);
                    printf("\n");
                }
                break;
                
                
            case 2: 
                //Display Total Number of seats sold
                printf("Total Number of seats sold:%d\n",totalTicketsSold);
                break;
                
            case 3: 
                //Display Total Number of seats available
                printf("Total Number of seats available:%d\n",totalTicketsAvailable);
                break;
            case 4: 
                //Print seating chart
                for (i = 0; i < 15; i++) {
                    for (j = 0; j < 30; j++) {
                        printf("%c", grid[i][j]);
                    }
                    printf(" Row:%d",i+1);
                    printf("\n");
                }
                break;
            case 5: printf("Quitting program!\n");
                exit(0);
                break;
            default: printf("Invalid choice!\n");
            break;
        }
    } while (choice != 3);
    
    return 0;
}
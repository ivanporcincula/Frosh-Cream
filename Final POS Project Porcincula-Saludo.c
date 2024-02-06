//This program is an Ice Cream Shop's POS (Point of Sale) System 
//pre-processor directives
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// functions used all throughout the program
void menu();
int takeorder();
int discount (int total);
int Option (); 

int main(){ //start main
	char password[20]; 
	char username[20];
	int i;

	printf("To start ordering, please login!\n");
	
	//start
start:
	
	//username input
	printf("Username: ");
	scanf("%s",&username);
	//conditional statement so username would not exceed over 20 characters
	if(strlen(username)> 20){
		printf("Username cannot exceed over 20 characters! Try again!\n\n");
		goto start;
	}
	
	//password input
	printf("Password: ");
	for(i=0; i<18; i++)
  	{
   		password[i]=getch();
   		printf("*");   	
  	}
  	//conditional statement so password would not exceed over 20 characters
  	if(strlen(password)> 20){
		printf("Password cannot exceed over 20 characters! Try again!\n\n");
		goto start;
	}
  	
	  
	  //strcmp returns 0 value if variable and string inside strcmp(variable, string) are the same.
	  //conditional statements if login is successful or not
	if(strcmp(username, "froshicecream1") == 0 && strcmp(password, "123456789012345678") == 0){
	success:
		printf("\n\nLogin successful! Please choose your order in the given list below.\n\n");
		system("pause");
		printf("\n\n");
		menu(); //calls void functio
		system("pause");
		Option(); //calls option function
		
	}
	else if(strcmp(username, "froshicecream2") == 0 && strcmp(password, "sarapngfroshcream2") == 0){
		//goes to "sucess:"
		goto success;
	}
	else if(strcmp(username, "froshicecream3") == 0 && strcmp(password, "sarapngfroshcream3") == 0){
		//goes to "sucess:"
		goto success;
	}
	else{
		printf("\nLogin Failed! Invalid username or password. Please try again.\n");
		//goes back to start
		goto start;
	}

} //end main

//start menu void function
void menu(){
	printf("\t\t ___________________________________________________________________________________________________________________\n");
	printf("\t\t|                                                 FROSHCREAM                                                        |\n");
	printf("\t\t|___________________________________________________________________________________________________________________|\n");
	printf("\t\t|                                                    MENU                                                           |\n");
	printf("\t\t|Order Code         Order Name             Price      |     Order Code             Order Name               Price   |\n");
	printf("\t\t|   100         Chocolate Ice Cream        P45.00     |        110        Chocolate Almond Ice Cream        P60.00  |\n");
	printf("\t\t|   101          Vanilla Ice Cream         P45.00     |        111       Blueberry Cheesecake Ice Cream     P60.00  |\n");
	printf("\t\t|   102         Strawberry Ice Cream       P50.00     |        112          Ube and Cheese Ice Cream        P50.00  |\n");
	printf("\t\t|   103      Cookies & Cream Ice Cream     P50.00     |        113           Cookie Dough Ice Cream         P55.00  |\n");
	printf("\t\t|   104           Mango Ice Cream          P45.00     |        114         Chocolate Brownie Ice Cream      P55.00  |\n");
	printf("\t\t|   105          Avocado Ice Cream         P55.00     |        115               S'mores Ice Cream          P60.00  |\n");
	printf("\t\t|   106         Banana Split Sundae        P95.00     |        116                Caramel Sundae            P40.00  |\n");
	printf("\t\t|   107        Rocky Road Ice Cream        P55.00     |        117               Chocolate Sundae           P40.00  |\n");
	printf("\t\t|   108       Double Dutch Ice Cream       P55.00     |        118              Strawberry Sundae           P40.00  |\n");
	printf("\t\t|   109         Pistachio Ice Cream        P50.00     |        119              Ice Cream Sandwich          P35.00  |\n");
	printf("\t\t--------------------------------------------------------------------------------------------------------------------\n");
}//end of menu void function



int Option () //start of option function
{
	int options; 
	OPTION:
				printf("\nOptions:");
				printf("\n1. Back to menu");
				printf("\n2. Take order");
				printf("\n3. Exit Program");
				printf("\nPlease input your choice:	");
				scanf ("%d", &options); //option input
				choice: 	
				//conditional statement to input which option the user would take 
					if (options==1)
						{
							menu();
							system("pause");
							goto OPTION; //goes back to option
						}
					else if (options==2)	
						{
							takeorder(); //goes to takeorder function
						}
					else if (options==3)
						{
							printf("Thank you for checking out frosh cream. We hope to see you again.");
							exit (0); //exits program
						}
					else 
						{
							printf ("Invalid Input. Please input a valid answer.");
							goto OPTION; //goes back to option
						}
} //end of option function

int takeorder()  //start of takeorder function
{	
	int ordercode, quantity, TOTAL1, total=0, checker=0, choice, w, TotalP[20]={}, TotalQ[20]={}, CODE[20]={}; // variable declaration 
	char answer; // variable declaration
	const char *Menu[]={}; //variable declaration
	const char *menu[]={"Chocolate Ice Chocolate", "Vanilla Ice Cream", "Strawberry Ice Cream", "Cookies & Cream Ice Cream", "Mango Ice Cream", "Avocado Ice Cream", "Banana Split Sundae", "Rocky Road Ice Cream", "Double Dutch Ice Cream", "Pistachio Ice Cream", "Chocolate Almond Ice Cream", 
					"Blueberry Cheesecake Ice Cream", "Ube and Cheese Ice Cream", "Cookie Dough Ice Cream", "Chocolate Brownie Ice Cream", "S'mores Ice Cream", "Caramel Sundae", "Chocolate Sundae", "Strawberry Sundae", "Ice Cream Sandwich"};
	int codes [20]={100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119}; // variable declaration for the order codes
	int price [20]={45,45,50,50,45,55,95,55,55,50,60,60,50,55,55,60,40,40,40,35}; // variable declaration for the order prices		 								
	
	
	printf("\nMay I now take your order?");
do{ //start of do while loop
	ordertaker:
		printf("\nPlease input the order code:	");
		scanf ("%d", &ordercode); //ordercode input
		printf("\nPlease input the quantity:	");
		scanf ("%d", &quantity); //quantity input
		if (ordercode <= 119 && ordercode >=100 && quantity >=1)
				{
					CODE[checker]= codes[ordercode-100]; //formula to compute for the item code
					TotalP[checker]=price[ordercode-100]; //formula to compute the price
					TotalQ[checker]=quantity; //formula to compute the quantity
					Menu[checker]=menu[ordercode-100]; //formula to check the menu
					TOTAL1= TotalQ[checker]*price[ordercode-100];  //formula to compute the initial total
					total += TOTAL1; //formula to compute the running total
					printf("Total: %d", total);	
					checker += 1;
				}
			else 
				{
					printf("\nInput invalid. Please try again");
					goto ordertaker; //returns to ordertaker
				}
			printf("\n");
			printf ("\nDo you have any additional orders? (Y/N)"); //input statement
			fflush (stdin);//clearing input buffer
			scanf ("%c", &answer);
	} while ((answer =='y')||(answer =='Y')); //end of do while loop 
	choices: 
		printf("\n1. Receipt");
		printf("\n2. Return to Menu");
		printf("\n3. Exit Program");
		printf("\nPlease input your choice:	");
		scanf ("%d", &choice); //choice input
		//conditional statement to input which choice the user would take 
		if (choice==1)
			{
				printf("\n\n\t\tRECEIPT");
				printf("\n\t\tOrder Name        			 Order Code             Quantity         	  Price");
				for(w=0; w<checker; w++) //start of for loop
					{
						printf("\n\t\t%s       		  %d          		  %d      		     %d", Menu[w], CODE[w], TotalQ[w],  TotalP[w]);	
	                } //end of for loop
				printf("\n\n\t\tTOTAL:%d", total);
				discount (total); //goes to discount function
			}
		else if (choice==2)	
			{
				goto ordertaker; //displays the option to take order
			}
		else if (choice==3)	
			{
				printf("Thank you for checking out frosh cream. We hope to see you again.");
				exit (0); //exits program
			} 
		else 
			{
				printf("\nInput invalid. Please try again");
				goto choices; //returns to choices
			} 
} //end of takeorder function

int discount (int total) 
{//start of discount function
	float discounttotal,change; //variable declaration 
	int discount,cash;  //variable declaration 
		printf("\n\t\tDiscount");
		printf("\n\t\t0. None");
		printf("\n\t\t1. Senior/PWD (20%)");
		printf("\n\t\t2. Others(30%)");
	tryagain:
		printf("\n\t\tPlease input your choice:	");
		scanf ("%d", &discount); // discount input
		//conditional statement to input which discount option the user would take 
		if (discount==1)
			{
				discounttotal= .8*total; //formula to compute for 20% discount
			}
		else if (discount==2)
			{
				discounttotal= .7*total; //formula to compute for 30% discount
			}
		else if (discount==0)
			{
				discounttotal=total; //formula to compute for no discount
			}
		else 
			{
				printf("\nInput invalid. Please try again");
				goto tryagain;	
			}
		printf("\n\t\tTOTAL WITH DISCOUNT:%.2f", discounttotal);
	money:
		printf("\n\t\tCASH:	");
		scanf ("%d", &cash); //cash input
		//conditional statement to input how much the user paid 
		if (cash>=discounttotal)
			{
				change=cash-discounttotal; //formula to compute for change
				printf("\n\t\tCHANGE %.2f", change);
				printf("\n\t\tThank you for choosing frosh cream. We hope to see you again.");
			}
		else 
		{
			printf("\nInput invalid. Please try again");
			goto money; //returns to money
		}
}//end of discount function

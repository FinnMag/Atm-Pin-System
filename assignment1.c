/* Program Author: Finn Maguire

Program start date: 6/11/2020
Latest edit date: 22/11/2020

Program to enable bank customers to manage their 4 digit PIN number on an ATM.
Program will include 4 options, 1) PIN Verification, 2) Change PIN, 3) PIN History, 4) Exit.
Program will take into account user error input and will help correct the users error. */

#include <stdio.h>
 
int main(void)
{
    //Declare variables
 	int pin[4] = {1,2,3,4};
    int opt = 0;
    int correct = 0;
    int incorrect = 0;
    int end = 0;
    int pintest[4];
    int newpin[4];
    int newpintest[4];
    int i;
    int pincount; 
    int pinverify;
    
    //Default PIN
    printf("The default pin is 1234\n");

    while (end == 0)
    {   
        fflush(stdin);
        //Menu that provides options for selection
        printf("---------------------------------------------------------------------------------\n");
        printf("Welcome to the Bank\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("Please enter the number corresponding to the option\n");
        printf("---------------------------------------------------------------------------------\n");
        
        //4 Options provided
        printf("1.Enter and verify your PIN\n");
        printf("2.Change PIN\n");
        printf("3.History of PIN entries\n");
        printf("4.Exit\n");
        printf("---------------------------------------------------------------------------------\n");
        
        //Clear buffer to prevent excess inputs activating switch function
        fflush(stdin);
        //Input validation
        if(scanf("%d", &opt) == 1)
        {
            //Switch function to execute option selected
            switch(opt)
            {  
                //1. Enter PIN 
                case 1:
                {   
                    //Reset variables
                    i = 0;
                    pincount = 0;
                    pinverify = 0;
                    printf("---------------------------------------------------------------------------------\n");
                    printf("You have selected to verify your PIN\n");
                    printf("---------------------------------------------------------------------------------\n");
                    printf("Please enter your 4 digit PIN number:\n");
                    printf("*Notice, The machine will only take the first 4 numbers entered by the user*\n");
                    printf("---------------------------------------------------------------------------------\n");

                    //For loop to scan new PIN
                    for(i = 0; i < 4; i++)
                    {   
                        //Detects if input contains non integer
                        if(scanf("%1d", &pintest[i]) != 1)
                        {   
                            printf("---------------------------------------------------------------------------------\n");
                            getchar();
                            printf("Invalid input, Please enter an Integer\n");
                            fflush(stdin);
                            //Inavlid input changes variable to stop code from continuing
                            pinverify = 1;
                            break;
                        }   //end if

                    }   //end for

                    if(pinverify == 0)
                    {
                        //Compares digits to see if they match
                        for(i = 0; i < 4; i++)
                        {
                            if(pintest[i] == pin[i])
                            {
                                pincount++;
                            }   //end if

                        }   //end for

                        //If all digits match
                        if (pincount == 4)
                        {
                            printf("---------------------------------------------------------------------------------\n");
                            printf("Your PIN was correct\nYou have verified your PIN\nReturning to the main menu\n");
                            //Counter for correct PIN history
                            correct = correct + 1;
                            fflush(stdin);
                            break;
                        }   //end if
                        
                        //If not all digits match
                        else
                        {
                            printf("---------------------------------------------------------------------------------\n");
                            printf("Your PIN was Incorrect, Returning to the main menu\n");
                            //Counter for incorrect PIN history
                            incorrect = incorrect + 1;
                            fflush(stdin);
                            break;
                        }   //end else

                    }   //end if
                    
                    //Clear buffer
                    fflush(stdin);
                    break;
                }   //end case
            
                //2. New PIN
                case 2:      
                {   
                    //Reset variables
                    i = 0;
                    pincount = 0;
                    pinverify = 0;

                    printf("---------------------------------------------------------------------------------\n");
                    printf("You have selected to change your PIN\n");
                    printf("---------------------------------------------------------------------------------\n");
                    printf("Enter a new PIN:\n");
                    printf("*Notice, The machine will only use the first 4 numbers entered by the user*\n");
                    printf("---------------------------------------------------------------------------------\n");

                    //Scans first 4 digits for new PIN
                    for(i = 0; i < 4; ++i)
                    {   
                        //Scans for integers
                        if(scanf("%1d", &newpin[i]) == 1)
                        {
                            pinverify++;
                        }   //end if
                        
                        //Input validation for non integers
                        else
                        {
                            getchar();
                            printf("---------------------------------------------------------------------------------\n");
                            printf("Invalid input, Please enter 4 Integers\nReturning to the main menu\n");
                            break;
                        }   //end else

                    }   //end for

                    while(pinverify == 4)
                    {
                        //Verifies if new PIN matches
                        printf("---------------------------------------------------------------------------------\n");
                        printf("Please re-enter your new PIN:\n");
                        printf("---------------------------------------------------------------------------------\n");
                        //Clear buffer
                        fflush(stdin);
                        
                        for(i = 0; i < 4; i++)
                        {
                            //Input validation
                            if(scanf("%1d", &newpintest[i]) == 1)
                            {
                                pinverify++;
                            }   //end if

                            //Input validation
                            else
                            {
                                getchar();
                                printf("---------------------------------------------------------------------------------\n");
                                printf("Invalid input, Please enter 4 Integers\nReturning to the main menu\n");
                                break;
                            }   //end else
                        
                        }   //end for
                        break;
                    }   //end while

                    while (pinverify == 8)
                    {
                        //Compares entered PIN's
                        for(i = 0; i < 4; i++)
                        {
                            if(newpintest[i] == newpin[i])
                            {
                                pincount++;
                            }   //end if
                            
                        }   //end for
                    
                        //Compares digits to see if they match
                        if (pincount !=4)
                        {
                            printf("The new PIN did not match, Returning to the main menu\n");
                            break;
                        }   //end if

                        //Assigns PIN variable
                        else
                        {
                            //Reset variable
                            i = 0;
                            for(i = 0; i < 4; i++)
                            {
                                pin[i] = newpin[i];
                            }   //end for
                        
                            printf("---------------------------------------------------------------------------------\n");
                            printf("You have made a new PIN\nReturning to the main menu\n");
                            break;
                        }   //end else

                    }   //end while

                    break;
                }   //end case
                  
                //3.Pin History
                case 3:   
                {
                    printf("---------------------------------------------------------------------------------\n");
                    printf("You have selected to view your PIN entry history\n");
                    printf("---------------------------------------------------------------------------------\n");
                    printf("You have entered your PIN correctly '%d' times\n", correct);
                    printf("You have entered your PIN incorrectly '%d' times\n", incorrect);
                    printf("Returning to the main menu\n");
                    break;
                }   //end case

                //4. Exit
                case 4:
                {
                    printf("Thank you for using the system, Goodbye\n");
                    printf("---------------------------------------------------------------------------------\n");
                    //End condition
                    end = 1;
                    break;
                }   //end case
                
                //Invalid values default to main menu
                default: 
                {
                    printf("---------------------------------------------------------------------------------\n");
                    printf("You have entered an invald value, please try again\n");
                    break;
                }   //end case

            }   //end switch

        }   //end if

        //Input validation for non integers 
        else
        {
            getchar();
            printf("Invalid input, Please enter an Integer\n");
            //Clear buffer
            fflush(stdin);
        }   //end else

    }   //end while

}   //end main
//Anastasis Drougas
//it2024023

#include <stdio.h>
#include <stdlib.h>

//Functions that we need.
int days_of_the_month(int month,int year);
int get_dow(int day, int month, int year);
int get_dow(int day, int month, int year);
void printyear(int year);


int main()
{
   printf("Welcome to the calendar.\n"); //Asking the user to give us the year.
    printf("Year: ");
    int y;
    do 
    {
        if (scanf("%d", &y) != 1) 
        {
            printf("Error reading year, try again: ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
            break;
        }
    } 
    while (1);
    if (y <= 0)
    {
        printf("Error,this calendar accepts only years A.C.\n");
        exit(1);
    }

    printf("Month (0 to print entire year ): ");//Asking the user to give us the month.
    int m;
    do 
    {
        if (scanf("%d", &m) != 1) 
        {
            printf("Error reading month, try again: ");
            /*  Empty scanf buffer */
            while (getchar() != '\n');
        } 
        else 
        {
            break;
        }
    } 
    while (1);
    if ((m<0)||(m>12))
    {
        printf("This month does not exist\n");
        exit(2);
    }

    if (m!=0)
    {
        if (m==1) //Printing the month and the days.
            printf("        Jan\n");
        else if (m==2)
            printf("        Feb\n");
        else if (m==3)
            printf("        Mar\n");
        else if (m==4)
            printf("        Apr\n");
        else if (m==5)
            printf("        May\n");
        else if (m==6)
            printf("        Jun\n");
        else if (m==7)
            printf("        Jul\n");
        else if (m==8)
            printf("        Aug\n");
        else if (m==9)
            printf("        Sep\n");
        else if (m==10)
            printf("        Oct\n");
        else if (m==11)
            printf("        Nov\n");
        else if (m==12)
            printf("        Dec\n");

        printf("Su Mo Tu We Th Fr Sa\n");  

       
        int d=1; //day.
        int days_month = days_of_the_month(m,y); //Returns the number of days that the month has.
        int i; //counter
        
        for (d=1;d<=days_month;d++)
            {
                int w=get_dow(d,m,y); //returns a day of the week (0 for saturday, 6 for sunday, -1 if  the day does not exist)
                
                if (w==-1)//Case, the day does not exist (days between 2 and 14 of September 1752).
                    continue;
                
                if (w==0) //turning Saturday from 0 to 7.
                    w=7;
                
                
               
                if (d==1) //Finding the start.
                {
                    
                    int s=3*w-2; //times that we are going to use space;
                    for (i=0;i<s;i++)
                    {
                        printf(" ");
                    }
                    if (w==7)
                    {
                        printf("%d\n",d); //changing line on Saturday
                    }
                    else 
                    {
                        printf("%d",d);
                    }
                }
                //Printing all th other days.
                else 
                {
                    if (w==7)
                    {
                        printf("%3d\n",d); //Changing line on Saturday.
                    }
                    else if (w==1)
                    {
                        printf("%2d",d); 
                    }
                    else 
                    {
                        printf("%3d",d);
                    }
                }
        
            }
            printf("\n");
            return 0;
    }
    else 
    {
        printyear(y); //Fuction that prints the entire year
        return 0;
    }
}


int days_of_the_month(int month,int year) //Function that returns the number of days that a month has.
{
    //Case, months that have 31 days.
    if ((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))
    {
        return 31;
    }
    //Case, months that have 30 days.
    else if ((month==4)||(month==6)||(month==9)||(month==11))
    {
        return 30;
    }
    //Case, the month is February.
    else 
    {
        //if the year is before 1752.
        if (year<=1752)
        {
            if (year%4==0)
            {
                return 29;
            }
            else 
            {
                return 28;    
            }
        
        }
        
        //if the year is after 1752.
        else 
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
            {
                return 29;
            }
            else 
            {
                return 28;
            }
        }
    }
}


int get_dow(int day, int month, int year)//Function that returns the day of the week
{
    int w; //day of the week
    
    
    if (month==1)//Fixing the months January and Februrary.
    {
        month=13;
        year-=1;
    }
    if (month==2)
    {
        month=14;
        year-=1;
    }
    
    //Case, year>=1752
    if (year>=1752)
    {
        //Case, year==1752.
        if (year==1752) 
        {
            if (month>9)
            {
                w = (day+(13*(month+1))/5+year+year/4-year/100+year/400)%7;
                return w;
            }
            else if (month<9)
            {
                w= (day+(13*(month+1))/5+year+year/4+5)%7;
                return w;
            }
            if (month==9)
            {
                if ((day<=2))
                {
                    w= (day+(13*(month+1))/5+year+year/4+5)%7;
                    return w;
                }
                else if (day>=14)
                {
                     w = (day+(13*(month+1))/5+year+year/4-year/100+year/400)%7;
                    return w;
                }
                else 
                {
                    return -1; //Returns a day of the week that does not exist so that main prints nothing.
                }
            }
        }
        else
        {
             w = (day+(13*(month+1))/5+year+year/4-year/100+year/400)%7;
            return w;
        }
    }
    //Case, year<1752
    else 
    {
        w = (day+(13*(month+1))/5+year+(year/4)+5)%7;
        return w;
    }
    return -1;
}


void print_month_row(int month_start, int year, int value) //Function that prints a row of three months.
{
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    int max_days[3], start_days[3];
    for (int i = 0; i < 3; i++) 
    {
        max_days[i] = days_of_the_month(month_start + i, year); //Returns the number of the days that each month has.
        
        start_days[i] = get_dow(1, month_start + i, year); //Returns the starting day 1.
        if (start_days[i]==0)
        {
            start_days[i]=7;
        }
    }

    printf("         %s                     %s                   %s\n", months[month_start - 1], months[month_start], months[month_start + 1]);
   
    for (int i = 0; i < 3; i++)//Prints the days of the week
    {
        printf(" Su Mo Tu We Th Fr Sa  ");
    }
    printf("\n");

    //Prints days of the month
    int days[3] = {1, 1, 1}; //Sets the start for each month.
    
    while (days[0] <= max_days[0] || days[1] <= max_days[1] || days[2] <= max_days[2]) //Outer loop, ends when every month has been printed 
    {
        for (int i = 0; i < 3; i++) //The months.
        {
            
            if (days[i] == 1)//The staring day of each month
            {
                for (int j = 1; j < start_days[i]; j++) 
                {
                    printf("   ");
                }
            }

            for (int j = start_days[i]; j <= 7; j++) 
            {
               
                if (value==1 && i==2 && days[i]>2 && days[i] < 14)//Not printing the dates that do not exist.
                {
                    int w=get_dow(days[i],9,year);
                    if (w==-1)
                    {
                        days[i]+=11;
                        j--;
                        continue;
                    }
                }
                if (days[i] > max_days[i]) 
                {
                    printf("   ");
                } else 
                {
                    printf("%3d", days[i]);
                    days[i]++;
                }
            }
            start_days[i] = 1; // Reset start day for the next weeks
            printf("  ");
            
        }
        printf("\n");
       

    }
}


void printyear(int year)//Function that controls the months that are given to print_month_row(). 
{
    printf("                                 %d\n",year);
    for (int i = 0; i < 12; i += 3) 
    {
        if (i != 6)
        {
            print_month_row(i + 1, year,0); //Prints months by row. False (0) value when none of the months is Septemper.
            printf("\n");
        }
        else
        {
            print_month_row(i + 1, year,1); //Prints months by row. True (1) value when one of the months is Septemper.
            printf("\n");
        }
    }
}


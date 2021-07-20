//Author:
//Agyeya Mishra
//Department of Civil Engineering
//Delhi Technological University (formerly, Delhi College of Engineering)
//New Delhi, India


//C++ program to minimise cash flow among a set of friends who have borrowed money
#include <iostream>

using namespace std;

//Number of persons (or vertices in the graph)
#define number_of_persons 3

//A utility function that returns index of minimum value in array[]
int get_Minimum(int array[])
{
    int min_Index = 0;
    for(int i = 1; i < number_of_persons; i++)
    {
        if(array[i] < array[min_Index])
            min_Index = i;
    }
    
    //returns the index of the minimum value
    return min_Index;
}

//A utility function that returns index of maximum value in array[]
int get_Maximum(int array[])
{
    int max_Index = 0;
    for(int i = 1; i < number_of_persons; i++)
    {
        if(array[i] > array[max_Index])
            max_Index = i;    
    }
    
    //returns the index of maximum value
    return max_Index;
}

//A utility function to return minimum of 2 values
int minimum_of_two(int number1, int number2)
{
    if(number1 < number2)
        return number1;
    else
        return number2;
}

//amount[p] indicates the net amount to be credited or debited to r from person 'p'
//If amount[p] is positive, then ith person will take amount[i]
//If amount[p] is negative, then ith person will give -amount[i]

void minCashFlowRecursion(int amount[])
{
    //Find the index of minimum and maximum values in amount[]
    //amount[maxCredit] indicates the maximum amount to be given to (or credited to) any person 
    //amout[maxDebit] indicates the maximum amount to be taken (or debited) from any person
    //So, if there is a positive value in amount[], then there must be a negative value
    
    int maxCredit = get_Maximum(amount), maxDebit = get_Minimum(amount);
    
    //If both amounts are 0, then all amounts are settled
    if(amount[maxCredit] == 0 && amount[maxDebit] == 0)
        return;
        
    //Find the minimum of the two amounts
    int minimum = minimum_of_two(-amount[maxDebit], amount[maxCredit]);
    amount[maxCredit] -= minimum;
    amount[maxDebit] += minimum;
    
    //If minimum is the maximum amount to be
    cout<<"Person "<<maxDebit<<" pays "<<minimum<<" to "<<maxCredit<<"."<<endl;
    
    //Recur for the amount array. Note that it is guaranteed that the recursion would terminate as either amount[maxCredit] or amount[maxDebit] becomes 0
    minCashFlowRecursion(amount);
}

//Given a set of persons as graph[] where graph[i][j] indicates the amount that person i needs to pay person j, this function finds and prints the minimum cash flow to settle all debts
void minCashFlow(int graph[][number_of_persons])
{
    //Create an array amount[], initialize all value in it as 0
    int amount[number_of_persons] = {0};
    
    //Calculate the net amount to be paid to person 'p' and stores it in amount[p]
    //The value of amount[p] can be calculated by subtracting debts of 'p' from credits of 'p'
    
    for(int p = 0; p < number_of_persons; p++)
    {
        for(int i = 0; i < number_of_persons; i++)
        {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }
    
    minCashFlowRecursion(amount);
}

//Driver function
int main()
{
    //graph[i][j] indicates the amount that person i needs to pay person j
    
    int graph[number_of_persons][number_of_persons] = {{0, 1000, 2000},
                                                       {0, 0, 5000},
                                                       {0, 0, 0}};
    //print the solution
    minCashFlow(graph);
    
    return 0;
}

/*
We will use greedy approach as we have to optimize number of activities.

The greedy choice is to always pick the next activity whose finish time is 
least among the remaining activities and the start time is more than or equal 
to the finish time of the previously selected activity.

Algo:

1) Sort the activities according to their finishing time 

2) Select the first activity from the sorted array and print it.
 
3) Do the following for the remaining activities in the sorted array : 
    a) If the start time of this activity is greater than or equal to the finish 
	   time of the previously selected activity then select this activity and print it.
	   
I have used third argument of sort function in order to sort the structure array according to finish time
*/

#include<iostream>
#include<algorithm>  //to use sort()
#include<vector>    

using namespace std;

// Structure for storing starting time,finishing time and index number of activity of meeting (this will be printed).
struct Activity 
{
    int start_time;
    int end_time;
    int index;
};

// Comparator function which can compare the second element of structure used to sort pairs in increasing order of second value.
bool comparator(struct Activity a1,struct Activity a2)
{
	//returns true if condition holds
    return (a1.end_time<a2.end_time);
}

//our function that uses greedy approach
void max_activities(int s[],int f[],int n)
{
	//making a structure array
    struct Activity Act[n];
    
    //Feeding the structure array we just created above with input arrays by user
    for (int i=0;i<n;i++)
    {
        //Starting time of Activity i.
        Act[i].start_time=s[i];
         
        //Finishing time of Activity i
        Act[i].end_time=f[i];
         
        // Original position/index of Activity
        Act[i].index=i+1;
    }
 
    // Sorting of Activity according to their finish time. 3rd argument is what we created above in bool function
    sort(Act,Act+n,comparator);
    
    //_________________After sorting__________________
 
    // Using vector for storing selected Activity as we don't know size beforehand to store. Print this vector later
    vector<int> A;
 
    //Initially select first Activity bcoz its the one thats going to finish soon so that we can do more activities(greedy).
    A.push_back(Act[0].index);
 
    //time_limit to check whether new Activity can be conducted or not.
    int time_limit=Act[0].end_time;
 
    //Tarverse the struct array from 1st index and check whether the current activity can be selected or not.
    //The activity can be selected only if its starting time is less than or equal to time_limit
    for (int i=1;i<n;i++) 
	{
        if (Act[i].start_time>=time_limit)
        {
            //Push selected Activity to vector
            A.push_back(Act[i].index);
             
            //Update time limit so that we can select next activity
            time_limit=Act[i].end_time;
        }
    }
    
    // Print final selected Activities.
    cout<<"\nSelected activities in  terms of index numbers are => \n";
    for (int i=0;i<A.size();i++) 
	{
        cout<<" "<<A[i];
    }
}

int main()
{
	//Keeping input static as its just for testing purpose
	
	//Starting time
    int s[]={ 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[]={ 2, 4, 6, 7, 9, 9 };
     
    //Number of Activity.
    int n=5;
 
    //call our sunction
	max_activities(s,f,n);
	
return 0;
}

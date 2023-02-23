/*An airline company uses the formula shown below to determine the priority of passengers on the
waiting list for overbooked flights. Priority number = A / 1000 + B – C where,
A is the customer’s total mileage in the past year
B is the number of years in his or her frequent flier program
C is a sequence number representing the customer’s arrival position when he or she booked the
flight.
Given a file of overbooked customers as shown in below.The program that reads the file
and determines each customer’s priority number and build an application for the airline
company that builds a priority queue using the priority number and prints a list of waiting
customers in priority sequence*/
//Bryan Devaux 53,000 5 1
//Amanda Trapp 89,000 3 2
//Sarah Gilley 93,000 3 3
//Bacon Nguyen 17,000 1 4
//Warren Rexroad 72,000 7 5
//jorge Gonzales 65,000 2 6
//Paula Hung 34,000 3 7
//Lau masan 21,000 6 8
//steve chu 42,000 4 9
//Dave lightfoot 63,000 3 10
//joanne Brown 33,000 2 11

#include<stdio.h>
#include<iostream>
#include<string>
#define left(n)(2*n)
#define right(n)(2*n)+1
using namespace std;

struct passenger
{
    string name;
    int milage;
    int years;
    int sequence;

    passenger()
    {
        name="";
        milage=0;
        years=0;
        sequence=0;
    }

    int calcPriority()
    {
        int PriorityNumber = (((milage/1000)+years)-sequence);
        return PriorityNumber;
    }

    void printDetails()
    {
        cout<<"Passenger Details"<<endl;
        cout<<"Name: "<<name<<" Mileage:"<<milage<<" Year:"<<years<<" Sequence:"<<sequence<<endl;
        cout<<"Priority:"<<calcPriority()<<endl;
    }

};

bool compare(passenger &a, passenger &b)
{
    return a.calcPriority() < b.calcPriority();
}

template<typename T,bool(*comparetor)(T &a, T &b)>

struct Heap
{
    T arr[10000];
    int idx;

    Heap()
    {
        idx=0;
    }

    bool isEmpty()
    {
        return idx==0;
    }

    void Insert(T val)
    {
        idx++;
        arr[idx]=val;
        int temp=idx;
        while(temp>1 && comparetor(arr[temp],arr[temp/2]))
        {
            Swap(arr[temp],arr[temp/2]);
            temp=temp/2;

        }

    }

    void heapify(int node)
    {
        int changed=node;
        if(left(node)<=idx && comparetor(arr[left(node)],arr[changed]))
        {
            changed=left(node);
        }
        if(right(node)<=idx && comparetor(arr[right(node)],arr[changed]))
        {
            changed=right(node);
        }
        if(changed!=node)
        {
            Swap(arr[node],arr[changed]);
            heapify(changed);
        }
    }

    void Swap(T &a,T &b)
    {
        T temp;
        temp=a;
        a=b;
        b=temp;
    }

    void Delete()
    {
        if(isEmpty()==false)
        {
            Swap(arr[1],arr[idx]);
            idx--;
            heapify(1);
        }
    }

    T getTop()
    {
        return arr[1];
    }

};
template<typename T>
struct Stack
{
    T arr[10000];
    int TOP;

    Stack()
    {
        TOP = -1;
    }

    void push(T val)
    {
        TOP++;
        arr[TOP]=val;

    }

    void pop()
    {
        if(!isEmpty())
        {
            TOP--;
        }
        else
        {
            printf("stack is empty\n");
        }
    }

    T top()
    {
        return arr[TOP];
    }

    bool isEmpty()
    {
        if (TOP == -1)
        {
            return true;
        }
        else
        {

            return false;
        }

    }

    void printAll()
    {
        for(int i=0;i<=TOP;i++){
            arr[i].printDetails();
        }
    }
};

void parseInput(string str, string &name,int &milage, int &year, int &sequence)
{
    int spaceCount=0;
    for(int i=0 ; i<str.size() ; i++)
    {
        if(str[i]==' ')
        {
            spaceCount++;
        }
        if(spaceCount<2)
        {
            name+=str[i];
        }
        else if(spaceCount<3)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                milage=(milage*10)+str[i]-'0'; //'0-9'
            }
        }
        else if(spaceCount<4)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                year=(year*10)+str[i]-'0';
            }
        }
        else
        {
            if(str[i]>='0' && str[i]<='9' )
            {
                sequence=(sequence*10)+str[i]-'0';
            }
        }

    }
}

int main()
{
    Stack<passenger> stk = Stack<passenger>();
    Heap<passenger,compare> minHeap;
    passenger temp;
    int ticketCount;
    cout<<"\t\t\t" << "Welcome To The Program Of Resolving Overbooked Flight\n\n"<< endl;
    cout<< "\t Please Enter Name Mileage Years and Sequence of passenger\n\n"<<endl;
    string str;
    char arr[200];

    while(gets(arr))
    {
        temp = passenger();
        parseInput(string(arr),temp.name,temp.milage,temp.years,temp.sequence);
        minHeap.Insert(temp);
        fflush(stdin);
    }

    while(minHeap.isEmpty()==false)
    {
        stk.push(minHeap.getTop());
        minHeap.Delete();
    }

    stk.printAll();
    cout<<endl<<endl;
    cout<<"\t\t How Many Tickets Available ?" <<endl;
    cin>>ticketCount;
    cout<<"\t\tFollowing People will Get Tickets:\n"<<endl;

    for(int i=0;i<ticketCount;i++){
        if(stk.isEmpty()){
            break;
        }
        stk.top().printDetails();
        stk.pop();
    }

    cout<<endl<<endl;

    if(stk.isEmpty()){
        cout<<"\t\tEveryone Received Tickets\n"<<endl;
    }
    else{
        cout<<"\t\tThese people will catch the next flight\n"<<endl;
        while(stk.isEmpty()==false){
            stk.top().printDetails();
            stk.pop();
        }
    }

    return 0;
}


#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sys/time.h>
#include<sstream>
#include "tree.h"
#include "rbt.cpp"
#include "bst.cpp"
#include "tree.cpp"
using namespace std;

int main(int argc, char *argv[])
{
int choice,ext,delkey,inskey,srchkey;
char *dictfile,*locfile,*timeinsfile,*timesrchfile;
Dict *obj; ///Creating object of Dict class (Base Class)
BST bt;///Creating object of class Binary Search Tree(Derived class)
RBT rt; ///Creating object of class Redblack tree(Derived class)
ext=0;
if(strcmp(argv[1],"-bst")==0)
	choice=1;
else
	choice=2;

switch(choice)
{
  case 1:

	///For Binary search tree


        obj=&bt;///Setting the base class object as BST object
	dictfile= argv[2];
	locfile =argv[3];
timeinsfile =NULL;
timesrchfile =NULL;

if(argc==7)
{
	if(strcmp(argv[4],"-t") ==0){
		timeinsfile =argv[5];
		timesrchfile =argv[6];
	}
        else{
		timeinsfile =NULL;
		timesrchfile =NULL;
	}
}
	break;
  case 2:	///For Red Black tree
	obj=&rt;///Setting the base class object as RBT object
      
	dictfile= argv[1];
	locfile =argv[2];
timeinsfile =NULL;
timesrchfile =NULL;
if(argc==6)
{
	if(strcmp(argv[3],"-t") ==0){
		timeinsfile =argv[4];
		timesrchfile =argv[5];
	}else{
		timeinsfile =argv[3];
		timesrchfile =argv[4];
	}
}
	break;
default: 
	cout<<"Enter a either 1 or 2\n";
 
} /// end of switch
obj->PopulateDict(dictfile,timeinsfile);
obj->LocateDict(locfile,timesrchfile);
do{

/*******************************MENU***************************/
cout<<"\n*****************************************************\n";
cout<<"Enter \n1 - Insert \n2 - Delete\n3 - Search\n4 - Display\n5 - Clear\n6 - Exit\n";
cin>>ext;
/*************************************************************/
switch(ext)
{
  																																																																											case 1:		///To Insert

        cout<<"Enter Key to Insert\n";
	cin>>inskey;
	obj->Insert(inskey);
	cout<<"Key "<<inskey<<" Inserted\n";
	break;
        case 2:		///To Delete
	cout<<"Enter Key to Delete\n";
	cin>>delkey;
	if(obj->Delete(delkey)) {cout<<"Key "<<delkey<<" Deleted\n";}
		else	{cout<<"Key "<<delkey<<" Not Found\n";}
	break;
        case 3:		///To Search
	cout<<"Enter Key to Search\n";
	cin>>srchkey;
	if(obj->Search(srchkey)){ ///Searching Values in the corresponding data structure
		cout<<"Search Key "<<srchkey<<" Found\n";
	}
	else{
		cout<<"Search Key "<<srchkey<<" Not Found\n";
	}
	break;
   case 4:		///To Display
	obj->Display();
	break;
   case 5:		///To Clear List
	obj->ClearADT();
	break;
   case 6: exit(0); 
    break;
   default:
   cout<<"SOMETHING WRONG ENTER CORRECT OPTION"<<ext;
   break;
}
}while(ext!=6);
return 0;
}

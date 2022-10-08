#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sys/time.h>
#include<sstream>

/**
* Function Name : PopulateDict(char *dictfile,char *timeinsert)
*
*Input:	Arguments	Datatype	Description

*	dictfile	char*		Filename of file which contain keys to insert
*
*	timeinsert	char*		Filename of file where we stores the execution time of insertion 
*
* Return NULL
*
* Purpose: 1) Read Dictionary file(given as command line argument)
*
*	   2) Input the Key values in the file to corresponding datastructure
*
*	   3) Evaluate time taken for insertion
*
*	   4) Store the evaluated time to a file(name given as commandline argument) for each set of inputs
*
*
 */



void Dict::PopulateDict(char *dictfile,char *timeinsert)
{
	ifstream in (dictfile); ///Creating file pointer for dictionary file
	ofstream out (timeinsert,std::ios_base::app);///Creating file pointer for timeinsert file
   	timeval t1, t2;
	double elapsedTime=0.00;
	string line; ///String variable line stores the line reading from file
	int i,count,j,key;
	count=0;
	int val;

	if(in.is_open()){ ///File Checking
	while(getline(in,line)!=NULL) ///Reading Line
	{
		std::istringstream buffer(line);
		buffer >> val; ///Store the values into val
		gettimeofday(&t1, NULL);
		Insert(val);///Inserting Value
		gettimeofday(&t2, NULL);
	    elapsedTime += (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
		count++; ///Setting count
	}}
	in.close();

	if(timeinsert!=NULL)
	{
	out <<count<<"\t"<<elapsedTime<<"\n"; ///Storing the time
	}
}

/**
* Function Name : LocateDict(char *locfile,char *timesearch)
*
*Input:	Arguments	Datatype	Description
*
*
*	locfile		char*		Filename of file which contain Search keys
*
*	timesearch	char*		Filename of file where we stores the execution time of searching
*
* Return NULL
*
* Purpose: 1) Read file(given as command line argument) that contains values to search
*	 2) Search key values in the file to corresponding datastructure
*	 3) Evaluate time taken for searching
*	 4) Store the evaluated time to a file(name given as commandline argument) for each set of inputs
*
*
 */


void Dict::LocateDict(char *locfile,char *timesearch){
	ifstream in (locfile);///Setting the file pointer of locfile
	ofstream out (timesearch,std::ios_base::app);///Creating file pointer for timeinsert file
   	timeval t1, t2;
	float elapsedTime =0.00;
	string line; ///String variable line stores the line reading from file
	int val;
	int count,i,j;
	count=0;
	bool s_key;

	
	if(in.is_open()){ ///File Checking
	while(getline(in,line)!=NULL) ///Reading Line
	{
		std::istringstream buffer(line);
		buffer >> val; ///Store the values into array val

		gettimeofday(&t1, NULL);
		s_key =Search(val);
		gettimeofday(&t2, NULL);

	    elapsedTime += (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
		if(s_key ==false){ ///Searching Values in the corresponding data structure
//			cout<<"Search Key "<<val<<" Found\n";

			cout<<"Search Key "<<val<<" Not Found\n";
		}
		count++; ///Setting count
	}}
	in.close();
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
//	elapsedTime = elapsedTime/(count);
	if(timesearch!=NULL)
	{
	out <<count<<"\t"<<elapsedTime<<"\n"; ///Storing the time
	}


} 


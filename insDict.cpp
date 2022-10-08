#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<sstream>

using namespace std;
int GetRand(int min, int max);

int main()
{
	int i;
	ofstream out ("dictionary10.txt");
	for(i=0;i<20;i++){
	out << GetRand(0,20)<<"\n";
	}
	ofstream out1 ("locate10.txt");
	for(i=0;i<500;i++){
	out1 << GetRand(0,500)<<"\n";
	}
}

/* 
int GetRand(int min, int max)

{

  static int Init = 0;

  int rc;

  

  if (Init == 0)

  {

    srand(time(NULL));

    Init = 1;

  }



  rc = (rand() % (max - min + 1) + min);

  

  return (rc);

} */

#include <iostream>
#include <stdlib.h>
#include <csignal>
#include <setjmp.h>
using namespace std;

jmp_buf return_to_top_level;

//We can do something in the handler.
static void handler(int signum){
	cout <<"Signal  "<<signum <<" here!"<<endl;
	//change SIGFPE to the Default Value	
	signal(SIGFPE, SIG_IGN);
	longjmp (return_to_top_level, 1);
}

int main(){
	signal(SIGFPE,handler);
	
	if (setjmp (return_to_top_level) == 0){
		int d = 5;
		d = d/(d-5);
	}

	cout <<"I want this line to be printed."<<endl;
	return 0;
}

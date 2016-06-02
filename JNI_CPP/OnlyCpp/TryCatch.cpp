#include <iostream>
#include <stdio.h>
using namespace std;

int main(){	
	try{
		int d = 5;
		if (d-5 == 0){
			throw(23333);		
		}
		d = d/(d-5);
	}
	catch(int e){
		cout << "Caught divide by zero exception: "<<e<<endl;
	}

	return 0;
}

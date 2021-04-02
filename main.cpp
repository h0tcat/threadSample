#include "MultiThread.h"

int main(int argc,char** argv){
	
	if(argc!=2){
		std::cerr << "Usage: multithreadsample N" << std::endl;
		return -1;
	}else{

		size_t amountThread=std::stoi(argv[1]);
		nori::MultiThread multiThreadSample(amountThread);

		multiThreadSample.Start();
	}
	return 0;
}

#include "MultiThread.h"

nori::MultiThread::MultiThread(){
	
	this->amountThread=2;
	
	nori::MultiThread(this->amountThread);
}

nori::MultiThread::MultiThread(size_t amountThread){
	
	this->count=0;
	this->amountThread=amountThread;
	
	this->threads = new std::vector<std::thread>(this->amountThread);
	for(auto& thread : *this->threads){
		thread=std::thread([=](){
				while(this->count<500000){
					this->count++;
					std::cout << this->count << std::endl;
				}
			}
		);
	}
}

nori::MultiThread::~MultiThread(){
	delete this->threads;
}

void nori::MultiThread::Start(){
	std::lock_guard<std::mutex> lock(this->mtx);
	for(auto& thread : *this->threads){
		thread.join();
	}
}


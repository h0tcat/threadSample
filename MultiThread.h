#ifndef __MULTITHREAD_SAMPLE_H__
#define __MULTITHREAD_SAMPLE_H__

#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

namespace nori{
	class MultiThread{
		public:
			MultiThread();
			MultiThread(size_t amountThread);
			~MultiThread();
			
			void Start();

		protected:
			size_t amountThread;
			std::vector<std::thread>* threads;
			std::mutex mtx;
		
		private:

			int count;
	};
};
#endif



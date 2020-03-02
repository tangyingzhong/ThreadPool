#include <iostream>
#include "IThreadPool.h"
#include "ThreadPool.h"

void RunTask(void* pUser)
{
	(void)(pUser);

	std::cout << "Run task now" << std::endl;
}

void RunTask1(void* pUser)
{
	(void)(pUser);

	std::cout << "Run task1 now" << std::endl;
}

int main()
{
	IThreadPool* pPool = new ThreadPool(1024);
	if (pPool==nullptr)
	{
		return -1;
	}

	pPool->Start();

	TaskEntry taskEntity;

	taskEntity.iTaskId = 100;

	taskEntity.pFunc = RunTask;

	taskEntity.pUser = nullptr;

	pPool->AddTask(taskEntity);

	TaskEntry taskEntity1;

	taskEntity1.pFunc = RunTask1;

	taskEntity1.iTaskId = 101;

	taskEntity1.pUser = nullptr;

	pPool->AddTask(taskEntity1);

	getchar();

	pPool->Stop(false);

	delete pPool;

	pPool = nullptr;

    return 0;
}
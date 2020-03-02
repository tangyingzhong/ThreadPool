///************************************************************************
/// <copyrigth>Voice AI Technology Of ShenZhen</copyrigth>
/// <author>tangyingzhong</author>
/// <contact>yingzhong@voiceaitech.com</contact>
/// <version>v1.0.0</version>
/// <describe>
///
///</describe>
/// <date>2020/2/28</date>
///***********************************************************************
#ifndef ITHREADPOOL_H
#define ITHREADPOOL_H

#include <string>

struct TaskEntry
{
	using TaskCallbackFunc = void(*)(void*);

	// Task id
	int iTaskId;

	// Task callback function
	TaskCallbackFunc pFunc;

	// User data
	void* pUser;
};

class MyThread;

class IThreadPool
{
public:
	// Detructe the IThreadPool
	virtual ~IThreadPool(){	}
	
public:
	// Start pool
	virtual void Start() = 0;

	// Stop pool
	virtual int Stop(bool bForce) = 0;

	// Add Task to pool
	virtual int AddTask(TaskEntry& task) = 0;

	// Transfer thread to container
	virtual bool Transfer(MyThread* pThread) = 0;

	// Get error message
	virtual std::string GetErrorMsg() = 0;
};

#endif // ITHREADPOOL_H

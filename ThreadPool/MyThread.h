///************************************************************************
/// <copyrigth>Voice AI Technology Of ShenZhen</copyrigth>
/// <author>tangyingzhong</author>
/// <contact>yingzhong@voiceaitech.com</contact>
/// <version>v1.0.0</version>
/// <describe>
/// This is c++11 thread
///</describe>
/// <date>2020/2/28</date>
///***********************************************************************
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <thread>
#include "IThreadPool.h"

class MyThread:public std::thread
{
public:
	// Construct the MyThread
	MyThread(IThreadPool* pThreadPool);
	
	// Detructe the MyThread
	virtual ~MyThread();
	
private:
	// Forbid the copy MyThread
	MyThread(const MyThread& other)=delete;
	
	// Forbid the assigment of MyThread
	MyThread& operator=(const MyThread& other)=delete;
	
public:
	// Set thread detach
	void SetDetachState(bool bIsDetach);

	// Get thread id
	unsigned long long GetThreadId();

	// Start the thread
	void Start();

	// Get the ThreadId
	inline int GetId() const
	{
		return m_iThreadId;
	}

	// Set the ThreadId
	inline void SetId(int iThreadId)
	{
		m_iThreadId = iThreadId;
	}

	// Set the Task
	inline void SetTask(TaskEntry& task)
	{
		m_Task = task;
	}

private:
	// Run the thread
	void Run();

private:
	// Get the disposed status
	inline bool GetDisposed() const
	{
		return m_bDisposed;
	}
	
	// Set the disposed status
	inline void SetDisposed(bool bDisposed)
	{
		m_bDisposed = bDisposed;
	}

	// Get the IsDetached
	inline bool GetIsDetached() const
	{
		return m_bIsDetached;
	}

	// Set the IsDetached
	inline void SetIsDetached(bool bIsDetached)
	{
		m_bIsDetached = bIsDetached;
	}

	// Get the ThreadPool
	inline IThreadPool* GetThreadPool() const
	{
		return m_pThreadPool;
	}

	// Set the ThreadPool
	inline void SetThreadPool(IThreadPool* pThreadPool)
	{
		m_pThreadPool = pThreadPool;
	}

private:
	// Thread id
	int m_iThreadId;
	
	// Thread pool
	IThreadPool* m_pThreadPool;
	
	// Task
	TaskEntry m_Task;

	// Current thread
	std::thread m_CurThread;

	// Thread detach state
	bool m_bIsDetached;
	
	// Disposed status
	bool m_bDisposed;	
};

#endif // MYTHREAD_H

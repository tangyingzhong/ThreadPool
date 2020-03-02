#include <stdio.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include "MyThread.h"

// Construct the MyThread
MyThread::MyThread(IThreadPool* pThreadPool):m_pThreadPool(pThreadPool),
	m_bIsDetached(true),
	m_bDisposed(false)
{

}

// Detructe the MyThread
MyThread::~MyThread()
{
	if (!GetDisposed())
	{
		SetDisposed(true);
	}
}

// Set thread detach
void MyThread::SetDetachState(bool bIsDetach)
{
	SetIsDetached(bIsDetach);
}

// Get thread id
unsigned long long MyThread::GetThreadId()
{
	std::thread::id tid= std::this_thread::get_id();

	std::stringstream stream;

	stream << tid;

	std::string strThreadId = stream.str();

	unsigned long long threadId= std::stoull(strThreadId);

	return threadId;
}

// Run the thread
void MyThread::Run()
{
	m_Task.pFunc(m_Task.pUser);

	// Add current thread to idel container again
	if (GetThreadPool())
	{
		GetThreadPool()->Transfer(this);
	}
}

// Start the thread
void MyThread::Start()
{
	m_CurThread = std::thread(&MyThread::Run, this);

	if (GetIsDetached())
	{
		m_CurThread.detach();
	}
	else
	{
		m_CurThread.join();
	}
}

#include "Sleep.h"
#include <QObject>

#ifdef Q_OS_WIN32
#include <windows.h>
#elif defined(Q_OS_LINUX)
#include <unistd.h>
#elif defined(Q_OS_MAC)
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>
#endif

void Sleep::sleep(unsigned long secs)
{
#ifdef Q_OS_WIN32
    ::Sleep(secs);
#elif defined(Q_OS_LINUX)
//    struct timeval tv;
//    gettimeofday(&tv, 0);
//    struct timespec ti;
//    ti.tv_sec = tv.tv_sec + secs;
//    ti.tv_nsec = (tv.tv_usec);
//    thread_sleep(&ti);
	usleep(1000*secs);
#elif defined(Q_OS_MAC)
	usleep(1000*secs);
#endif
}

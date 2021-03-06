#ifndef _SINGLE_INSTANCE_H_
#define _SINGLE_INSTANCE_H_

#include <cstdint>
#include <string>
#include <core/noncopyable.h>

#ifdef _WIN32
#include <windows.h>
#endif

namespace core
{
class SingleInstance : public core::NonCopyable
{
    public:

        explicit SingleInstance(int singleInstancePort = 666);
        ~SingleInstance();

        // Move ctor deletion
        SingleInstance(SingleInstance&& other) = delete;
        // Move assignment operator deletion
        SingleInstance& operator=(SingleInstance&& other) = delete;

        bool operator()();

    private:

#ifdef __linux__
        int m_socketFD = -1;
        int m_rc;
        uint16_t m_port;
#elif _WIN32
        HANDLE m_mutex;
        unsigned long  m_lastError;
#endif
};

}//namespace
#endif
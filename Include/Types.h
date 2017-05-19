#pragma once

namespace spdlog
{
    namespace sinks
    {

        enum class FilterType
        {
            RemoteServiceStart,
            RemoteServiceStop,
            RemoteServiceDisconnect,
            RemoteServiceConnect,
            RemoteServiceSessionLogon,
            RemoteServiceSessionLogoff,
            RemoteServicePause,
            RemoteServiceResume,
            RemoteServiceLock,
            RemoteServiceUnlock,
            RemoteServiceConsoleConnect,
            RemoteServiceConsoleDisconnect,
            ProcessObserver,
            InactivityWatcher,
            CommunicatonServer,
            GlobalCommunicationClient,
            GlobalCommunicationServer,
            GlobalCommunicationThread,
            LocalCommunicationClient,
            LocalCommunicationServer,
            NON,

        };
    }
}
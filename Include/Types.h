#pragma once

namespace spdlog
{
    namespace sinks
    {

        enum class FilterType
        {
            RemoteServiceUnspecific,
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
            ShutdownHandler,
            CommunicatonServer,
            GlobalCommunicationClient,
            GlobalCommunicationServer,
            GlobalCommunicationThread,
            LocalCommunicationClient,
            LocalCommunicationServer,
            WtsSession,
            WtsSessionMananger,
            NON,

        };
    }
}
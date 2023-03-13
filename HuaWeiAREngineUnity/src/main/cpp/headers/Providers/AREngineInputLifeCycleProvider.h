
#ifndef AREngineInputLifeCycleProvider_202303091956_H
#define AREngineInputLifeCycleProvider_202303091956_H
#include "ProviderInterface/IUnityXRInput.h"

class AREngineInputLifeCycleProvider
{
private:
    static IUnityXRInputInterface *s_XrInput;

public:
    /// Initialize the subsystem.
    ///
    /// @param handle Handle for the current subsystem which can be passed to methods related to that subsystem.
    /// @param data Value of userData field when provider was registered.
    /// @return Status of function execution.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API Initialize(UnitySubsystemHandle handle, void *data);
    /// Start the subsystem.
    ///
    /// @param handle Handle for the current subsystem which can be passed to methods related to that subsystem.
    /// @param data Value of userData field when provider was registered.
    /// @return Status of function execution.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API Start(UnitySubsystemHandle handle, void *data);
    /// Stop the subsystem.
    ///
    /// @param handle Handle for the current subsystem which can be passed to methods related to that subsystem.
    /// @param data Value of userData field when provider was registered.
    static void UNITY_INTERFACE_API Stop(UnitySubsystemHandle handle, void *data);
    /// Shutdown the subsystem.
    ///
    /// @param handle Handle for the current subsystem which can be passed to methods related to that subsystem.
    /// @param data Value of userData field when provider was registered.
    static void UNITY_INTERFACE_API Shutdown(UnitySubsystemHandle handle, void *data);

    static void Register(IUnityInterfaces *unityInterfaces);
};

#endif
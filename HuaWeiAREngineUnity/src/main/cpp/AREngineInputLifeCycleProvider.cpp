#include "Providers/AREngineInputLifeCycleProvider.h"
#include "Providers/AREngineInputProvider.h"
IUnityXRInputInterface* AREngineInputLifeCycleProvider::s_XrInput=NULL;
UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputLifeCycleProvider::Initialize(UnitySubsystemHandle handle, void *data)
{
    UnityXRInputProvider inputProvider;
    inputProvider.userData = nullptr;
    inputProvider.Tick = &AREngineInputProvider::Tick;
    inputProvider.FillDeviceDefinition = &AREngineInputProvider::FillDeviceDefinition;
    inputProvider.UpdateDeviceConfig = &AREngineInputProvider::UpdateDeviceConfig;
    inputProvider.UpdateDeviceState = &AREngineInputProvider::UpdateDeviceState;
    inputProvider.HandleEvent = &AREngineInputProvider::HandleEvent;
    inputProvider.HandleRecenter = &AREngineInputProvider::HandleRecenter;
    inputProvider.HandleHapticImpulse = AREngineInputProvider::HandleHapticImpulse;
    inputProvider.HandleHapticBuffer = &AREngineInputProvider::HandleHapticBuffer;
    inputProvider.QueryHapticCapabilities = &AREngineInputProvider::QueryHapticCapabilities;
    inputProvider.HandleHapticStop = &AREngineInputProvider::HandleHapticStop;
    inputProvider.QueryTrackingOriginMode = &AREngineInputProvider::QueryTrackingOriginMode;
    inputProvider.QuerySupportedTrackingOriginModes = &AREngineInputProvider::QuerySupportedTrackingOriginModes;
    inputProvider.HandleSetTrackingOriginMode = &AREngineInputProvider::HandleSetTrackingOriginMode;
    inputProvider.TryGetDeviceStateAtTime = &AREngineInputProvider::TryGetDeviceStateAtTime;
    return s_XrInput->RegisterInputProvider(handle, &inputProvider);
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputLifeCycleProvider::Start(UnitySubsystemHandle handle, void *data)
{
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

void UNITY_INTERFACE_API AREngineInputLifeCycleProvider::Stop(UnitySubsystemHandle handle, void *data)
{
}

void UNITY_INTERFACE_API AREngineInputLifeCycleProvider::Shutdown(UnitySubsystemHandle handle, void *data)
{
}

void AREngineInputLifeCycleProvider::Register(IUnityInterfaces *unityInterfaces)
{
    s_XrInput = unityInterfaces->Get<IUnityXRInputInterface>();
    UnityLifecycleProvider inputLifeCycleProvider;
    inputLifeCycleProvider.userData = nullptr;
    inputLifeCycleProvider.Initialize = &AREngineInputLifeCycleProvider::Initialize;
    inputLifeCycleProvider.Start = &AREngineInputLifeCycleProvider::Start;
    inputLifeCycleProvider.Stop = &AREngineInputLifeCycleProvider::Stop;
    inputLifeCycleProvider.Shutdown = &AREngineInputLifeCycleProvider::Shutdown;
    s_XrInput->RegisterLifecycleProvider("huaweiarengineunity", "arengine-Input", &inputLifeCycleProvider);
}
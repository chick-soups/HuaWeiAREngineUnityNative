
#include "Providers/AREngineInputProvider.h"
#include "ProviderInterface/UnitySubsystemTypes.h"
#include "ProviderInterface/IUnityXRInput.h"

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::Tick(UnitySubsystemHandle handle, void *userData, UnityXRInputUpdateType updateType)
{
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}
UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::FillDeviceDefinition(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceDefinition *definition)
{
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::UpdateDeviceConfig(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceConfig *config)
{
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::UpdateDeviceState(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputUpdateType updateType, UnityXRInputDeviceState *state) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::HandleEvent(UnitySubsystemHandle handle, void *userData, unsigned int eventType, UnityXRInternalInputDeviceId deviceId, void *buffer, unsigned int size) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::HandleRecenter(UnitySubsystemHandle handle, void *userData) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::HandleHapticImpulse(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, int channel, float amplitude, float duration) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::HandleHapticBuffer(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, int channel, unsigned int bufferSize, const unsigned char *const buffer) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::QueryHapticCapabilities(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRHapticCapabilities *capabilities) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::HandleHapticStop(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::QueryTrackingOriginMode(UnitySubsystemHandle handle, void *userData, UnityXRInputTrackingOriginModeFlags *trackingOriginMode) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::QuerySupportedTrackingOriginModes(UnitySubsystemHandle handle, void *userData, UnityXRInputTrackingOriginModeFlags *supportedTrackingOriginModes) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::HandleSetTrackingOriginMode(UnitySubsystemHandle handle, void *userData, UnityXRInputTrackingOriginModeFlags trackingOriginMode) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

UnitySubsystemErrorCode UNITY_INTERFACE_API AREngineInputProvider::TryGetDeviceStateAtTime(UnitySubsystemHandle handle, void *userData, UnityXRTimeStamp time, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceState *state) {
    UnitySubsystemErrorCode errorCode(kUnitySubsystemErrorCodeSuccess);
    return errorCode;
}

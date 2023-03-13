#ifndef AREngineInputProvider_202303091958_H
#define AREngineInputProvider_202303091958_H
#include "ProviderInterface/IUnityXRInput.h"
class AREngineInputProvider
{
public:
    void *userData;

     /// A call from Unity at the beginning of each device update pass.  Device's update twice a frame: once before the Monobehaviour::UpdateLoop and once right before rendering.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] updateType The type of tick this is, to help providers get reference for when in a frame this is being called.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API Tick(UnitySubsystemHandle handle, void *userData, UnityXRInputUpdateType updateType);

    /// Unity requesting the provider to fill in connected device information on a device that has been reported as connected.  Used to create customized device states.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The Id of the device that needs a definition filled
    /// @param[in] definition The definition to be filled by the plugin
    static UnitySubsystemErrorCode UNITY_INTERFACE_API FillDeviceDefinition(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceDefinition *definition);
    
    /// Unity responding to a request to update a device's configuration.  This is triggered by calling IUnityXRInputInterface::InputSubsystem_DeviceConfigChanged.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The Id of the device that needs a it's configuration changed.
    /// @param[in] config The configuration to be filled by the plugin.
    /// @return kUnitySubsystemErrorCodeSuccess The config was successfully updated.
    /// @return kUnitySubsystemErrorCodeFailure The config could not be updated.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API UpdateDeviceConfig(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceConfig *config);
     /// A call from Unity when it needs a snapshot of a specific device's state.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The Id of the device whose state is requested.
    /// @param[in] updateType The type of update being polled for.   For BeforeRender we are predominantly interested in pose data, in the time expected for rendering
    /// @param[in] state The customized DeviceState to fill in.  The indices within this state match the order those input features were added from FillDeviceDefinition
    static UnitySubsystemErrorCode UNITY_INTERFACE_API UpdateDeviceState(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRInputUpdateType updateType, UnityXRInputDeviceState *state);
  /// Simple, generic method callback to inform the plugin or individual devices of events occurring within unity
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] eventType The type of event being sent
    /// @param[in] deviceId The Id of the device that should handle the event.  Will be kUnityInvalidXRInputFeatureIndex if event is for all devices.
    /// @param[in] buffer An in/out payload of data.  The contents are dictated by the eventType.  See UnityXRInputEventType for details of each payload.
    /// @param[in] size The size of the buffer payload.  This can be used to verify that the type is actually what was expected.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API HandleEvent(UnitySubsystemHandle handle, void *userData, unsigned int eventType, UnityXRInternalInputDeviceId deviceId, void *buffer, unsigned int size);
/// A call from Unity when the developer requests a recenter.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @return kUnitySubsystemErrorCodeSuccess The provider was successfully recentered.
    /// @return kUnitySubsystemErrorCodeFailure The provider was unable to recenter.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API HandleRecenter(UnitySubsystemHandle handle, void *userData);
 /// A call from Unity when the developer requests a haptic impulse or rumble.  This should only be processed if the device reports that it supports haptic impulses via QueryHapticCapabilities.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The input device that the message is being directed to.
    /// @param[in] channel The haptic channel that the impulse is requested for.
    /// @param[in] amplitude The requested amplitude in a [0,1] range.
    /// @param[in] duration The >0 duration that the impulse is requested for.
    /// @return kUnitySubsystemErrorCodeSuccess The provider will trigger the haptic impulse on the specified device.
    /// @return kUnitySubsystemErrorCodeFailure The provider will not be triggering the haptic impulse.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API HandleHapticImpulse(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, int channel, float amplitude, float duration);
 /// A call from Unity when the developer is requesting a buffered haptic effect on an input device.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The input device that the message is being directed to.
    /// @param[in] channel The haptic channel that the impulse is requested for.
    /// @param[in] buffer The haptic buffer to process with samples in a [0,255] range.
    /// @param[in] bufferSize The number of samples being sent in the buffer variable.
    /// @return kUnitySubsystemErrorCodeSuccess The provider will successfully process the haptic buffer.
    /// @return kUnitySubsystemErrorCodeFailure The provider will not process the haptic buffer.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API HandleHapticBuffer(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, int channel, unsigned int bufferSize, const unsigned char *const buffer);
  /// A call from Unity to request the haptic capabilities of a device.  The provider is expected to fill in the UnityXRHapticCapabilities struct that is passed in.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The input device that the message is being directed to.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API QueryHapticCapabilities(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId, UnityXRHapticCapabilities *capabilities);
 /// A call from Unity when the developer requests a stop of all haptic effects on a specific device.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] deviceId The input device that the message is being directed to.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API HandleHapticStop(UnitySubsystemHandle handle, void *userData, UnityXRInternalInputDeviceId deviceId);
/// A call from Unity requesting the current tracking origin mode.  The provider is expected to set the UnityXRInputTrackingOrigin variable with the current tracking mode.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] trackingOriginMode The tracking origin mode that the provider is currently in.
    /// @return kUnitySubsystemErrorCodeSuccess The trackingOrigin was successfully retrieved.
    /// @return kUnitySubsystemErrorCodeFailure The trackingOrigin could not be retrieved.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API QueryTrackingOriginMode(UnitySubsystemHandle handle, void *userData, UnityXRInputTrackingOriginModeFlags *trackingOriginMode);
  /// A call from Unity requesting the supported tracking origin modes.  The provider is expected to set the UnityXRInputTrackingOrigin variable with all supported modes.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] supportedTrackingOriginModes Bitwise or of all supported tracking origin modes.
    /// @return kUnitySubsystemErrorCodeSuccess All supported tracking origins were successfully retrieved.
    /// @return kUnitySubsystemErrorCodeFailure The supported tracking origins could not be retrieved.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API QuerySupportedTrackingOriginModes(UnitySubsystemHandle handle, void *userData, UnityXRInputTrackingOriginModeFlags *supportedTrackingOriginModes);
 /// A call from Unity when the developer wants to set a new tracking origin mode.
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData User specified data.
    /// @param[in] trackingOriginMode The tracking origin mode that the developer wants to set the provider to.
    /// @return kUnitySubsystemErrorCodeSuccess The tracking origin was successfully set.
    /// @return kUnitySubsystemErrorCodeInvalidArguments The tracking origin is not of a type supported by the provider via QuerySupportedTrackingOriginModes.
    /// @return kUnitySubsystemErrorCodeFailure Any other situation where the tracking origin was not able to be set.
    static UnitySubsystemErrorCode UNITY_INTERFACE_API HandleSetTrackingOriginMode(UnitySubsystemHandle handle, void *userData, UnityXRInputTrackingOriginModeFlags trackingOriginMode);
    /// Unity calls this when requesting a state at a specific time in the past
    ///
    /// @param[in] handle Handle obtained from UnityLifecycleProvider callbacks.
    /// @param[in] userData Custom data set when registering the provider
    /// @param[in] time The historical time Unity requests the state from
    /// @param[in] deviceId The Id of the device whose state is requested.
    /// @param[in] state The Device State that the provider must fill in.  The indices within this state match the order those input features were added from FillDeviceDefinition
    /// @return kUnitySubsystemErrorCodeSuccess State block successfully generated
    /// @return kUnitySubsystemErrorCodeFailure Holographic space is not available
    /// @return kUnitySubsystemErrorCodeFailure Unable to build historic state data
    /// @return kUnitySubsystemErrorCodeInvalidArguments the state provided is null
    static UnitySubsystemErrorCode UNITY_INTERFACE_API TryGetDeviceStateAtTime(UnitySubsystemHandle handle, void *userData, UnityXRTimeStamp time, UnityXRInternalInputDeviceId deviceId, UnityXRInputDeviceState *state);
};
#endif
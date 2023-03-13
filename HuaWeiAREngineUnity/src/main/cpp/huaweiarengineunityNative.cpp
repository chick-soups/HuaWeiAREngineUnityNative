#include <jni.h>
#include <string>

#include "ProviderInterface/IUnityInterface.h"
#include "Providers/AREngineInputLifeCycleProvider.h"


extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
UnityPluginLoad(IUnityInterfaces *unityInterfaces)
{
    AREngineInputLifeCycleProvider::Register(unityInterfaces);
}
extern "C" void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API
UnityPluginUnload()
{

}
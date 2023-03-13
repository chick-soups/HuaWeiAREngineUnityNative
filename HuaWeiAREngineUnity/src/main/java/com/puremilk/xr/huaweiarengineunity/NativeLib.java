package com.puremilk.xr.huaweiarengineunity;

public class NativeLib {

    // Used to load the 'huaweiarengineunity' library on application startup.
    static {
        System.loadLibrary("huaweiarengineunity");
    }

    /**
     * A native method that is implemented by the 'huaweiarengineunity' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
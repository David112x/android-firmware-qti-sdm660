/**
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 **/

package com.qualcomm.qti.modemtestmode;

import java.io.UnsupportedEncodingException;

import android.app.Application;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Handler;
import android.util.Log;

import com.qualcomm.qcrilhook.QcRilHook;
import com.qualcomm.qcrilhook.QcRilHookCallback;

import org.codeaurora.telephony.utils.Registrant;
import org.codeaurora.telephony.utils.RegistrantList;

public class MbnAppGlobals extends Application {
    private static final String TAG = "MbnAppGlobals";
    private boolean mQcRilHookReady = false;
    private QcRilHook mQcRilHook;
    public static int MBN_TYPE_SW = 0;
    public static int MBN_TYPE_HW = 1;


    private RegistrantList mQcRilHookReadyRegistrants = new RegistrantList();

    @Override
    public void onCreate() {
        super.onCreate();
        mQcRilHook = new QcRilHook(this, mQcRilHookCallback);
    }

    // QcRilHook Callback
    private QcRilHookCallback mQcRilHookCallback = new QcRilHookCallback() {
        @Override
        public void onQcRilHookReady() {
            log("QcRilHook is ready");
            synchronized (mQcRilHookReadyRegistrants) {
                mQcRilHookReady = true;
                mQcRilHookReadyRegistrants.notifyRegistrants();
            }
        }
        public void onQcRilHookDisconnected() {
            // TODO: Handle onQcRilHookDisconnected
        }
    };

    private static MbnAppGlobals sApp;
    public MbnAppGlobals() {
        sApp = this;
    }
    public static MbnAppGlobals getInstance() {
        if (sApp == null) {
            throw new IllegalStateException("no AppGlobals");
        }
        return sApp;
    }

    public String getMetaInfoForConfig(String config) {
        log("getMetaInfoForConfig, mQcRilHookReady:" + mQcRilHookReady +
                " config:" + config);
        if (!mQcRilHookReady || config == null) {
            return null;
        }
        int mbnType = MbnTestUtils.isCurrentSwMbnMode() ? MBN_TYPE_SW : MBN_TYPE_HW;
        return  mQcRilHook.qcRilGetMetaInfoForConfig(config, mbnType);
    }

    public boolean getAllConfigs() {
        log("getAllConfigs, mQcRilHookReady:" + mQcRilHookReady);
        if (!mQcRilHookReady) {
            return false;
        }
        return mQcRilHook.qcRilGetAllConfigs();
    }

    public String getMbnConfig(int sub) {
        return getMbnConfig(sub, (MbnTestUtils.isCurrentSwMbnMode() ? MBN_TYPE_SW : MBN_TYPE_HW));
    }

    public String getMbnConfig(int sub, int mbnType) {
        log("getMbnConfig, mQcRilHookReady:" + mQcRilHookReady + " Sub:" + sub
            + " mbnType:" + mbnType);
        if (!mQcRilHookReady) {
            return null;
        }
        return mQcRilHook.qcRilGetConfig(sub, mbnType);
    }


    public boolean cleanUpConfigs() {
        log("cleanUpConfigs, mQcRilHookReady:" + mQcRilHookReady);
        if (!mQcRilHookReady) {
            return false;
        }

        return mQcRilHook.qcRilCleanupConfigs();
    }

    public boolean setupMbnConfig(String fileName, String config, int subMask) {
        log("setupMbnConfig, mQcRilHookReady:" + mQcRilHookReady +
                " fileName:" + fileName + " Config:" + config + " Mask" + subMask);
        if (!mQcRilHookReady || config == null || fileName == null) {
            return false;
        }
        int mbnType = MbnTestUtils.isCurrentSwMbnMode() ? MBN_TYPE_SW : MBN_TYPE_HW;

        return mQcRilHook.qcRilSetConfig(fileName, config, subMask, mbnType);
    }

    public boolean selectConfig(String config, int subMask) {
        log("selectConfig, mQcRilHookReady:" + mQcRilHookReady +
                " Config:" + config + " Mask:" + subMask);
        if (!mQcRilHookReady) {
            return false;
        }
        int mbnType = MbnTestUtils.isCurrentSwMbnMode() ? MBN_TYPE_SW : MBN_TYPE_HW;
        deactivateConfigs();
        return mQcRilHook.qcRilSelectConfig(config, subMask, mbnType);
    }

    public byte[] getOemVersionOfID(String config) {
        log("getOemVersionOfID, mQcRilHookReady:" + mQcRilHookReady + " Config:" + config);
        if (!mQcRilHookReady || config == null) {
            return null;
        }

        return mQcRilHook.qcRilGetOemVersionOfID(config);
    }

    public byte[] getOemVersionOfFile(String fileName) {
        log("getOemVersionOfFile, mQcRilHookReady:" + mQcRilHookReady + " File Name:" + fileName);
        if (!mQcRilHookReady || fileName == null) {
            return null;
        }

        return mQcRilHook.qcRilGetOemVersionOfFile(fileName);
    }

    public byte[] getQcVersionOfID(String config) {
        log("getQcVersionOfID, mQcRilHookReady:" + mQcRilHookReady + " Config:" + config);
        if (!mQcRilHookReady || config == null) {
            return null;
        }

        return mQcRilHook.qcRilGetQcVersionOfID(config);
    }

    public byte[] getQcVersionOfFile(String fileName) {
        log("getQcVersionOfFile, mQcRilHookReady:" + mQcRilHookReady + " File Name:" + fileName);
        if (!mQcRilHookReady || fileName == null) {
            return null;
        }

        return mQcRilHook.qcRilGetQcVersionOfFile(fileName);
    }

    public boolean validateConfig(String config, int sub) {
        log("validateConfig, mQcRilHookReady:" + mQcRilHookReady + " config:" + config +
                " sub:" + sub);
        if (!mQcRilHookReady  || config == null) {
            return false;
        }

        return mQcRilHook.qcRilValidateConfig(config, sub);
    }

    public boolean deactivateConfigs() {
        log("deactivateConfigs, mQcRilHookReady:" + mQcRilHookReady);
        if (!mQcRilHookReady) {
            return false;
        }
        int mbnType = MbnTestUtils.isCurrentSwMbnMode() ? MBN_TYPE_SW : MBN_TYPE_HW;

        return mQcRilHook.qcRilDeactivateConfigs(mbnType);
    }

    public boolean deactivateAllConfigs() {
        log("deactivateAllConfigs, mQcRilHookReady:" + mQcRilHookReady);
        if (!mQcRilHookReady) {
            return false;
        }
        return (mQcRilHook.qcRilDeactivateConfigs(MBN_TYPE_SW)
                ? mQcRilHook.qcRilDeactivateConfigs(MBN_TYPE_HW) : false);
    }

    public boolean enableAutoMode() {
        log("enableAutoMode, mQcRilHookReady:" + mQcRilHookReady);
        if (!mQcRilHookReady) {
            return false;
        }
        return (mQcRilHook.qcRilEnableAutoMode(0)
                ? mQcRilHook.qcRilEnableAutoMode(1) : false);
    }

    // Register for QcRilHook Ready
    public void registerQcRilHookReady(Handler handler, int what, Object obj) {
        Registrant r = new Registrant(handler, what, obj);
        synchronized (mQcRilHookReadyRegistrants) {
            mQcRilHookReadyRegistrants.add(r);
            if (mQcRilHookReady) {
                r.notifyRegistrant();
            }
        }
    }

    public void setSelectMode(String mode) {
        SharedPreferences.Editor editor =
            getSharedPreferences("data", Context.MODE_PRIVATE).edit();
        editor.putString("select_mode", mode);
        editor.commit();
    }

    public String getSelectMode(){
        SharedPreferences preferences = getSharedPreferences("data", Context.MODE_PRIVATE);
        return preferences.getString("select_mode", MbnTestUtils.DEFAULT_MODE);
    }

    // unRegister for QcRilHook Ready
    public void unregisterQcRilHookReady(Handler handler) {
        synchronized (mQcRilHookReadyRegistrants) {
            mQcRilHookReadyRegistrants.remove(handler);
        }
    }

    private void log(String msg) {
        Log.d(TAG, "MbnTest_ " + msg);
    }
}

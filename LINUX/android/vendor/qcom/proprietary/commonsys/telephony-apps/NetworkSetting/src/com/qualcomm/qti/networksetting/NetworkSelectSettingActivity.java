/*
 * Copyright (c) 2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Not a Contribution.
 */
/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.qualcomm.qti.networksetting;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.MenuItem;


/**
 * Activity associated with NetworkSelectSetting fragment
 */
public class NetworkSelectSettingActivity extends Activity {
    private static final String TAG = "NetworkSelectSettingActivity";
    public static final String KEY_SUBSCRIPTION_ID = "subscription_id";

    /**
     * Returns the Android Intent that led to this Activity being created.
     */
    public static Intent getIntent(Context context, int subId) {
        Intent intent = new Intent(context, NetworkSelectSettingActivity.class);
        intent.putExtra(KEY_SUBSCRIPTION_ID, subId);
        return intent;
    }

    @Override
    public void onCreate(Bundle savedState) {
        Log.d(TAG, "onCreate()");
        super.onCreate(savedState);
        int subId = getIntent().getExtras().getInt(KEY_SUBSCRIPTION_ID);
        setContentView(R.layout.choose_network);

        FragmentManager fragmentManager = getFragmentManager();
        Fragment fragment = fragmentManager.findFragmentById(R.id.choose_network_content);
        if (fragment == null) {
            fragmentManager.beginTransaction()
                    .add(R.id.choose_network_content,
                            NetworkSelectSetting.newInstance(subId), TAG)
                    .commit();
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        final int itemId = item.getItemId();
        if (itemId == android.R.id.home) {
            onBackPressed();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}

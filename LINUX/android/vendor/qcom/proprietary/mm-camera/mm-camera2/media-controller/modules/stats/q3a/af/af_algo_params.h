/* af_algo_params.h
*
*   DESCRICRIPTION
*   value monitor for different af algo for different sensivitity.
*
* Copyright (c) 2016 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

{
  {  0, /* is_af_region_weight_enable */
     0, /* is_af_Luma_weight_enable */
     0, /* is_af_face_weight_enable */
     /* region_weight_table*/
     {  25,
        {
          0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f,
          0.5f, 1.0f,16.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.5f,
          0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
          1.0f
        },
    },
    /* luma_weight_table */
    {  // Number of valid entries
       2,
       { // {Luma value, weight }
         {4000.0f, 1.0f},
         {6000.0f, 0.6f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
      },
    },
    {  // Number of valid entries
       4,
       { // {fv index, weight }
         {4.0f, 0.5f},
         {9.0f,  1.0f},
         {10.0f, 1.0f},
         {24.0f, 1.5f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
         {0.0f,0.0f},
      },
    },
  },
  1,
};


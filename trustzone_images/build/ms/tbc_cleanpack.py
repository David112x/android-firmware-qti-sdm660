#============================================================================
#  Name:                                                                     
#    tbc_cleanpack.py 
#
#  Description:                                                              
#    None 
#                                                                            
# Copyright (c) 2020 by QUALCOMM, Incorporated.  All Rights Reserved.        
#============================================================================
#                                                                            
# *** AUTO GENERATED FILE - DO NOT EDIT                                      
#                                                                            
# GENERATED: Sun Mar 29 23:53:04 2020 
#============================================================================
def exists(env):
   return env.Detect('tcfg_cleanpack')

def generate(env):
   env.AddUsesFlags('USES_CLEAN_PACK',  True)

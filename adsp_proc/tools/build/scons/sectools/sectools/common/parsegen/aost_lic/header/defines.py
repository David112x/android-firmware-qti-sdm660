#===============================================================================
#
# Copyright (c) 2014 Qualcomm Technologies, Inc. All Rights Reserved.
# Qualcomm Technologies Proprietary and Confidential.
#
#===============================================================================

#------------------------------------------------------------------------------
# AOST LIC Header
#------------------------------------------------------------------------------
# magic values
AOSTLMAG        = 'QCLF'

AOSTLMAG_STRING = 'Magic'
AOSTLMAG_DESCRIPTION = \
{
    AOSTLMAG      : AOSTLMAG,
}

# version values
AOSTLVERONE     = 1
AOSTLVERTWO     = 2

AOSTLVER_STRING = 'Version'
AOSTLVER_DESCRIPTION = \
{
    AOSTLVERONE : '1',
    AOSTLVERTWO : '2',
}

# type values
AOSTLTYPECOMM   = 0x0001
AOSTLTYPEEVAL   = 0xFFFF

AOSTLTYPE_STRING  = 'License Type'
AOSTLTYPE_DESCRIPTION = \
{
    AOSTLTYPECOMM : 'Commercial',
    AOSTLTYPEEVAL : 'Evaluation',
}

# oem_id max
AOSTLMAXOEMID = 0xFFFF

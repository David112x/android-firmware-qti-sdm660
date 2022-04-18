# ===============================================================================
#
#  Copyright (c) 2013-2017 Qualcomm Technologies, Inc.
#  All Rights Reserved.
#  Confidential and Proprietary - Qualcomm Technologies, Inc.
#
# ===============================================================================

'''
Created on Feb 21, 2014

@author: hraghav
'''

import os

from sectools.common.utils import c_path
from sectools.features.isc.cfgparser import ConfigParser
from sectools.features.isc.imageinfo import ImageInfo
from . import BaseStager


class ImagePathsStager(BaseStager):

    def __init__(self, image_path, img_config_parser, parsegen_config, sign_id=None):
        from sectools.features.isc.parsegen.config.parser import ParsegenCfgParser
        assert isinstance(image_path, str)
        assert isinstance(img_config_parser, ConfigParser)
        assert isinstance(parsegen_config, ParsegenCfgParser)
        if sign_id is not None: assert isinstance(sign_id, str)

        # Initialize the BaseStager
        BaseStager.__init__(self)

        # Validate that the image path exists
        image_path = c_path.normalize(image_path)
        if not c_path.validate_file(image_path):
            raise RuntimeError('No read access to the image path: ' + image_path)

        # Validate the sign_id
        sign_id = self._get_sign_id(img_config_parser,
                                    os.path.basename(image_path),
                                    sign_id)

        # Get the config block for the sign id
        img_config_block = img_config_parser.get_config_for_sign_id(sign_id)

        # Create the one image info object
        image_info = ImageInfo(image_path, sign_id, img_config_block,
                               img_config_parser, parsegen_config)
        image_info.dest_image.image_name = image_info.src_image.image_name

        # Check if the dest image name should be overridden
        if img_config_block.output_file_name is not None:
            image_info.dest_image.image_name = img_config_block.output_file_name

        # Put the image info object into the list
        self._image_info_list.append(image_info)

    @property
    def mini_build_path(self):
        raise RuntimeError('Individual Image Signing does not support minimized build.')

    @mini_build_path.setter
    def mini_build_path(self, mini_build_path):
        raise RuntimeError('Individual Image Signing does not support minimized build.')

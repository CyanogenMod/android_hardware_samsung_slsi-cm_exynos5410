/*
 * Copyright (C) 2012 The Android Open Source Project
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

#ifndef ANDROID_EXYNOS_HWC_MODULE_H_
#define ANDROID_EXYNOS_HWC_MODULE_H_
#include <hardware/hwcomposer.h>
#include <linux/s3c-fb.h>

#define VSYNC_DEV_PREFIX "/sys/devices"
#define VSYNC_DEV_MIDDLE "/platform/exynos-sysmmu.11"
#define VSYNC_DEV_NAME  "/exynos5-fb.1/vsync"

#define DUAL_VIDEO_OVERLAY_SUPPORT
#define EXYNOS_SUPPORT_BGRX_8888
#define WAIT_FOR_RENDER_FINISH

#ifdef WAIT_FOR_RENDER_FINISH
inline int ExynosWaitForRenderFinish(const private_module_t  *gralloc_module,
                                                        buffer_handle_t *handle, int num_buffers)
{
    if (gralloc_module) {
        if (gralloc_module->FinishPVRRender(gralloc_module, handle, num_buffers) < 0)
            return -1;
    }
    return 0;
}
#endif

const size_t GSC_DST_W_ALIGNMENT_RGB888 = 16;
const size_t GSC_DST_CROP_W_ALIGNMENT_RGB888 = 1;
const size_t GSC_W_ALIGNMENT = 16;
const size_t GSC_H_ALIGNMENT = 16;
const size_t GSC_DST_H_ALIGNMENT_RGB888 = 1;
const size_t FIMD_GSC_IDX = 0;
const size_t FIMD_GSC_SEC_IDX = 1;
const size_t HDMI_GSC_IDX = 2;
#ifdef USES_VIRTUAL_DISPLAY
const size_t WFD_GSC_IDX = 3;
#else
const size_t WFD_GSC_DRM_IDX = 3;
#endif
const int FIMD_GSC_USAGE_IDX[] = {FIMD_GSC_IDX, FIMD_GSC_SEC_IDX};
#ifdef USES_VIRTUAL_DISPLAY
const int AVAILABLE_GSC_UNITS[] = { 0, 1, 1, 1 };
#else
const int AVAILABLE_GSC_UNITS[] = { 0, 1, 1, 5 };
#endif

#endif

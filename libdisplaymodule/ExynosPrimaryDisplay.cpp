#include "ExynosPrimaryDisplay.h"
#include "ExynosHWCModule.h"

ExynosPrimaryDisplay::ExynosPrimaryDisplay(int numGSCs, struct exynos5_hwc_composer_device_1_t *pdev) :
    ExynosOverlayDisplay(numGSCs, pdev)
{
}

int ExynosPrimaryDisplay::waitForRenderFinish(buffer_handle_t *handle, int buffers)
{
    if (mGrallocModule->FinishPVRRender(mGrallocModule, handle, buffers) < 0)
        return -1;

    return 0;
}

ExynosPrimaryDisplay::~ExynosPrimaryDisplay()
{
}

﻿#pragma once

#include "AsstPort.h"

#ifdef __cplusplus
extern "C" {
#endif
    typedef void (MEO_CALL* AsstCallback)(int msg, const char* detail_json, void* custom_arg);

    MEOAPI_PORT void* MEO_CALL AsstCreate();
    MEOAPI_PORT void* MEO_CALL AsstCreateEx(AsstCallback callback, void* custom_arg);
    void MEOAPI AsstDestory(void* p_asst);

    bool MEOAPI AsstCatchDefault(void* p_asst);
    bool MEOAPI AsstCatchEmulator(void* p_asst);
    bool MEOAPI AsstCatchCustom(void* p_asst);
    bool MEOAPI AsstCatchSpecific(void* p_asst, const char* address);
    bool MEOAPI AsstCatchFake(void* p_asst);

    bool MEOAPI AsstStartSanity(void* p_asst);
    bool MEOAPI AsstStartVisit(void* p_asst, bool with_shopping);
    bool MEOAPI AsstStartProcessTask(void* p_asst, const char* task);
    bool MEOAPI AsstStartRecruiting(void* p_asst, const int required_level[], int required_len, bool set_time);
    bool MEOAPI AsstStartInfrastShift(void* p_asst, int work_mode, const char** order, int order_size, int uses_of_drones, double dorm_threshold);
    bool MEOAPI AsstStartDebugTask(void* p_asst);

    void MEOAPI AsstStop(void* p_asst);
    bool MEOAPI AsstSetParam(void* p_asst, const char* type, const char* param, const char* value);

    MEOAPI_PORT const char* MEO_CALL AsstGetVersion();
#ifdef __cplusplus
}
#endif
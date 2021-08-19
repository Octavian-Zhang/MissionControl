#ifndef RTW_HEADER_SendData_IndividualUAVCmdT_h_
#define RTW_HEADER_SendData_IndividualUAVCmdT_h_
#include "rtwtypes.h"
#include "DatalinkInterface.h"

class SendData_IndividualUAVCmdT
{
  public:
    virtual void SendData(const IndividualUAVCmd *data, int32_T length, int32_T *
                          status) = 0;
    virtual ~SendData_IndividualUAVCmdT()
    {
    }
};

#endif

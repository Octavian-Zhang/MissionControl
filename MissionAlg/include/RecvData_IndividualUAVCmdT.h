#ifndef RTW_HEADER_RecvData_IndividualUAVCmdT_h_
#define RTW_HEADER_RecvData_IndividualUAVCmdT_h_
#include "rtwtypes.h"
#include "DatalinkInterface.h"

class RecvData_IndividualUAVCmdT
{
  public:
    virtual void RecvData(IndividualUAVCmd *data, int32_T length, int32_T
                          *status) = 0;
    virtual ~RecvData_IndividualUAVCmdT()
    {
    }
};

#endif

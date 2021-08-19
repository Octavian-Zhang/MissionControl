#include "rtwtypes.h"
#include <cmath>
#include "mod_dBqh4Vat.h"
#include "wrapToPi_iEuDNbvh.h"

void wrapToPi_iEuDNbvh(real_T *theta)
{
    real_T thetaWrap;
    if (std::abs(*theta) > 3.1415926535897931) {
        thetaWrap = mod_dBqh4Vat(*theta + 3.1415926535897931);
        if (static_cast<boolean_T>(static_cast<int32_T>((thetaWrap == 0.0) &
                (*theta + 3.1415926535897931 > 0.0)))) {
            thetaWrap = 6.2831853071795862;
        }

        *theta = thetaWrap - 3.1415926535897931;
    }
}

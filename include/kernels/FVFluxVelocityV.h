#ifndef FV_FLUX_VELOCITY_V_H
#define FV_FLUX_VELOCITY_V_H
#pragma once

#include <FVFluxKernel.h>

class FVFluxVelocityV : public FVFluxKernel {

public:
    static InputParameters validParams();
    FVFluxVelocityV(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;
    const Real & _gravity;

private:
    const ADVariableValue & _vel_u;
    const ADVariableValue & _height;

};

#endif // FV_FLUX_VELOCITY_V_H
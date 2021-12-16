#ifndef FV_FLUX_VELOCITY_U_H
#define FV_FLUX_VELOCITY_U_H
#pragma once

#include <FVFluxKernel.h>

class FVFluxVelocityU : public FVFluxKernel {

public:
    static InputParameters validParams();
    FVFluxVelocityU(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;
    const Real & _gravity;

private:
    const ADVariableValue & _vel_v;
    const ADVariableValue & _height;

};

#endif // FV_FLUX_VELOCITY_U_H
#ifndef FV_FLUX_HEIGHT_H_
#define FV_FLUX_HEIGHT_H_
#pragma once

#include <FVFluxKernel.h>

class FVFluxHeight : public FVFluxKernel {

public:
    static InputParameters validParams();
    FVFluxHeight(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;
    const Real & _meanHeight;

private:
    const ADVariableValue & _vel_u;
    const ADVariableValue & _vel_v;

};

#endif // FV_FLUX_HEIGHT_H_
#ifndef LANDSCAPE_DIFFUSION_H_
#define LANDSCAPE_DIFFUSION_H_
#pragma once

#include <ADKernelGrad.h>

class LandscapeDiffusion : public ADKernelGrad {

public:
	static InputParameters validParams();
	LandscapeDiffusion(const InputParameters & parameters);

protected:
	virtual ADRealVectorValue precomputeQpResidual() override;
	const Real & _landDiffusivity;

};


#endif // LANDSCAPE_DIFFUSION_H_
[Mesh]
    type = GeneratedMesh
    dim = 3
    nx = 100
    ny = 100
    nz = 100
    xmin = -1
    xmax = 1
    ymin = -1
    ymax = 1
    zmin = -1
    zmax = 1
[]

[Variables]
    [c]
    []
[]

[Kernels]
    [diffusion]

    []
    [advection]
        
    []
    [time]
        type = ADTimeDerivative
        variable = c
    []
[]
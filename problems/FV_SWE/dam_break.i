[Mesh]
    type = GeneratedMesh
    dim = 2
    nx = 40
    ny = 40
    xmin = 0
    xmax = 20
    ymin = 0
    ymax = 20
[]

[Adaptivity]
  marker = errorfrac # this specifies which marker from 'Markers' subsection to use
  steps = 2 # run adaptivity 2 times, recomputing solution, indicators, and markers each time

  # Use an indicator to compute an error-estimate for each element:
  [Indicators]
    # create an indicator computing an error metric for the convected variable
    [error] # arbitrary, use-chosen name
      type = GradientJumpIndicator
      variable = h
      outputs = none
    []
  []

  # Create a marker that determines which elements to refine/coarsen based on error estimates
  # from an indicator:
  [Markers]
    [errorfrac] # arbitrary, use-chosen name (must match 'marker=...' name above
      type = ErrorFractionMarker
      indicator = error # use the 'error' indicator specified above
      refine = 0.5 # split/refine elements in the upper half of the indicator error range
      coarsen = 0 # don't do any coarsening
      outputs = none
    []
  []
[]

[Variables]
    [h]
        order = CONSTANT
        family = MONOMIAL
        fv = true
    []
    [u]
        order = CONSTANT
        family = MONOMIAL
        fv = true
        initial_condition = 1
    []
    [v]
        order = CONSTANT
        family = MONOMIAL
        fv = true
        initial_condition = 0
    []
[]

[FVKernels]
    [h_time]
        type = FVTimeKernel
        variable = h
    []
    [h_flux]
        type = FVFluxHeight
        variable = h
        mean_height = 0
        velocity_u = u
        velocity_v = v
    []
    [u_time]
        type = FVTimeKernel
        variable = u
    []
    [u_flux]
        type = FVFluxVelocityU
        variable = u
        gravity = 0
        velocity_v = v
        height = h
    []
    [v_time]
        type = FVTimeKernel
        variable = v
    []
    [v_flux]
        type = FVFluxVelocityV
        variable = v
        gravity = 0
        velocity_u = u
        height = h
    []
[]

[FVBCs]
    [h_west]
        type = FVNeumannBC
        variable = h
        boundary = left
        value = 0
    []
    [h_east]
        type = FVNeumannBC
        variable = h
        boundary = right
        value = 0
    []
    [h_south]
        type = FVNeumannBC
        variable = h
        boundary = bottom
        value = 0
    []
    [h_north]
        type = FVNeumannBC
        variable = h
        boundary = top
        value = 0
    []

    [u_west]
        type = FVNeumannBC
        variable = u
        boundary = left
        value = 0
    []
    [u_east]
        type = FVNeumannBC
        variable = u
        boundary = right
        value = 0
    []
    [u_south]
        type = FVNeumannBC
        variable = u
        boundary = bottom
        value = 0
    []
    [u_north]
        type = FVNeumannBC
        variable = u
        boundary = top
        value = 0
    []

    [v_west]
        type = FVNeumannBC
        variable = v
        boundary = left
        value = 0
    []
    [v_east]
        type = FVNeumannBC
        variable = v
        boundary = right
        value = 0
    []
    [v_south]
        type = FVNeumannBC
        variable = v
        boundary = bottom
        value = 0
    []
    [v_north]
        type = FVNeumannBC
        variable = v
        boundary = top
        value = 0
    []
[]

[ICs]
    [h_ic]
        type = FunctionIC
        variable = h
        function = 'if (x < 4 & y < 4, 5, 0)'
    []
[]

[Executioner]
	type = Transient
	scheme = crank-nicolson
	end_time = 10	
	dt = 0.05

	# petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
	# petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
	execute_on = 'timestep_end'
	exodus = true
[]

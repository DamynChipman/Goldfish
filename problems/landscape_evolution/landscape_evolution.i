[Mesh]
	type = GeneratedMesh
	dim = 2
	nx = 500
	ny = 500
	xmin = 0	# [m]
	xmax = 500	# [m]
	ymin = 0	# [m]
	ymax = 500	# [m]
[]

[Variables]
	[elevation]
		order = first
		family = lagrange
	[]
[]

[Kernels]
	[diffusion]
		type = LandscapeDiffusion
		variable = elevation
		landDiffusivity = 2.5	# [m/yr]
	[]
	[uplift]
		type = LandscapeUplift
		variable = elevation
		uplift = 0.005
	[]
	[time]
		type = ADTimeDerivative
		variable = elevation
	[]
[]

[BCs]
	[west]
		type = ADNeumannBC
		boundary = left
		variable = elevation
		value = 0		# [m]
	[]
	[east]
		type = ADNeumannBC
		boundary = right
		variable = elevation
		value = 0		# [m]
	[]
	[south]
		type = ADNeumannBC
		boundary = bottom
		variable = elevation
		value = 0		# [m]
	[]
	[north]
		type = ADNeumannBC
		boundary = top
		variable = elevation
		value = 0		# [m]
	[]
[]

[ICs]
	[initial]
		type = RandomIC
		variable = elevation
		max = 100		# [m]
		min = 0			# [m]
	[]
[]

[Executioner]
	type = Transient
	scheme = implicit-euler
	end_time = 100	# [yr]
	# end_time = 50		# [yr]
	dt = 5				# [yr]

	petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
	petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
	execute_on = 'timestep_end'
	exodus = true
[]
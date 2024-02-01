def this_raises():
	"""This function always raises an exception.

	>>> this_raises()
	Traceback (most recent call last):
		Bla
		Bla
		Bla
	RuntimeError: here is the error
	"""
	raise RuntimeError('here is the error')

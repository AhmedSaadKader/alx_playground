from math import pi

def circle_area(a):
	if type(a) not in [int, float]:
		raise TypeError("The radius must be a non-negative real number.")

	if a < 0:
		raise ValueError("The radius cannot be negative.")
		
	return pi * (a ** 2)
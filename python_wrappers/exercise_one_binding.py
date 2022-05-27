import ctypes

exercise_one_lib = ctypes.CDLL("Builds/obj/exercise1_8.so")

# python_c_square = basic_function_lib.c_square
# python_c_square.restype = None

# def do_square_using_c(list_in):
# 	"""Call C function to calculate squares"""
# 	n = len(list_in)
# 	c_arr_in = (c_double * n) (*list_in)
# 	c_arr_out = (c_double * n) ()

# 	python_c_square(c_int(n), c_arr_in, c_arr_out)
# 	return c_arr_out[:]

print(exercise_one_lib._func_flags_)
print(dir(exercise_one_lib._func_restype_))
print(exercise_one_lib._name)
print(dir(exercise_one_lib._FuncPtr))

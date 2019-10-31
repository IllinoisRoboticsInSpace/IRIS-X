from ctypes import cdll

serial = cdll.LoadLibrary("target/release/libserial.dylib")

serial.comm()

print("done!")

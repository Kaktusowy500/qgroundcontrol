from pymavlink import mavutil
import time

master = mavutil.mavlink_connection('udpout:localhost:14550', source_system=1)

# Send a message for QGC to read out loud
#  Severity from https://mavlink.io/en/messages/common.html#MAV_SEVERITY
# master.mav.statustext_send(mavutil.mavlink.MAV_SEVERITY_INFO,
#                            "QGC will read this".encode())

# Send a DEBUG_VECT message
name = "test".encode()  # Name of the debug vector (10 chars max)
time_usec = int(time.time() * 1e6)  # Timestamp in microseconds
# vector components
x = 50.1  
y = 18.6  
z = 3.0 

master.mav.debug_vect_send(name, time_usec, x, y, z)
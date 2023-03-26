#                  - OpenPLC Python SubModule (PSM) -
# See end of file for description and usage

#import all your libraries here
import psm
import time
import libioplus

# A global variable for the number of tiers in the stack.  It assumes that the
# stacks are numbered 0, 1, 2, etc.
NUM_TIERS = 1

def hardware_init():
    #Insert your hardware initialization code in here
    psm.start()

# Update the update_inputs function to handle multiple tiers and read relay values
def update_inputs():
    for tier in range(NUM_TIERS):
        # Store previous states
        prev_states = [psm.get_var(f"IX{tier}." + str(i)) for i in range(8)]

        # Read card stack level inputs
        val = libioplus.getOpto(tier)
        for i in range(8):
            var_state = False
            if val & (1 << i) != 0:
                var_state = True

            # Compare the current state with the previous state
            if var_state != prev_states[i]:
                print(f"State change: IX{tier}.{i} changed from {prev_states[i]} to {var_state}")

            # Update the state
            psm.set_var(f"IX{tier}." + str(i), var_state)  # move OPTO state to IX{tier}.0 .. IX{tier}.7

        # Read relay contacts as inputs
        prev_relay_states = [bool(psm.get_var(f"QX{tier}." + str(i))) for i in range(8)]
        for i in range(8):
            relay_val = libioplus.getRelayCh(tier, i + 1)  # Read the relay value

            # Convert relay_val to boolean
            relay_val_bool = bool(relay_val)

            # Compare the current state with the previous state
            if relay_val_bool != prev_relay_states[i]:
                print(f"Relay value change: QX{tier}.{i} changed from {prev_relay_states[i]} to {relay_val_bool}")



# Update the update_outputs function to handle multiple tiers
def update_outputs():
    for tier in range(NUM_TIERS):
        # Store previous states
        prev_relay_states = [psm.get_var(f"QX{tier}." + str(i)) for i in range(8)]

        # Update outputs for card stack level
        val = 0
        for i in range(8):
            a = psm.get_var(f"QX{tier}." + str(i))  # relays QX{tier}.0..QX{tier}.7
            if a == True:
                val += 1 << i

            # Compare the current state with the previous state
            if a != prev_relay_states[i]:
                print(f"Relay state change: QX{tier}.{i} changed from {prev_relay_states[i]} to {a}")

        # Update the relay outputs
        libioplus.setRelays(tier, val)





if __name__ == "__main__":
    hardware_init()
    while (not psm.should_quit()):
        update_inputs()
        update_outputs()
        time.sleep(0.1) #You can adjust the psm cycle time here
    psm.stop()

# PSM is the bridge connecting OpenPLC core to Python programs. PSM allows
# you to directly interface OpenPLC IO using Python and even write drivers
# for expansion boards using just regular Python.
#
# PSM API is quite simple and just has a few functions. When writing your
# own programs, avoid touching on the "__main__" function as this regulates
# how PSM works on the PLC cycle. You can write your own hardware initialization
# code on hardware_init(), and your IO handling code on update_inputs() and
# update_outputs()
#
# To manipulate IOs, just use PSM calls psm.get_var([location name]) to read
# an OpenPLC location and psm.set_var([location name], [value]) to write to
# an OpenPLC location. For example:
#     psm.get_var("QX0.0")
# will read the value of %QX0.0. Also:
#     psm.set_var("IX0.0", True)
# will set %IX0.0 to true.
#
# Below you will find a simple example that uses PSM to switch OpenPLC's
# first digital input (%IX0.0) every second. Also, if the first digital
# output (%QX0.0) is true, PSM will display "QX0.0 is true" on OpenPLC's
# dashboard. Feel free to reuse this skeleton to write whatever you want.
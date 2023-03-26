
# LLF_Driver

LLF_Driver is a Python-based driver for OpenPLC that interfaces with SequentMicrosystems Home Automation HATs. The driver supports multiple tiers of HATs and reads OPTO input values and relay contact states.

## Features

- Handles multiple tiers of SequentMicrosystems Home Automation HATs
- Reads OPTO input values and relay contact states
- Uses OpenPLC's Python SubModule (PSM) to interface with the hardware

## Configuration

Before using the LLF_Driver, make sure to set the `NUM_TIERS` variable in the `llf-driver-psm.py` file to match the number of HATs that are on your stack. For example, if you have 3 HATs, set `NUM_TIERS = 3`.  The HATs should be configured with the jumpers with ascending stack IDs, e.g, 0, 1, 2...

## Usage

1. Install OpenPLC and its dependencies on your Raspberry Pi.
2. Clone this repository into your desired directory.
3. Copy the LLF_Driver Python PSM code from `./llf-driver-psm.py` and paste it into the Hardware page of OpenPLC as a "Python on Linux (PSM)" OpenPLC Hardware Layer option. Click on "Save Changes".
4. In the OpenPLC web interface, click on the "Programs" tab, then click on "Upload Program" and upload the Structured Text program found in `./build/generated_plc.st`.
5. Run the OpenPLC project.

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

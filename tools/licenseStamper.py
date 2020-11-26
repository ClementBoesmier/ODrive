import os
import glob

header = """/* MIT License

Copyright (c) 2016-2021 ODrive Robotics, Inc

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */
"""

folders = ['communication', 'MotorControl', 'Tests', 'Drivers', 'Drivers/STM32', 'Drivers/DRV8301']

for dir in folders:
    for f in glob.glob(os.path.join('../Firmware', dir, '*.c*')):
        with open(f, 'r') as orig:
            data = orig.read()
        
        if not (data.startswith('MIT License')):
            with open(f, 'w') as dest:
                dest.write(header + '\n' + data)

    for f in glob.glob(os.path.join('../Firmware', dir, '*.h*')):
        with open(f, 'r') as orig:
            data = orig.read()
        
        if not (data.startswith('MIT License')):
            with open(f, 'w') as dest:
                dest.write(header + '\n' + data)
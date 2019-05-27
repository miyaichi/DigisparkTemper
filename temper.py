#!/usr/bin/python3

import json
import time
import usb


def read(device):
    """Read byte from usb device
    """
    response = device.ctrl_transfer(
        bmRequestType=usb.util.build_request_type(
            usb.util.CTRL_IN, usb.util.CTRL_TYPE_CLASS,
            usb.util.CTRL_RECIPIENT_DEVICE),
        bRequest=0x01,  # USBRQ_HID_GET_REPORT
        wValue=(0x03 << 8) | 0,
        wIndex=0,  # ignored
        data_or_wLength=1)  # length
    if not response:
        return None
    return response[0]


def read_line(device):
    """Read line
    """
    device.reset()
    line = ""
    while True:
        c = chr(read(device))
        if c == '\r':
            return line.strip()
        line += c


def main():
    device = usb.core.find(idVendor=0x16c0, idProduct=0x05df)
    if device is None:
        print("Device not found")
        exit()

    while True:
        try:
            line = read_line(device).strip()
            data = json.loads(line)
            print(data)
        except Exception as e:
            print(line)
            print(e)

        time.sleep(5 - 1)


if __name__ == "__main__":
    main()

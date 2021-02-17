#!/usr/bin/python3
""" UTF-8 Validator """


def validUTF8(data):
    try:
        sigBits = [byte & 0xFF for byte in data]
        byteData = bytes(eightBits)
        byteData.decode()
    except:
        return False
    return True

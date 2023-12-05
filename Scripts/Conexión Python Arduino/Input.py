import serial

# Abre el puerto serie
ser = serial.Serial('COM10', 115200)  # Reemplaza 'COMX' con el nombre de tu puerto serie
#sensor_value = ser.readline().decode('utf-8')

while True:
    processed_value = int(input('Ingrese 1 o 0: '))
    ser.write(str(processed_value).encode())

import matplotlib.pyplot as plt
import matplotlib.animation as animation
import serial
import numpy as np
import time

esp = serial.Serial("COM10", 115200)

fig, ax = plt.subplots()

xdata, ydata = [], []
line, = ax.plot([], [])

T = 0.002

def init():
    ax.set_ylim(0, 1023)
    ax.set_xlabel('Tiempo (s)')
    ax.set_ylabel('Valor emg')
    ax.set_title('EMG en tiempo real')
    ax.grid()
    return line,


def update(frame):
    l2 = esp.readline().decode('utf-8')
    l2= float(l2) 
    ydata.append(l2)
    xdata.append(frame*T)
    line.set_data(xdata, ydata)
    if len(xdata)>1000:
        xdata.pop(0)
        ydata.pop(0)
    ax.relim()  # Recalculate the data limits for proper autoscaling
    ax.autoscale_view()  # Autoscale the view limits
    return line,

ani = animation.FuncAnimation(fig, update, init_func=init, blit=True, interval=0.0005, repeat=False, cache_frame_data=False )

plt.grid()
plt.show()

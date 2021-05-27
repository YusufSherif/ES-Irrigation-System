import serial
import time
import tkinter


#Thresholds
def set_button1_state():
        varLabel.set("Temp = " + str(update_temp_reading()))

def set_button2_state():
        varLabel.set("Upper Moisture = " + str(update_moisture_reading()))

def set_button15_state():
        varLabel.set("Lower Moisture = " + str(update_lower_moisture_reading()))

def set_button16_state():
        varLabel.set("Humidity = "+ str(update_humidity_reading()))

def set_button17_state():
        varLabel.set("Light_time = " + str(update_light_reading()))

def set_button18_state():
        varLabel.set("Dark time = "+ str(update_dark_reading()))



def set_button3_state():
        varLabel.set("Temp +")
        ser.write('T'.encode('ascii'))
        #varLabel2.set(update_temp_reading())
        #varLabel2.set(tkTop.after(1000, update_light_reading()))

def set_button4_state():
        varLabel.set("Temp -")
        ser.write('E'.encode('ascii'))
        #varLabel2.set(update_temp_reading())

def set_button5_state():
        varLabel.set("Humidity +")
        ser.write('H'.encode('ascii'))
        #varLabel2.set(update_humidity_reading())

def set_button6_state():
        varLabel.set("Humidity -")
        ser.write('U'.encode('ascii'))
        #varLabel2.set(update_humidity_reading())

def set_button7_state():
        varLabel.set("Upper Moisture +")
        ser.write('M'.encode('ascii'))
        #varLabel2.set(update_moisture_reading())

def set_button8_state():
        varLabel.set("Upper Moisture -")
        ser.write('O'.encode('ascii'))
        #varLabel2.set(update_moisture_reading())

def set_button9_state():
        varLabel.set("Light +")
        ser.write('L'.encode('ascii'))
        #varLabel2.set(update_light_reading())

def set_button10_state():
        varLabel.set("Light -")
        ser.write('I'.encode('ascii'))
        #varLabel2.set(update_light_reading())

def set_button11_state():
        varLabel.set("Darkness +")
        ser.write('D'.encode('ascii'))
        #varLabel2.set(update_light_reading())

def set_button12_state():
        varLabel.set("Darkness -")
        ser.write('A'.encode('ascii'))
        #varLabel2.set(update_light_reading())

def set_button13_state():
        varLabel.set("Lower Moisture +")
        ser.write('X'.encode('ascii'))
        #varLabel2.set(update_light_reading())

def set_button14_state():
        varLabel.set("Lower Moisture -")
        ser.write('Z'.encode('ascii'))
        #varLabel2.set(update_light_reading())


def update_temp_reading():
        ser.write('t'.encode('ascii'))
        #time.sleep(0.1)
        new_temp = ser.read(5)
        new_temp = float(new_temp.decode('ascii'))
        return new_temp

def update_humidity_reading():
        ser.write('h'.encode('ascii'))
        #time.sleep(0.1)
        new_humidity = ser.read(5)
        new_humidity = float(new_humidity.decode('ascii'))
        return(new_humidity)

def update_moisture_reading():
        ser.write('m'.encode('ascii'))
        #time.sleep(0.1)
        new_moisture = ser.read(5)
        new_moisture = float(new_moisture.decode('ascii'))
        return(new_moisture)

def update_light_reading():
        ser.write('l'.encode('ascii'))
        #time.sleep(0.1)
        new_light = ser.read(5)
        new_light = float(new_light.decode('ascii'))
        return(new_light)

def update_dark_reading():
        ser.write('d'.encode('ascii'))
        #time.sleep(0.1)
        new_dark = ser.read(5)
        new_dark = float(new_dark.decode('ascii'))
        return(new_dark)

def update_lower_moisture_reading():
        ser.write('v'.encode('ascii'))
        #time.sleep(0.1)
        new_l_moisture = ser.read(5)
        new_l_moisture = float(new_l_moisture.decode('ascii'))
        return(new_l_moisture)


ser = serial.Serial('/dev/ttyS3', 9600)
time.sleep(3)
ser.write('L'.encode('ascii'))

tkTop = tkinter.Tk()
tkTop.geometry('300x200')
tkTop.title("Project 2 UI")
label3 = tkinter.Label(text = 'Electronic '
                      '\n Farmer',font=("Courier", 12,'bold')).pack()
tkTop.counter = 0
b = tkTop.counter

varLabel = tkinter.IntVar()
tkLabel = tkinter.Label(textvariable=varLabel, )
tkLabel.pack()

varLabel2 = tkinter.IntVar()
tkLabel2 = tkinter.Label(textvariable=varLabel2, )
tkLabel2.pack()


button1 = tkinter.IntVar()
button1state = tkinter.Button(tkTop,
    text="Display \n temp threshold",
    command=set_button1_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button1state.pack(side='top', ipadx=10, padx=10, pady=15)

button2 = tkinter.IntVar()
button2state = tkinter.Button(tkTop,
    text="Display upper\n moisture threshold",
    command=set_button2_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button2state.pack(side='top', ipadx=10, padx=10, pady=15)

button15 = tkinter.IntVar()
button15state = tkinter.Button(tkTop,
    text="Display lower\n moisture threshold",
    command=set_button15_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button15state.pack(side='top', ipadx=10, padx=10, pady=15)

button16 = tkinter.IntVar()
button16state = tkinter.Button(tkTop,
    text="Display \n humidity threshold",
    command=set_button16_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button16state.pack(side='top', ipadx=10, padx=10, pady=15)


button17 = tkinter.IntVar()
button17state = tkinter.Button(tkTop,
    text="Display \n lightime threshold",
    command=set_button2_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button17state.pack(side='top', ipadx=10, padx=10, pady=15)


button18 = tkinter.IntVar()
button18state = tkinter.Button(tkTop,
    text="Display \n darktime threshold",
    command=set_button18_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button18state.pack(side='top', ipadx=10, padx=10, pady=15)

button3 = tkinter.IntVar()
button3state = tkinter.Button(tkTop,
    text="Temperature+",
    command=set_button3_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button3state.pack(side='left', ipadx=10, padx=10, pady=15)

button4 = tkinter.IntVar()
button4state = tkinter.Button(tkTop,
    text="Temperature-",
    command=set_button4_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button4state.pack(side='left', ipadx=10, padx=10, pady=15)

button5 = tkinter.IntVar()
button5state = tkinter.Button(tkTop,
    text="Humidity+",
    command=set_button5_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button5state.pack(side='left', ipadx=10, padx=10, pady=15)

button6 = tkinter.IntVar()
button6state = tkinter.Button(tkTop,
    text="Humidity-",
    command=set_button6_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button6state.pack(side='left', ipadx=10, padx=10, pady=15)

button7 = tkinter.IntVar()
button7state = tkinter.Button(tkTop,
    text="Upper Moisture+",
    command=set_button7_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button7state.pack(side='left', ipadx=10, padx=10, pady=15)

button8 = tkinter.IntVar()
button8state = tkinter.Button(tkTop,
    text="Upper \n Moisture-",
    command=set_button8_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button8state.pack(side='left', ipadx=10, padx=10, pady=15)

button13 = tkinter.IntVar()
button13state = tkinter.Button(tkTop,
    text="Lower \n moisture +",
    command=set_button13_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button13state.pack(side='left', ipadx=10, padx=10, pady=15)

button14 = tkinter.IntVar()
button14state = tkinter.Button(tkTop,
    text="Lower \n moisture -",
    command=set_button14_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button14state.pack(side='left', ipadx=10, padx=10, pady=15)


button9 = tkinter.IntVar()
button9state = tkinter.Button(tkTop,
    text="Lightime+",
    command=set_button9_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button9state.pack(side='left', ipadx=10, padx=10, pady=15)

button10 = tkinter.IntVar()
button10state = tkinter.Button(tkTop,
    text="Lightime-",
    command=set_button10_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button10state.pack(side='left', ipadx=10, padx=10, pady=15)

button11 = tkinter.IntVar()
button11state = tkinter.Button(tkTop,
    text="Dark+",
    command=set_button11_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button11state.pack(side='left', ipadx=10, padx=10, pady=15)

button12 = tkinter.IntVar()
button12state = tkinter.Button(tkTop,
    text="Dark-",
    command=set_button12_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5
)
button12state.pack(side='left', ipadx=10, padx=10, pady=15)




tkButtonQuit = tkinter.Button(
    tkTop,
    text="Quit",
    command=quit,
    height = 4,
    fg = "black",
    width = 8,
    bg = 'yellow',
    bd = 5
)
tkButtonQuit.pack(side='left', ipadx=10, padx=10, pady=15)



tkinter.mainloop()

import serial
import string
import time
import mysql.connector 
from mysql.connector import Error

def connect():
    """ Connect to MySQL database """
    try:
        cur = mysql.connector.connect(host='localhost',
                                       database='db_korlantas',
                                       user='root',
                                       password='K0rlanta5_1nt3rlo9')
	if cur.is_connected():
		mycursor = cur.cursor(buffered=True)
            	print('Connected to MySQL database')
		arduinoPort = '/dev/ttyUSB2' #check in the /dev folder the Arduino Serial Port
		ser = serial.Serial()
		
		ser.setPort(arduinoPort) #boundRate 9600 automatically set
		try:
			ser.open()
			ser.flushInput()
		except: 
			print('Port Error!')
		else:
			while True:
               			mycursor.execute('SELECT nilai FROM motor_belok')
				result = mycursor.fetchone()
				for x1 in result:
					for c1 in x1:
						time.sleep(0)
				ser.write(c1.encode())
				#ser.write('\n'.encode())
				time.sleep(1)
				cur.commit()
    except Error as e:
	print(e)
	connect()

    finally:
        ser.close()
        #print('connection closed')
        mycursor.close()
        #print('database closed')
        #print('end')
	connect()

if __name__ == '__main__':
    connect()

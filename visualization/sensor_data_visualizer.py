import matplotlib.pyplot as plt

class SensorDataVisualizer:
    def __init__(self, time, temp, humidity, pressure, UV_control, UV_exp, batt_control, batt_exp):
        """
        Constructor for the SensorDataVisualizer class.

        :param time: List of time values.
        :param temp: List of temperature values.
        :param humidity: List of humidity values.
        :param pressure: List of pressure values.
        :param UV_control: List of UV control values.
        :param UV_exp: List of UV experimental values.
        :param batt_exp: List of battery experimental values.
        """
        self.time = time
        self.temp = temp
        self.humidity = humidity
        self.pressure = pressure
        self.UV_control = UV_control
        self.UV_exp = UV_exp
        self.batt_control = batt_control
        self.batt_exp = batt_exp

    def plot_all_data(self):
        """
        Creates a single plot that shows all types of sensor data in subplots.
        """
        fig, axes = plt.subplots(nrows=3, ncols=2, figsize=(12, 16))
        axes[0, 0].plot(self.time, self.temp)
        axes[0, 0].set_xlabel('Time')
        axes[0, 0].set_ylabel('Temperature (C)')
        axes[0, 0].set_title('Temperature over Time')

        axes[0, 1].plot(self.time, self.humidity)
        axes[0, 1].set_xlabel('Time')
        axes[0, 1].set_ylabel('Humidity (%)')
        axes[0, 1].set_title('Humidity over Time')

        axes[1, 0].plot(self.time, self.pressure)
        axes[1, 0].set_xlabel('Time')
        axes[1, 0].set_ylabel('Pressure (Pa)')
        axes[1, 0].set_title('Pressure over Time')

        axes[1, 1].plot(self.time, self.UV_control)
        axes[1, 1].set_xlabel('Time')
        axes[1, 1].set_ylabel('UV Control')
        axes[1, 1].set_title('UV Control over Time')

        axes[2, 0].plot(self.time, self.UV_exp)
        axes[2, 0].set_xlabel('Time')
        axes[2, 0].set_ylabel('UV Exp')
        axes[2, 0].set_title('UV Exp over Time')

        axes[2, 1].plot(self.time, self.batt_exp)
        axes[2, 1].set_xlabel('Time')
        axes[2, 1].set_ylabel('Battery Exp')
        axes[2, 1].set_title('Battery Exp over Time')

        # Adjust the layout of subplots to prevent overlapping labels
        fig.tight_layout(h_pad=4, w_pad=2)

        # Display the plot
        plt.show()

    def plot_ambient_parameters(self):
        fig, axes = plt.subplots(nrows=2, ncols=2, figsize=(12, 16))
        axes[0, 0].plot(self.time, self.temp)
        axes[0, 0].set_xlabel('Time')
        axes[0, 0].set_ylabel('Temperature (C)')
        axes[0, 0].set_title('Temperature over Time')

        axes[0, 1].plot(self.time, self.humidity)
        axes[0, 1].set_xlabel('Time')
        axes[0, 1].set_ylabel('Humidity (%)')
        axes[0, 1].set_title('Humidity over Time')

        axes[1, 0].plot(self.time, self.pressure)
        axes[1, 0].set_xlabel('Time')
        axes[1, 0].set_ylabel('Pressure (Pa)')
        axes[1, 0].set_title('Pressure over Time')

        axes[1,1].axis('off')

        # Adjust the layout of subplots to prevent overlapping labels
        fig.tight_layout(h_pad=4, w_pad=2)

        # Display the plot
        plt.show()

    def plot_UV_experiment(self):
        fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(12, 16))
        axes[0].plot(self.time, self.UV_control)
        axes[0].set_xlabel('Time')
        axes[0].set_ylabel('UV Control')
        axes[0].set_title('UV Control over Time')

        axes[1].plot(self.time, self.UV_exp)
        axes[1].set_xlabel('Time')
        axes[1].set_ylabel('UV Exp')
        axes[1].set_title('UV Exp over Time')

        # Adjust the layout of subplots to prevent overlapping labels
        fig.tight_layout(h_pad=4, w_pad=2)

        # Display the plot
        plt.show()

    def plot_batt_experiment(self):
        fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(12, 16))
        axes[0].plot(self.time, self.batt_control)
        axes[0].set_xlabel('Time')
        axes[0].set_ylabel('Battery Control')
        axes[0].set_title('Battery Control over Time')

        axes[1].plot(self.time, self.batt_exp)
        axes[1].set_xlabel('Time')
        axes[1].set_ylabel('Battery Exp')
        axes[1].set_title('Battery Exp over Time')

        # Adjust the layout of subplots to prevent overlapping labels
        fig.tight_layout(h_pad=4, w_pad=2)

        # Display the plot
        plt.show()
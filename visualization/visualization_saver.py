import matplotlib.pyplot as plt

class VisualizationSaver:
    def __init__(self, time, temp, humidity, pressure, UV_control, UV_exp, batt_control, batt_exp):
        self.time = time
        self.temp = temp
        self.humidity = humidity
        self.pressure = pressure
        self.UV_control = UV_control
        self.UV_exp = UV_exp
        self.batt_control = batt_control
        self.batt_exp = batt_exp
        self.export_directory = "figures/"

    def save_all_data(self):
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
        plt.tight_layout(h_pad=4, w_pad=2)
        plt.savefig(f"{self.export_directory}all_data.jpg")

    def save_ambient_parameters(self):
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

        plt.savefig(f"{self.export_directory}ambient_parameters.jpg")

    def save_UV_expermient(self):
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

        plt.savefig(f"{self.export_directory}UV_experiment.jpg")

    def save_batt_experiment(self):
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

        plt.savefig(f"{self.export_directory}batt_experiment.jpg")

    def save_all_separately(self):
        # Plot and save temperature over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.temp)
        ax.set_xlabel('Time')
        ax.set_ylabel('Temperature (C)')
        ax.set_title('Temperature over Time')
        fig.savefig(self.export_directory + 'temp.jpg')
        plt.close(fig)

        # Plot and save humidity over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.humidity)
        ax.set_xlabel('Time')
        ax.set_ylabel('Humidity (%)')
        ax.set_title('Humidity over Time')
        fig.savefig(self.export_directory + 'humidity.jpg')
        plt.close(fig)

        # Plot and save pressure over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.pressure)
        ax.set_xlabel('Time')
        ax.set_ylabel('Pressure (Pa)')
        ax.set_title('Pressure over Time')
        fig.savefig(self.export_directory + 'pressure.jpg')
        plt.close(fig)

        # Plot and save UV control over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.UV_control)
        ax.set_xlabel('Time')
        ax.set_ylabel('UV Control')
        ax.set_title('UV Control over Time')
        fig.savefig(self.export_directory + 'UV_control.jpg')
        plt.close(fig)

        # Plot and save UV exp over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.UV_exp)
        ax.set_xlabel('Time')
        ax.set_ylabel('UV Exp')
        ax.set_title('UV Exp over Time')
        fig.savefig(self.export_directory + 'UV_exp.jpg')
        plt.close(fig)

        # Plot and save batt_control over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.batt_control)
        ax.set_xlabel('Time')
        ax.set_ylabel('Batt Control')
        ax.set_title('Batt Control over Time')
        fig.savefig(self.export_directory + 'batt_control.jpg')
        plt.close(fig)

        # Plot and save batt_exp over time
        fig, ax = plt.subplots()
        ax.plot(self.time, self.batt_exp)
        ax.set_xlabel('Time')
        ax.set_ylabel('Batt Exp')
        ax.set_title('Batt Exp over Time')
        fig.savefig(self.export_directory + 'batt_exp.jpg')
        plt.close(fig)
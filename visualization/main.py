# lists which will contain data
time = []
temp = []
humidity = []
pressure = []
UV_control = []
UV_exp = []
batt_control = []
batt_exp = []

with open("DATALOG.TXT") as f:
    data = f.readlines()[1::] # excludes first line, which contains headers

    clean_data = []
    # delete invalid lines and line skip symbols
    for line in data:
        if not "nan" in line:
            clean_data.append(line.replace("\n", ""))

    # adds data to each category
    for line in clean_data:
        time.append(float(line.split(";")[0].replace(" ", "")))
        temp.append(float(line.split(";")[1].replace(" ", "")))
        humidity.append(float(line.split(";")[2].replace(" ", "")))
        pressure.append(float(line.split(";")[3].replace(" ", "")))
        UV_control.append(float(line.split(";")[4].replace(" ", "")))
        UV_exp.append(float(line.split(";")[5].replace(" ", "")))
        batt_control.append(float(line.split(";")[6].replace(" ", "")))
        batt_exp.append(float(line.split(";")[7].replace(" ", "")))


# time conversion in minutes
for i in range(len(time)):
    time[i] = time[i]/60000

print(time)
print(temp)
print(humidity)
print(pressure)
print(UV_control)
print(UV_exp)
print(batt_control)
print(batt_exp)
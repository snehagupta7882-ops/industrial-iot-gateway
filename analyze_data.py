import pandas as pd
import matplotlib.pyplot as plt

# Read CSV
data = pd.read_csv("energy_data.csv")

print(data.head())

# Temperature Graph
plt.figure(figsize=(8,5))
plt.plot(data["Time"], data["Temperature"], marker="o")
plt.title("Temperature Monitoring")
plt.xlabel("Time")
plt.ylabel("Temperature (°C)")
plt.grid(True)
plt.show()

# Load Graph
plt.figure(figsize=(8,5))
plt.plot(data["Time"], data["Load"], marker="o")
plt.title("Machine Load Monitoring")
plt.xlabel("Time")
plt.ylabel("Load")
plt.grid(True)
plt.show()



from sklearn.ensemble import IsolationForest

# AI Model(detect readings when output is 1 :- normal data/readings  and  output is -1:- it means abnormal data/readings through AI)
X = data[["Temperature", "Load"]]

model = IsolationForest(
    contamination=0.15,
    random_state=42
)

data["Anomaly"] = model.fit_predict(X)
print(data)

# anomaly detection graph
plt.figure(figsize=(10,5))

normal = data[data["Anomaly"] == 1]
anomaly = data[data["Anomaly"] == -1]

plt.plot(normal["Time"], normal["Load"], marker="o", label="Normal")
plt.scatter(anomaly["Time"], anomaly["Load"], s=100, label="Anomaly")

plt.title("AI Anomaly Detection")
plt.xlabel("Time")
plt.ylabel("Load")
plt.legend()
plt.grid(True)

plt.show()
# for calculate health of machine based on temperature, load and anomaly detection
def calculate_health(temp, load, anomaly):

    health = 100

    # Temperature effect
    if temp > 40:
        health -= 20
    elif temp > 35:
        health -= 10

    # Load effect
    if load > 2800:
        health -= 30
    elif load > 1200:
        health -= 15

    # AI anomaly effect
    if anomaly == -1:
        health -= 20

    return max(0, health)

# calculate heath score 
data["Health"] = data.apply(
    lambda row: calculate_health(
        row["Temperature"],
        row["Load"],
        row["Anomaly"]
    ),
    axis=1
)
print(data)

# for graph of health score
plt.figure(figsize=(10,5))

plt.plot(
    data["Time"],
    data["Health"],
    marker="o"
)

plt.title("Machine Health Score")
plt.xlabel("Time")
plt.ylabel("Health (%)")
plt.grid(True)

plt.show()
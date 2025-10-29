import matplotlib.pyplot as plt

# Data
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000]
time_values = [0.000000, 0.000000, 0.000001, 0.000002, 0.000005,
               0.000013, 0.000019, 0.000023, 0.000026, 0.000028]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.title('Linear Search: Array Size vs Time Taken')
plt.xlabel('Array Size (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.000001, f"{time_values[i]:.6f}",
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()

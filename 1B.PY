import matplotlib.pyplot as plt

# Example Data (replace with your measured values from C program)
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 7000, 10000, 20000]
time_values = [0.000007, 0.000008, 0.000011, 0.000013, 0.000006,
               0.000009, 0.000007, 0.000008, 0.000011, 0.000007]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='red')

# Titles and labels
plt.title('Binary Search: Array Size vs Time Taken')
plt.xlabel('Array Size (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

# Show data point values on the graph
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.0000005, f"{time_values[i]:.6f}",
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()

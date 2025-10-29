import matplotlib.pyplot as plt

# Data from the test cases
sizes = [100, 1000, 10000, 100000, 200000]
times = [0.000000, 0.001000, 0.050000, 1.424000, 22.503000]

# Plot the data
plt.plot(sizes, times, marker='o', linestyle='-', color='brown')

# Labels and title
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.title('Selection Sort Time vs Input Size')

# Use logarithmic scales for better visualization
plt.xscale('log')
plt.yscale('log')

# Add grid
plt.grid(True)

# Display the plot
plt.show()

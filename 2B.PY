import matplotlib.pyplot as plt

# Data from the test cases
sizes = [100, 1000, 10000, 100000, 1000000]
times = [0.00002, 0.00006, 0.002000, 0.008000, 0.018000]

# Plot the data
plt.plot(sizes, times, marker='o', linestyle='-', color='purple')

# Labels and title
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.title('Quick Sort Time vs Input Size')

# Use logarithmic scales for better visualization
plt.xscale('log')
plt.yscale('log')

# Add grid
plt.grid(True)

# Display the plot
plt.show()

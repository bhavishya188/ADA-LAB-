import matplotlib.pyplot as plt

# Data from the test cases
sizes = [10, 100, 1000, 10000, 100000]
times = [0.00008, 0.0006, 0.00300, 0.016000, 24.103000]

# Plot the data
plt.plot(sizes, times, marker='o', linestyle='-', color='teal')

# Labels and title
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.title('Bubble Sort Time vs Input Size')

# Use logarithmic scales for better visualization
plt.xscale('log')
plt.yscale('log')

# Add grid
plt.grid(True)

# Display the plot
plt.show()

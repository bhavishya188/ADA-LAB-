import matplotlib.pyplot as plt

# Data from the test cases
sizes = [100, 1000, 10000, 100000, 1000000]
times = [0.000000, 0.000008, 0.000060, 0.000320, 0.254000]

# Plot the data
plt.plot(sizes, times, marker='o', linestyle='-', color='red')

# Labels and title
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.title('Merge Sort Time vs Input Size')

# Use logarithmic scales for better visualization
plt.xscale('log')
plt.yscale('log')

# Add grid
plt.grid(True)

# Display the plot
plt.show()

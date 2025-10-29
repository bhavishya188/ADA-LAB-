import matplotlib.pyplot as plt

# Data from the test cases
sizes = [100, 1000, 10000, 100000, 1000000]
times = [0.00008, 0.00100, 0.02600, 3.883000, 415.277000]

# Plot the data
plt.plot(sizes, times, marker='o', linestyle='-', color='orange')

# Labels and title
plt.xlabel('Input Size')
plt.ylabel('Time Taken (seconds)')
plt.title('Insertion Sort Time vs Input Size')

# Use logarithmic scales for better visualization
plt.xscale('log')
plt.yscale('log')

# Add grid
plt.grid(True)

# Display the plot
plt.show()

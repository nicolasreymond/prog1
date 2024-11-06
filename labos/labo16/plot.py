import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Read data from CSV file
data = pd.read_csv('results.csv')

# Filter data for each method
gpt_data = data[data['Method'] == 'GPT']
nre_data = data[data['Method'] == 'NRE']

# Extract x and y values for each method
x_gpt = gpt_data['k']
y_gpt = gpt_data['Time']
x_nre = nre_data['k']
y_nre = nre_data['Time']

# Create a figure with one plot
fig, ax3 = plt.subplots(figsize=(15, 6))

# Scatter plot for GPT and NRE
ax3.scatter(x_gpt, y_gpt, marker='o', label='GPT', color='blue')
ax3.scatter(x_nre, y_nre, marker='x', label='NRE', color='red')

# Fit linear regression models
gpt_coefficients = np.polyfit(x_gpt, y_gpt, 1)  # Linear fit (degree=1)
nre_coefficients = np.polyfit(x_nre, y_nre, 1)  # Linear fit (degree=1)

# Create extrapolation range
x_extrapolated = np.linspace(min(min(x_gpt), min(x_nre)), max(max(x_gpt), max(x_nre)) + 5, 100)

# Calculate the extrapolated y values for GPT and NRE
y_gpt_extrapolated = np.polyval(gpt_coefficients, x_extrapolated)
y_nre_extrapolated = np.polyval(nre_coefficients, x_extrapolated)

# Plot the extrapolated lines
ax3.plot(x_extrapolated, y_gpt_extrapolated, linestyle='--', color='blue', label='GPT Extrapolated')
ax3.plot(x_extrapolated, y_nre_extrapolated, linestyle='--', color='red', label='NRE Extrapolated')

# Set title and labels
ax3.set_title('Scatter Plot of GPT and NRE Data with Extrapolated Lines')
ax3.set_xlabel('k')
ax3.set_ylabel('Time (s)')
ax3.set_yscale('log')
ax3.legend()
ax3.set_xticks(range(int(min(min(x_gpt), min(x_nre))), int(max(max(x_gpt), max(x_nre)) + 6)))
ax3.grid(True)

# Adjust layout and show plot
plt.tight_layout()
plt.show()

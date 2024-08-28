import re

# Function to add numbers around the "+" sign
def add_numbers(expression):
    # Find all patterns with two numbers around the "+"
    pattern = re.compile(r"(\d+)\+(\d+)")
    while True:
        match = pattern.search(expression)
        if not match:
            break
        # Extract the two numbers
        num1 = int(match.group(1))
        num2 = int(match.group(2))
        # Calculate their sum
        sum_value = num1 + num2
        # Replace the original pattern with the sum
        expression = expression[:match.start()] + str(sum_value) + expression[match.end():]
    return expression

# Read the file content as a string
with open('assets.json', 'r') as file:
    file_content = file.read()

# Update the file content
updated_content = add_numbers(file_content)

# Write the updated content back to a new JSON file
with open('assets_updated.json', 'w') as file:
    file.write(updated_content)

print("JSON data has been updated and saved to 'assets_updated.json'.")
